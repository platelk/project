//
// Mutex.cpp for /home/vink/projet/cpp/thread-lib/Thread/src/Mutex.cpp in /home/vink/projet/cpp/thread-lib/Thread
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Apr 16 01:48:26 2013 kevin platel
// Last update Fri Jun  7 23:22:25 2013 kevin platel
//

#include <pthread.h>
#include "Mutex.hh"

Mutex::Mutex()
{
  pthread_mutexattr_t attr;

  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&(this->_mutex), &attr);
  this->_is_lock = false;
}

Mutex::~Mutex()
{
  if (this->isLock())
  pthread_mutex_unlock(&(this->_mutex));
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
