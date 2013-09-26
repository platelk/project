//
// SendQueue.hpp for SendQueue in /home/guiho_r/depot/bomberman/inc/Daemon
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Mon May 20 13:21:31 2013 ronan guiho
// Last update Sun Jun  9 01:59:13 2013 ronan guiho
//

#ifndef __SEND_QUEUE_HPP__
#define __SEND_QUEUE_HPP__

#include <queue>
#include <string>
#include <unistd.h>
#include <iostream>

#include "LockScope.hh"
#include "Thread.hpp"

namespace Daemon
{
  class DaemonServer;
  template<typename T>
  class SendQueue
  {
  private:
    class Message
    {
    private:
      std::string _id;
      T _data;
    public:
      Message(const std::string &id, const T &data)
      {
	_id = id;
	_data = data;
      }
      Message(const Message &msg)
	: _id(msg.getID()), _data(msg.getData())
      {
      }
      void setID(const std::string &id)
      {
	this->_id = id;
      }
      const std::string &getID() const
      {
	return (this->_id);
      }
      const T &getData() const
      {
	return (this->_data);
      }
      void setData(const T &data)
      {
	this->_data = data;
      }
    };
    int _freq;
    Mutex _mutex;
    DaemonServer *_daemon;
    std::queue<Message> _list;
    Thread<SendQueue *, void *> _thread;
  public:
    SendQueue(const int freq)
      : _freq(freq), _thread(&execute)
    {
      _thread.run(this);
    }
    void push(const std::string &id, const T &data)
    {
      Message msg(id, data);
      LockScope lock(this->_mutex);

      this->_list.push(msg);
    }
    int getRefreshFrequency() const
    {
      return (this->_freq);
    }
    void setRefreshFrequency(const int freq)
    {
      LockScope lock(this->_mutex);
      this->_freq = freq;
    }
    bool isEmpty() const
    {
      return (this->_list.empty());
    }
    void pop()
    {
      LockScope lock(this->_mutex);

      Message msg(this->_list.front());
      this->_list.pop();
      this->_daemon->sendTo(msg.getID(), msg.getData());
    }
    void setNetwork(DaemonServer *daemon)
    {
      LockScope lock(this->_mutex);
      this->_daemon = daemon;
    }
  private:
    static void *execute(SendQueue *qsend)
    {
      while (true)
	{
	  usleep(qsend->getRefreshFrequency());
	  while (!qsend->isEmpty())
	    qsend->pop();
	}
      return (0);
    }
  };
}

#endif
