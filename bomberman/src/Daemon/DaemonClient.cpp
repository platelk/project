//
// DaemonClient.cpp
//
// Made by Guiho Ronan
//
// Started on  Sun May 12 17:59:07 2013 Guiho Ronan
//

#include <string>
#include <sstream>

#include "Aggregator.hh"
#include "DaemonClient.hh"
#include "DaemonServer.hh"
#include "Network/Client.hh"
#include "Logging/Logger.hpp"
#include "Logging/ChannelConsole.hh"

const int Daemon::DaemonClient::MAX_MSG = 3;
const double Daemon::DaemonClient::TIMEOUT_MSG = 0.05;
const double Daemon::DaemonClient::TIMEOUT_SELECT = 200000;
const double Daemon::DaemonClient::TIMEOUT_AUTH = 2000000;

Daemon::DaemonClient::DaemonClient(const std::string &id, Network::Client *client)
  : _id(id), _client(client), _thread(&Daemon::DaemonClient::run),
    _buffer(this->MAX_MSG, this->TIMEOUT_MSG)
{
  _exec = Daemon::DaemonServer::execq;
  _agr = new Aggregator("\r\n");
  _thread.run(this);
}

void Daemon::DaemonClient::stop()
{
  this->_client->disconnect(Network::TCP | Network::UDP);
}

const std::string &Daemon::DaemonClient::getID() const
{
  return (this->_id);
}

Network::Client *Daemon::DaemonClient::getClient()
{
  return (this->_client);
}

Thread<Daemon::DaemonClient *, void *> *Daemon::DaemonClient::getThread()
{
  return (&this->_thread);
}

void Daemon::DaemonClient::pushToBuffer(const std::string &msg)
{
  std::string tmp;

  this->_agr->push(msg);
  while (this->_agr->checksum(tmp))
    {
      this->_buffer.push(tmp);
      tmp.clear();
    }
}

bool Daemon::DaemonClient::isTimeoutBuffer()
{
  return (this->_buffer.isTimeout());
}

void Daemon::DaemonClient::executeBuffer()
{
  while (!this->_buffer.isEmpty())
    this->_exec->push(this->_buffer.pop());
}

void *Daemon::DaemonClient::run(Daemon::DaemonClient *client)
{
  int socket;
  fd_set readfs;
  std::string msg;
  struct timeval time;
  double timeout;
  Network::Client *network;

  network = client->getClient();
  socket = network->getSocket(Network::TCP);
  timeout = client->TIMEOUT_SELECT;
  if (client->waitAuthentification() == false)
    {
      client->stop();
      return (0);
    }
  client->setState(Daemon::DaemonClient::WAIT);
  while (true)
    {
      FD_ZERO(&readfs);
      FD_SET(socket, &readfs);
      time.tv_sec = 0;
      time.tv_usec = timeout;
      if (select(socket + 1, &readfs, 0, 0, &time) > 0)
	{
	  if ((msg = network->receive(Network::TCP)) == "")
	    {
	      client->stop();
	      return (0);
	    }
	  client->pushToBuffer(msg);
	}
      if (client->isTimeoutBuffer())
	client->executeBuffer();
    }
  return (0);
}

const Daemon::DaemonClient::StateClient &Daemon::DaemonClient::getState() const
{
  return (this->_state);
}

void Daemon::DaemonClient::setState(const Daemon::DaemonClient::StateClient state)
{
  this->_state = state;
}


bool Daemon::DaemonClient::waitAuthentification()
{
  bool auth;
  int socket;
  fd_set readfs;
  std::string msg;
  std::string tmp;
  struct timeval time;

  auth = false;
  FD_ZERO(&readfs);
  socket = this->_client->getSocket(Network::TCP);
  FD_SET(socket, &readfs);
  time.tv_sec = 0;
  time.tv_usec = Daemon::DaemonClient::TIMEOUT_AUTH;
  if (select(socket + 1, &readfs, 0, 0, &time) > 0)
    {
      if ((msg = this->_client->receive(Network::TCP)) == "")
	{
	  this->stop();
	  return (0);
	}
      this->_agr->push(msg);
      if (this->_agr->checksum(tmp))
	auth = (tmp == (Daemon::DaemonServer::KEY + "\r\n")) ? true : false;
      tmp.clear();
      while (this->_agr->checksum(tmp))
	this->_buffer.push(tmp);
      this->executeBuffer();
      return (auth);
    }
  return (false);
}
