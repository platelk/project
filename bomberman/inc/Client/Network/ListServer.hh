//
// ListServer.hh for ListServer in /home/guiho_r/depot/bomberman/inc/Client/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Mon Jun  3 17:21:01 2013 ronan guiho
// Last update Mon Jun  3 20:33:25 2013 ronan guiho
//

#ifndef __LIST_SERVER_HH__
#define __LIST_SERVER_HH__

#include <list>
#include <string>

#include "Thread.hpp"
#include "LockScope.hh"
#include "ServerBroadcast.hh"

class ListServer
{
private:
  int _refresh;
  Mutex _mutex;
  bool _is_broadcast;
  ServerBroadcast *_current;
  std::list<ServerBroadcast> _list;
  Thread<ListServer *, void *> _thread_send;
  Thread<ListServer *, void *> _thread_recv;
public:
  static const std::string HOST;
  static const short PORT;
  ListServer(const int refresh);
  ServerBroadcast *getCurrentServer();
  int getRefresh();
  void broadcast(const ServerBroadcast &server);
  bool isBroadcast();
  std::list<ServerBroadcast> getListServer();
  Mutex *getMutex();
  static void *sender(ListServer *server);
  static void *receiver(ListServer *server);
  bool isExist(const ServerBroadcast &server);
  void pushServer(const ServerBroadcast &server);
};

#endif
