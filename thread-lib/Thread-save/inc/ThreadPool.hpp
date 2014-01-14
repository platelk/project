#ifndef __THREADPOOL_H__
# define __THREADPOOL_H__

#include <iostream>
#include <deque>
#include <queue>
#include <utility>

#include "Thread.hpp"
#include "Cond.hh"
#include "Mutex.hh"

template <typename P = int, typename R = int>
class ThreadPool
{
public:
  typedef R	(*thread_func)(P);

public:

  class ThreadElem
  {
  private:

    thread_func				*_f;
    Cond &				_main_cond;
    bool				_have_value;
    Thread<ThreadElem*, int>		_thread;
    Cond			_cond;
    R				_value;
    P				_param;

  public:
    ThreadElem(thread_func *f, Cond & cond)
      : _f(f), _main_cond(cond), _have_value(false)
    {
      this->_thread.run();
    }

    virtual ~ThreadElem()
    {
    }

    void	setValue(R value)
    {
      this->_value = value;
    }
    R		getValue() const
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

    bool	launch(P param, thread_func *f = 0)
    {
      if (f)
	this->_f = f;
      this->_param = param;
      if ((this->_thread).isStop() == false)
	return false;
      (this->_cond).signal();
      return true;
    }

    bool	haveValue() const
    {
      return (this->_have_value);
    }

    bool	isRunning() const
    {
      return (!(this->_thread).isStop());
    }

    int		operator()(int)
    {
      while (true)
	{
	  this->_cond.wait();
	  this->_value = (*(this->_f))(this->_param);
	  this->_have_value = true;
	  this->_main_cond->signal();
	}
      return (0);
    }
  };

private:

  int						_thread_limit;

  thread_func					_default_func;

  std::deque< ThreadElem* >			_thread_pool;
  std::queue< R >				_value;
  std::queue< std::pair<thread_func *, P> * >	_to_do;
  Cond						_cond;

public:
  ThreadPool(int size = -1, thread_func func = 0)
    : _thread_limit(size), _default_func(func)
  {
  }

  virtual ~ThreadPool()
  {
    for (size_t i = 0; i < this->_thread_pool.size(); ++i)
      delete this->_thread_pool[i];
  }

  void	waitUpdate()
  {
    this->_cond.wait();
  }

  void	update()
  {
    for (size_t i = 0; i < (this->_thread_pool).size(); ++i)
      {
	if (this->_thread_pool[i].haveValue())
	  this->_value.push(this->_thread_pool[i].getValue());
      }
    for (size_t i = 0; i < (this->_thread_pool).size(); ++i)
      {
	if (!this->_to_do.empty() && this->_thread_pool[i].isRunning == false)
	  {
	    std::pair<thread_func *, P> n = this->_to_do.front();
	    this->_to_do.pop();
	    this->_thread_pool[i].launch(n.second, n.first);
	  }
      }
    while (!this->_to_do.emtpy())
      {
	if (this->_thread_pool >= 0
	    && this->_thread_pool.size() >= this->_thread_limit)
	  break;
	std::pair<thread_func *, P> n = this->_to_do.front();
	ThreadElem *elem = new ThreadElem(n.first, this->_cond);
	this->_to_do.pop();
	elem->launch(n.second, n.first);
	this->_thread_pool.push_back(elem);
      }
  }

  bool	haveFreeThread()
  {
    for (size_t i = 0; i < (this->_thread_pool).size(); ++i)
      {
	if (this->_thread_pool[i].isRunning() == false)
	  return true;
      }
    return false;
  }

  bool	haveRessource() const
  {
    return (!this->_value.empty());
  }

  R	getRessource() const
  {
    R	ret;

    this->update();
    ret = this->_value.front();
    this->_value.pop();
    return ret;
  }

  void	sendRessource(P param, thread_func f = 0)
  {
    thread_func *func = new thread_func;
    if (f)
      *func = f;
    else
      *func = this->_default_func;
    this->_to_do.push(new std::pair<thread_func *, P>(func, param));
  }
};

template<typename P, typename R>
static int	threadPool_func(typename ThreadPool<P, R>::ThreadElem *elem)
{
  (*elem)();
  return (0);
}

#endif /* !__THREADPOOL_H__ */
