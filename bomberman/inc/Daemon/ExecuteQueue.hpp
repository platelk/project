//
// ExecuteQueue.hh for ExecuteQueue in /home/guiho_r/depot/bomberman/inc/Daemon
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Mon May 13 17:16:10 2013 ronan guiho
// Last update Sat Jun  8 23:11:47 2013 ronan guiho
//

#ifndef __EXECUTE_QUEUE_HPP__
#define __EXECUTE_QUEUE_HPP__

#include <queue>
#include <string>
#include <iostream>

#include "Thread/Mutex.hh"
#include "Thread/LockScope.hh"

namespace Daemon
{
  template<typename T>
  class ExecuteQueue
  {
  private:
    Mutex _mutex;
    std::queue<T> _list;
  public:
    ~ExecuteQueue()
    {
    }
    void push(T elem)
    {
      LockScope lock(this->_mutex);
      this->_list.push(elem);
    }
    bool isEmpty()
    {
      LockScope lock(this->_mutex);

      return (this->_list.empty());
    }
    void clear()
    {
      while (!this->isEmpty())
	this->pop();
    }
    T pop()
    {
      T elem;
      LockScope lock(this->_mutex);

      elem = this->_list.front();
      this->_list.pop();
      return (elem);
    }
  };
}

#endif
