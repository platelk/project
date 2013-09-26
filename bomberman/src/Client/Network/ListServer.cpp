//
// ListServer.cpp for ListServer in /home/guiho_r/depot/bomberman/inc/Client/Network
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Mon Jun  3 18:15:29 2013 ronan guiho
//

#include <cstdlib>
#include <unistd.h>
#include "LockScope.hh"
#include "Client/Network/Sender.hh"
#include "Client/Network/Listener.hh"
#include "Client/Network/ListServer.hh"

const std::string ListServer::HOST = "225.0.0.37";
const short ListServer::PORT = 5252;

ListServer::ListServer(const int refresh)
  : _refresh(refresh), _is_broadcast(false), _current(0),
    _thread_send(&ListServer::sender), _thread_recv(&ListServer::receiver)
{
  _thread_recv.run(this);
}

void ListServer::broadcast(const ServerBroadcast &server)
{
  LockScope(this->_mutex);

  this->_current = new ServerBroadcast(server.getTitle(), server.getHost(), server.getPort());
  this->_thread_send.run(this);
}

int ListServer::getRefresh()
{
  LockScope(this->_mutex);

  return (this->_refresh);
}

Mutex *ListServer::getMutex()
{
  return (&this->_mutex);
}

ServerBroadcast *ListServer::getCurrentServer()
{
  LockScope(this->_mutex);
  return (this->_current);
}

bool ListServer::isBroadcast()
{
  LockScope(this->_mutex);
  return (this->_is_broadcast);
}

std::list<ServerBroadcast> ListServer::getListServer()
{
  LockScope(this->_mutex);
  return (this->_list);
}

void *ListServer::sender(ListServer *server)
{
  Sender sender(ListServer::HOST, ListServer::PORT);

  sender.init();
  while (true)
    {
      sleep(server->getRefresh());
      sender.send(server->getCurrentServer()->serialize());
    }
  return (0);
}

bool ListServer::isExist(const ServerBroadcast &server)
{
  LockScope(this->_mutex);

  for (std::list<ServerBroadcast>::iterator it = this->_list.begin();
       it != this->_list.end(); ++it)
    {
      if ((*it).getHost() == server.getHost() &&
	  (*it).getPort() == server.getPort())
	return (true);
    }
  return (false);
}

void ListServer::pushServer(const ServerBroadcast &server)
{
  LockScope(this->_mutex);

  this->_list.push_back(ServerBroadcast(server.getTitle(), server.getHost(), server.getPort()));
}

void *ListServer::receiver(ListServer *server)
{
  ServerBroadcast srv("", "", 0);
  Listener listener(ListServer::HOST, ListServer::PORT);

  listener.init();
  while (true)
    {
      srv.unserialize(listener.recv());
      if (((server->getCurrentServer() != 0) &&
	   ((server->getCurrentServer()->getHost() == srv.getHost() &&	\
	     server->getCurrentServer()->getPort() != srv.getPort()) ||
	    (server->getCurrentServer()->getHost() != srv.getHost() &&	\
	     server->getCurrentServer()->getPort() == srv.getPort()))) ||
	  server->getCurrentServer() == 0)
	{
	  if (server->isExist(srv) == false)
	      server->pushServer(srv);
	}
    }
  return (0);
}
