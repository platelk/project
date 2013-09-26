//
// DaemonServer.cpp
//
// Made by Guiho Ronan
//
// Started on  Sun May 12 16:41:58 2013 Guiho Ronan
// Last update Sun Jun  9 12:06:32 2013 ronan guiho
//

#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "Aggregator.hh"
#include "SendQueue.hpp"
#include "DaemonServer.hh"
#include "ListClient.hh"
#include "ExecuteQueue.hpp"
#include "Core/Trame/Trame.hh"
#include "utils.hh"

Daemon::ExecuteQueue<std::string>* Daemon::DaemonServer::execq = new Daemon::ExecuteQueue<std::string>;
Daemon::SendQueue<std::string>* Daemon::DaemonServer::sendq = new Daemon::SendQueue<std::string>(100);

const int Daemon::DaemonServer::MAX_MSG = 3;
const double Daemon::DaemonServer::TIMEOUT_MSG = 0.05;
const double Daemon::DaemonServer::TIMEOUT_SELECT = 200000;

const std::string Daemon::DaemonServer::KEY = "9684dd2a6489bf2be2fbdd799a8028e3";
const std::string Daemon::DaemonServer::SEPARATOR = "\r\n";

Daemon::DaemonServer::DaemonServer(const short port)
  : _network(port), _list(500000), _udp_buffer(this->MAX_MSG, this->TIMEOUT_MSG),
    _thread(&Daemon::DaemonServer::execute)
{
  _thread.run(this);
}

void Daemon::DaemonServer::executeBuffer()
{
  while (!this->_udp_buffer.isEmpty())
    this->execq->push(this->_udp_buffer.pop());
}

bool Daemon::DaemonServer::run()
{
  int socket[3];
  fd_set readfs;
  std::string tmp;
  struct timeval time;
  Aggregator agreg(this->SEPARATOR);

  this->_network.run(Network::TCP | Network::UDP);
  if (this->_network.isRunning())
    {
      socket[0] = this->_network.getSocket(Network::TCP);
      socket[1] = this->_network.getSocket(Network::UDP);
      socket[2] = ((socket[0] > socket[1]) ? socket[0] : socket[1]) + 1;
      while (true)
	{
	  FD_ZERO(&readfs);
	  FD_SET(socket[0], &readfs);
	  FD_SET(socket[1], &readfs);
	  time.tv_sec = 0;
	  time.tv_usec = this->TIMEOUT_SELECT;
	  if (select(socket[2], &readfs, 0, 0, &time) > 0)
	    {
	      if (FD_ISSET(socket[1], &readfs))
		{
		  std::vector<std::string> msg = split_string(this->_network.receive(0, Network::UDP), '@');
		  if (msg.size() >= 2 && this->_list.isClient(msg[0]))
		    {
		      agreg.push(msg[1]);
		      tmp.clear();
		      while (agreg.checksum(tmp))
			{
			  this->_udp_buffer.push(tmp);
			  tmp.clear();
			}
		    }
		}
	      else if (FD_ISSET(socket[0], &readfs))
		{
		  Daemon::DaemonClient *dclient = this->_list.addClient(this->_network.acceptConnection());
		  Daemon::Trame trame(-1, "new_player", "", "", "", dclient->getID());
		  this->_udp_buffer.push(trame.toString());
		}
	    }
	  if (this->_udp_buffer.isTimeout())
	    this->executeBuffer();
	}
    }
  else
    return (false);
  return (true);
}


void Daemon::DaemonServer::disconnectAll()
{
  this->_list.disconnectAll();
}

void Daemon::DaemonServer::stop()
{
  this->_network.stop();
}

bool Daemon::DaemonServer::isRunning()
{
  return (this->_network.isRunning());
}

void Daemon::DaemonServer::sendTo(const std::string &id, const std::string &data)
{
  Daemon::DaemonClient *client;
  Daemon::ListClient::ListDaemonClient list = this->_list.getAllClient();

 if (id == "0")
   {
     this->_list.getMutex()->lock();
     for (Daemon::ListClient::ListDaemonClient::iterator it = list.begin(); it != list.end(); ++it)
       if ((*it).second)
	 {
	   this->_network.send((*it).second->getClient(), data);
	 }
     this->_list.getMutex()->unLock();
   }
 else
   {
     this->_list.getMutex()->lock();
     client = this->_list.getClient(id);
     if (client)
       this->_network.send(client->getClient(), data);
     this->_list.getMutex()->unLock();
   }
}

void *Daemon::DaemonServer::execute(DaemonServer *daemon)
{
  daemon->run();
  return (0);
}
