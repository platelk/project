//
// Cond.cpp for /home/vink/projet/cpp/thread-lib/Thread/src/Cond.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Tue Apr 16 10:48:43 2013 vink
// Last update Mon May 20 18:42:17 2013 ronan guiho
//

#include "Cond.hh"

Cond::Cond()
{
  pthread_cond_init(&(this->_cond), 0);
  pthread_mutex_init(&(this->_mutex), 0);
  time(&(this->_start));
  this->_is_lock = false;
}

Cond::~Cond()
{
  this->signalBroadcast();
  //  pthread_cond_destroy(&(this->_cond));
}

int	Cond::wait()
{
  time(&(this->_start));
  this->_is_lock = true;
  return pthread_cond_wait(&(this->_cond), &(this->_mutex));
}

int	Cond::signal()
{
  int	ret;

  ret = pthread_cond_signal(&(this->_cond));
  this->_is_lock = false;
  return ret;
}

int	Cond::signalBroadcast()
{
  int	ret;

  ret = pthread_cond_broadcast(&(this->_cond));
  this->_is_lock = false;
  return ret;
}

double	Cond::timeWaitting() const
{
  time_t	t;

  time(&t);
  return difftime(t, this->_start);
}

bool	Cond::isWaitting() const
{
  return this->_is_lock;
}
