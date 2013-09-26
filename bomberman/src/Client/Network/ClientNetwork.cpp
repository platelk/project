//
// ClientNetwork.cpp for ClientNetwork in /home/guiho_r/depot/bomberman/inc/Client/Network
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Tue May 28 11:06:26 2013 ronan guiho
//

#include <signal.h>

#include "utils.hh"
#include "Thread.hpp"
#include "Client/Network/ClientNetwork.hh"

ClientNetwork::ExecuteQ *ClientNetwork::execq = new ClientNetwork::ExecuteQ;
ClientNetwork::CSendQ *ClientNetwork::sendq = new ClientNetwork::CSendQ(1000);

const int ClientNetwork::MAX_MSG = 3;
const double ClientNetwork::TIMEOUT_MSG = 0.05;
const double ClientNetwork::TIMEOUT_SELECT = 200000;

const std::string ClientNetwork::KEY = "9684dd2a6489bf2be2fbdd799a8028e3";
const std::string ClientNetwork::SEPARATOR = "\r\n";

ClientNetwork::ClientNetwork()
  : _buffer(this->MAX_MSG, this->TIMEOUT_MSG)
{
  _thread = new Thread<ClientNetwork *, void *>(ClientNetwork::run);
  _agr = new Aggregator("\r\n");
  _connect = false;
  signal(SIGPIPE, SIG_IGN);
}

bool ClientNetwork::connect(const std::string &host, const short port)
{
  this->_net = new Network::Client(host, port);
  if ((this->_net->connect(Network::TCP | Network::UDP)) == true)
    {
      this->sendq->setNetwork(_net);
      this->_thread->run(this);
      this->_connect = true;
      return (true);
    }
  return (false);
}

void ClientNetwork::disconnect()
{
  this->_net->disconnect(Network::TCP | Network::UDP);
  this->_thread->stop();
  this->_connect = false;
}

bool ClientNetwork::isConnect() const
{
  return (this->_connect);
  //return (!this->_thread->isStop());
}

void ClientNetwork::treatment(const std::string &trame)
{
  std::string tmp;

  this->_agr->push(trame);
  while (this->_agr->checksum(tmp))
    {
      this->execq->push(tmp);
      tmp.clear();
    }
}

int ClientNetwork::execute()
{
  int max;
  int sock[2];
  fd_set readfs;
  struct timeval time;

  sock[0] = this->_net->getSocket(Network::TCP);
  sock[1] = this->_net->getSocket(Network::UDP);
  max = ((sock[0] > sock[1]) ? sock[0] : sock[1]) + 1;
  this->_net->send(this->KEY + this->SEPARATOR);
  while (true)
    {
      FD_ZERO(&readfs);
      FD_SET(sock[0], &readfs);
      FD_SET(sock[1], &readfs);
      time.tv_sec = 0;
      time.tv_usec = this->TIMEOUT_SELECT;
      if (select(max, &readfs, 0, 0, &time) > 0)
	{
	  if (FD_ISSET(sock[0], &readfs))
	    {
	      std::string trame;

	      if ((trame = this->_net->receive(Network::TCP)) == "")
		return (0);
	      this->treatment(trame);
	    }
	  else if (FD_ISSET(sock[1], &readfs))
	    {
	      std::vector<std::string> msg = split_string(this->_net->receive(Network::UDP), '@');
	      if (msg.size() >= 2)
		this->treatment(msg[1]);
	    }
	}
      if (this->_buffer.isTimeout())
	this->executeBuffer();
    }
  return (0);
}

void ClientNetwork::executeBuffer()
{
  while (!this->_buffer.isEmpty())
    this->execq->push(this->_buffer.pop());
}

void *ClientNetwork::run(ClientNetwork *client)
{
  client->execute();
  return (0);
}
