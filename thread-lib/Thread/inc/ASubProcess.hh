#ifndef __ASUBPROCESS_H__
# define __ASUBPROCESS_H__

#include <iostream>

#include "ASubProcessError.hh"

// Unix include

#include <stdio.h>
#include <time.h>

class ASubProcess
{
public:
typedef enum
  {
    BLOCK,
    NONE_BLOCK
  } State;

typedef void *	(*thread_func)(void *);

protected:
  double	_time;
  bool		_stopped;
  thread_func	_func;
  void		*_param;
  State		_state;
  time_t	_start;
  time_t	_end;


public:
  ASubProcess(thread_func func = 0, void *param = 0, ASubProcess::State stat = NONE_BLOCK);
  virtual ~ASubProcess();

  bool			isStop() const;
  double		getTime() const;

  virtual void	stop() = 0;
  virtual int	join() = 0;
  virtual int	run(thread_func func = 0, void *param = 0, ASubProcess::State stat = NONE_BLOCK) = 0;
};

#endif /* !__ASUBPROCESS_H__ */
