//
// Mutex.cpp for /home/vink/projet/cpp/thread-lib/Thread/src/Mutex.cpp in /home/vink/projet/cpp/thread-lib/Thread
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Apr 16 01:48:26 2013 kevin platel
// Last update Thu Apr 18 11:34:10 2013 vink
//

#include <pthread.h>
#include "Mutex.hh"

size_t			Mutex::max_id = 0;
std::map<int, Mutex*>	Mutex::mutex_map;

Mutex::Mutex()
{
  this->_id = Mutex::max_id;
  Mutex::max_id++;
  pthread_mutex_init(&(this->_mutex), 0);
  this->_is_lock = false;
  Mutex::mutex_map[this->_id] = this;
}

Mutex::~Mutex()
{
  pthread_mutex_unlock(&(this->_mutex));
  Mutex::mutex_map.erase(this->_id);
}

void	Mutex::lock()
{
  pthread_mutex_lock(&(this->_mutex));
  this->_is_lock = true;
  time(&(this->_start));
}

void	Mutex::unLock()
{
  pthread_mutex_unlock(&(this->_mutex));
}

bool	Mutex::isLock() const
{
  return this->_is_lock;
}

int	Mutex::getId() const
{
  return this->_id;
}

double	Mutex::timeLocked() const
{
  time_t t;

  time(&t);
  return (difftime(t, this->_start));
}

bool	Mutex::tryLock()
{
  if (this->_is_lock)
    return false;
  this->lock();
  return true;
}

int	Mutex::lock(size_t id)
{
  if (Mutex::mutex_map.find(id) == Mutex::mutex_map.end())
    return (-1);
  (Mutex::mutex_map[id])->lock();
  return (0);
}

int	Mutex::unLock(size_t id)
{
  if (Mutex::mutex_map.find(id) == Mutex::mutex_map.end())
    return (-1);
  (Mutex::mutex_map[id])->unLock();
  return (0);
}
