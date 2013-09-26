#ifndef __THREAD_H__
# define __THREAD_H__

#include <iostream>
#include "ASubProcess.hpp"
#include "ThreadError.hh"

#include <pthread.h>
#include <time.h>

template<typename P, typename R> void	*thread_launcher(void *param);


template<typename P = int, typename R = int>
class Thread : public ASubProcess<P, R>
{
private:
  pthread_t	_id;
  R		_ret;
public:
  Thread(typename ASubProcess<P, R>::thread_func func = 0,
	 P param = 0,
	 typename ASubProcess<P, R>::State stat = ASubProcess<P, R>::NONE_BLOCK)
    : ASubProcess<P, R>(func, param, stat), _id(0)
  {
  }

  virtual ~Thread()
  {
    pthread_cancel(this->_id);
  }

  void	stop()
  {
    if (this->_id)
      pthread_cancel(this->_id);
    // else
    //   throw ThreadStopError("Stop on a not running thread.\n");
  }

  int	join()
  {
    if (this->_id)
      return pthread_join(this->_id, NULL);
    else
      throw ThreadJoinError("Join on a not running thread.\n");
  }

  R	join(R *ret)
  {
    this->join();
    if (ret)
      *ret = this->_ret;
    return this->_ret;
  }

  int	run()
  {
    if (this->_func)
      pthread_create(&(this->_id), 0, &thread_launcher<P, R>, this);
    else
      throw ThreadRunError("Invalid run function.\n");

    if (this->_state == ASubProcess<P, R>::BLOCK)
      this->join();
    return 0;
  }

  int	run(P param,
	    typename ASubProcess<P, R>::thread_func func = 0,
	    typename ASubProcess<P, R>::State stat = ASubProcess<P, R>::NONE_BLOCK)
  {
    if (func)
      this->_func = func;
    this->_param = param;
    if (stat != this->_state)
      this->_state = stat;
    return this->run();
  }

  R	getReturn() const
  {
    return this->_ret;
  }

  void	*operator()(void *)
  {
    time(&(this->_start));
    this->_stopped = false;

    this->_ret = this->_func(this->_param);

    this->_stopped = true;
    time(&(this->_end));
    this->_time = difftime(this->_end, this->_start);
    return 0;
  }
};

template<typename P, typename R>
static void	*thread_launcher(void *param)
{
  Thread<P, R> *t = reinterpret_cast< Thread<P, R> *>(param);

  // pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);
  // pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, 0);
  return (*t)(0);
}

#endif /* !__THREAD_H__ */
