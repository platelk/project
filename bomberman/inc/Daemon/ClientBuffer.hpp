//
// ClientBuffer.hpp for ClientBuffer in /home/guiho_r/depot/bomberman/inc/Daemon
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Tue May 14 10:21:02 2013 ronan guiho
// Last update Thu May 16 14:35:50 2013 vink
//

#ifndef __CLIENT_BUFFER_HPP__
#define __CLIENT_BUFFER_HPP__

#include <time.h>
#include <queue>

namespace Daemon
{
  template<typename T>
  class ClientBuffer
  {
  private:
    unsigned int _maxstack;
    time_t _time;
    int _timeout;
    std::queue<T> _queue;
  public:
    ClientBuffer(const unsigned int maxstack, const int timeout)
      : _maxstack(maxstack), _timeout(timeout)
    {
      time(&this->_time);
    }
    void push(T elem)
    {
      time(&this->_time);
      this->_queue.push(elem);
    }
    T pop()
    {
      T elem;

      elem = this->_queue.front();
      this->_queue.pop();
      return (elem);
    }
    const time_t &getTime() const
    {
      return (this->_time);
    }
    void setTimeout(const int timeout)
    {
      this->_timeout = timeout;
    }
    bool isEmpty() const
    {
      return (this->_queue.empty());
    }
    bool isTimeout() const
    {
      time_t time_end;

      time(&time_end);
      return ((difftime(time_end, this->_time) >= this->_timeout ||
	       this->_queue.size() >= this->_maxstack) ? true : false);
    }
  };
}

#endif
