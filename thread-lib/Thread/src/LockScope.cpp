//
// LockScope.cpp for /home/vink/projet/cpp/thread-lib/Thread/src/LockScope.cpp in /home/vink/projet/cpp/thread-lib/Thread
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Apr 16 02:00:15 2013 kevin platel
//

#include "LockScope.hh"

LockScope::LockScope(Mutex &mutex)
  : _mutex(mutex)
{
  this->_mutex.lock();
}

LockScope::~LockScope()
{
  this->_mutex.unLock();
}
