#ifndef __ASUBPROCESS_H__
# define __ASUBPROCESS_H__

#include <iostream>

#include "ASubProcessError.hh"

// Unix include

#include <stdio.h>
#include <time.h>

template<typename P = int, typename R = int>
class ASubProcess
{
public:
typedef enum
  {
    BLOCK,
    NONE_BLOCK
  } State;

typedef R	(*thread_func)(P);

protected:
   double	_time;
  bool		_stopped;
  thread_func	_func;
  P		_param;
  State		_state;
  time_t	_start;
  time_t	_end;

public:
  ASubProcess(thread_func func = 0, P param = 0, ASubProcess::State stat = NONE_BLOCK)
  : _time(-1.0), _stopped(true), _func(func), _param(param), _state(stat)
  {
  }
  virtual ~ASubProcess()
  {
  }

  bool			isStop() const
  {
    return this->_stopped;
  }

  double		getTime() const
  {
    time_t t;

    if (this->_time >= 0.0)
      return this->_time;
    time(&t);
    if (this->_stopped == false)
      return (difftime(t, this->_start));
    return this->_time;
  }

  virtual void	stop() = 0;
  virtual int	join() = 0;
  virtual int	run() = 0;
  virtual int	run(P param, thread_func func = 0, ASubProcess::State stat = NONE_BLOCK) = 0;
};

#endif /* !__ASUBPROCESS_H__ */
