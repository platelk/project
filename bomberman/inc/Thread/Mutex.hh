#ifndef __MUTEX_H__
# define __MUTEX_H__

#include <iostream>
#include <map>

#include <time.h>
#include <pthread.h>

class Mutex
{
private:
  pthread_mutex_t	_mutex;
  time_t		_start;
  bool			_is_lock;
public:
  Mutex();
  virtual ~Mutex();

  void			lock();
  void			unLock();
  bool			tryLock();

  bool			isLock() const;
  int			  getId() const;
  double		timeLocked() const;

};

#endif /* !__MUTEX_H__ */
