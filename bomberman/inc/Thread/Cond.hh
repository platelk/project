#ifndef __COND_H__
# define __COND_H__

#include <iostream>
#include <map>
#include "Mutex.hh"

#include <pthread.h>

class Cond
{
private:
  pthread_mutex_t	_mutex;
  pthread_cond_t	_cond;

  time_t		_start;
  bool			_is_lock;
public:
  Cond();
  virtual ~Cond();

  int		wait();
  int		signal();
  int		signalBroadcast();

  bool		isWaitting() const;
  double	timeWaitting() const;
};

#endif /* !__COND_H__ */
