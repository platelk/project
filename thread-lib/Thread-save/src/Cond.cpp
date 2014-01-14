//
// Cond.cpp for /home/vink/projet/cpp/thread-lib/Thread/src/Cond.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Tue Apr 16 10:48:43 2013 vink
// Last update Tue Apr 16 12:21:17 2013 vink
//

#include "Cond.hh"

size_t			Cond::max_id = 0;
std::map<int, Cond*>	Cond::cond_map;

Cond::Cond()
{
  this->_id = Cond::max_id;
  Cond::max_id++;

  pthread_cond_init(&(this->_cond), 0);
  pthread_mutex_init(&(this->_mutex), 0);
  time(&(this->_start));
  this->_is_lock = false;

  Cond::cond_map[this->_id] = this;
}

Cond::~Cond()
{
  this->signalBroadcast();
  pthread_cond_destroy(&(this->_cond));
  Cond::cond_map.erase(this->_id);
}

int	Cond::wait()
{
  time(&(this->_start));
  this->_is_lock = true;
  pthread_mutex_lock(&(this->_mutex));
  return pthread_cond_wait(&(this->_cond), &(this->_mutex));
}

int	Cond::signal()
{
  int	ret;

  ret = pthread_cond_signal(&(this->_cond));
  pthread_mutex_unlock(&(this->_mutex));
  this->_is_lock = false;
  return ret;
}

int	Cond::signalBroadcast()
{
  int	ret;

  ret = pthread_cond_broadcast(&(this->_cond));
  pthread_mutex_unlock(&(this->_mutex));
  this->_is_lock = false;
  return ret;
}

int	Cond::getId() const
{
  return this->_id;
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

int	Cond::wait(size_t id)
{
  if (Cond::cond_map.find(id) == Cond::cond_map.end())
    return (-1);
  (Cond::cond_map[id])->wait();
  return (0);
}

int	Cond::signal(size_t id)
{
  if (Cond::cond_map.find(id) == Cond::cond_map.end())
    return (-1);
  (Cond::cond_map[id])->wait();
  return (0);
}

int	Cond::signalBroadcast(size_t id)
{
  if (Cond::cond_map.find(id) == Cond::cond_map.end())
    return (-1);
  (Cond::cond_map[id])->wait();
  return (0);
}
