#ifndef __MUTEX_H__
# define __MUTEX_H__

#include <iostream>
#include <map>

#include <time.h>
#include <pthread.h>

class Mutex
{
private:
  static size_t			max_id;
  static std::map<int, Mutex*>	mutex_map;
private:
  pthread_mutex_t	_mutex;
  time_t		_start;
  bool			_is_lock;
  int			_id;
public:
  Mutex();
  virtual ~Mutex();

  void			lock();
  void			unLock();
  bool			tryLock();

  bool			isLock() const;
  int			getId() const;
  double		timeLocked() const;

  static int	lock(size_t id);
  static int	unLock(size_t id);
};

#endif /* !__MUTEX_H__ */
