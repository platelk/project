#ifndef __THREADPOOL_H__
# define __THREADPOOL_H__

#include <iostream>
#include <deque>
#include <queue>
#include <utility>

#include "Thread.hpp"
#include "Cond.hh"
#include "Mutex.hh"
#include "LockScope.hh"

#include <unistd.h>
#include <time.h>

template<typename P, typename R> int	threadPool_func(void *elem);
template<typename P, typename R> int	threadPool_up(void *elem);


template <typename P = int, typename R = int>
class ThreadPool
{
public:
  typedef R	(*thread_func)(P);

public:

  class ThreadElem
  {
  private:

    thread_func				_f;
    Cond &				_main_cond;
    bool				_have_value;
    bool				_running;
    Thread<void *, int>		_thread;
    Cond			_cond;
    R				_value;
    P				_param;
    bool			_stop;

  public:
    ThreadElem(thread_func f, Cond & cond)
      : _f(f), _main_cond(cond), _have_value(false), _running(true)
    {
      this->_thread.run(this, &threadPool_func<P, R>);
      this->_stop = false;
    }

    virtual ~ThreadElem()
    {
      this->stop();
    }

    void	stop()
    {
      this->_stop = true;
      while (this->_thread.isStop() == false)
	this->_cond.signal();
      this->_thread.stop();
    }

    void	setValue(R value)
    {
      this->_value = value;
    }

    R		getValue()
    {
      this->_have_value = false;
      return (this->_value);
    }

    void	setParam(P param)
    {
      this->_param = param;
    }

    P		getParam() const
    {
      return this->_param;
    }

    bool	launch(P param, thread_func f = 0)
    {
      if (f)
	this->_f = f;
      this->_param = param;
      if (this->_running == true)
	return false;
      while (this->_running == false)
	(this->_cond).signal();
      return true;
    }

    bool	haveValue() const
    {
      return (this->_have_value);
    }

    bool	isRunning() const
    {
      return (this->_running);
    }

    int		operator()(int)
    {
      while (true)
	{
	  this->_running = false;
	  this->_cond.wait();
	  if (this->_stop)
	    break;
	  this->_running = true;
	  this->_value = ((this->_f))(this->_param);
	  this->_have_value = true;
	  this->_main_cond.signalBroadcast();
	}
      return (0);
    }
  };

private:

  size_t					_thread_limit;

  thread_func					_default_func;

  std::deque< ThreadElem* >			_thread_pool;
  std::queue< R >				_value;
  std::queue< std::pair<thread_func, P> * >	_to_do;
  Cond						_cond;
  Mutex	*					_mutex;

  Thread<void*, int>				_up_thread;

public:
  ThreadPool(size_t size_min = 0, size_t size_max = 0, thread_func func = 0)
    : _thread_limit(size_max), _default_func(func)
  {
    this->_mutex = new Mutex();
    while (size_min)
      {
	this->_thread_pool.push_back(new ThreadElem(func, this->_cond));
	size_min--;
      }
    while (this->haveFreeThread() == false);
    this->_up_thread.run(this, &threadPool_up<P, R>);
  }

  virtual ~ThreadPool()
  {
    ThreadElem *a;
    delete this->_mutex;
    this->_up_thread.stop();
    while (this->_thread_pool.empty())
      {
	a = this->_thread_pool.front();
	a->stop();
	delete a;
	this->_thread_pool.pop_front();
      }
  }

  void	waitUpdate()
  {
    this->_cond.wait();
  }

  void	update()
  {
    LockScope a(*this->_mutex);
    for (size_t i = 0; i < (this->_thread_pool).size(); ++i)
      {
    	if ((this->_thread_pool[i])->haveValue())
	  {
	    (this->_value).push((this->_thread_pool[i])->getValue());
	  }
      }
    for (size_t i = 0; i < (this->_thread_pool).size(); ++i)
      {
    	if (!this->_to_do.empty() && this->_thread_pool[i]->isRunning() == false)
    	  {
    	    std::pair<thread_func , P> *n = this->_to_do.front();
    	    this->_to_do.pop();
    	    (this->_thread_pool[i])->launch(n->second, n->first);
    	  }
      }
    while (!this->_to_do.empty())
      {
    	if (this->_thread_limit > 0
    	    && this->_thread_pool.size() >= this->_thread_limit)
    	  break;
    	std::pair<thread_func, P> *n = this->_to_do.front();
    	ThreadElem *elem = new ThreadElem(n->first, this->_cond);
    	this->_to_do.pop();
    	elem->launch(n->second, n->first);
    	this->_thread_pool.push_back(elem);
	delete n;
      }
  }

  bool	haveFreeThread()
  {
    for (size_t i = 0; i < (this->_thread_pool).size(); ++i)
      {
	if (this->_thread_pool[i]->isRunning() == false)
	  return true;
      }
    return false;
  }

  bool	haveRessource() const
  {
    return (!this->_value.empty());
  }

  R	getRessource()
  {
    R	ret;

    LockScope a(*this->_mutex);
    ret = (this->_value).front();
    (this->_value).pop();
    return ret;
  }

  void	sendRessource(P param, thread_func f = 0)
  {
    thread_func func;

    if (f)
      func = f;
    else
      func = this->_default_func;
    this->_to_do.push(new std::pair<thread_func , P>(func, param));
    this->update();
    this->_cond.signalBroadcast();
  }

  int	operator()()
  {
    while (true)
      {
	this->update();
	this->_cond.signalBroadcast();
	usleep(100);
      }
    return 0;
  }
};

template<typename P, typename R>
static int	threadPool_func(void *elem)
{
  typename ThreadPool<P, R>::ThreadElem *ptr = reinterpret_cast< typename ThreadPool<P, R>::ThreadElem * >(elem);
  (*ptr)(0);
  return (0);
}

template<typename P, typename R>
static int	threadPool_up(void *elem)
{
  ThreadPool<P, R> *ptr = reinterpret_cast< ThreadPool<P, R> *>(elem);
  (*ptr)();
  return (0);
}

#endif /* !__THREADPOOL_H__ */
