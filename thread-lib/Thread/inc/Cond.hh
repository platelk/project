#ifndef __COND_H__
# define __COND_H__

#include <iostream>
#include <map>
#include "Mutex.hh"

#include <pthread.h>

class Cond
{
private:
  static size_t			max_id;
  static std::map<int, Cond*>	cond_map;

  pthread_mutex_t	_mutex;
  pthread_cond_t	_cond;

  time_t		_start;
  bool			_is_lock;
  int			_id;
public:
  Cond();
  virtual ~Cond();

  int		wait();
  int		signal();
  int		signalBroadcast();

  bool		isWaitting() const;
  int		getId() const;
  double	timeWaitting() const;

  static int	wait(size_t id);
  static int	signal(size_t id);
  static int	signalBroadcast(size_t id);
};

#endif /* !__COND_H__ */
