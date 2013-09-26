//
// ClientSendQueue.hpp for ClientSendQueue in /home/guiho_r/depot/bomberman/inc/Client/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Tue May 28 16:21:39 2013 ronan guiho
// Last update Sat Jun  8 22:52:28 2013 ronan guiho
//

#ifndef __CLIENT_SEND_QUEUE_HPP__
#define __CLIENT_SEND_QUEUE_HPP__

#include <queue>
#include <string>
#include <unistd.h>
#include <iostream>

#include "LockScope.hh"
#include "Thread.hpp"
#include "Network/NetworkType.hh"
#include "Network/Client.hh"

template<typename T>
class ClientSendQueue
{
private:
  class Message
  {
  private:
    T _data;
    int _type;
  public:
    Message(const T &data, const int type)
      : _data(data), _type(type)
    {
    }
    Message(const Message &msg)
      : _data(msg.getData()), _type(msg.getType())
    {
    }
    void setType(const int type)
    {
      this->_type = type;
    }
    int getType() const
    {
      return (this->_type);
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
  Network::Client *_net;
  std::queue<Message> _list;
  Thread<ClientSendQueue *, void *> _thread;
public:
  ClientSendQueue(const int freq)
    : _freq(freq), _thread(&execute)
  {
    _thread.run(this);
  }
  void push(const T &data, const int type = Network::TCP)
  {
    Message msg(data, type);
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
    this->_net->send(msg.getData(), msg.getType());
  }
  void setNetwork(Network::Client *network)
  {
    LockScope lock(this->_mutex);
    this->_net = network;
  }
private:
  static void *execute(ClientSendQueue *qsend)
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

#endif
