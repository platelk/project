//
// Client.cpp for Client.cpp in /home/guiho_r/depot/dev_bomberman/network
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri May 10 10:25:03 2013 ronan guiho
// Last update Fri Jun  7 01:59:29 2013 ronan guiho
//

#include <string>
#include <iostream>
#include <unistd.h>

#include "Network/Client.hh"

Network::Client::Client(const std::string &host, const short port)
  :  _is_connect(false), _is_init(false), _sizemsg(1024), _sizesin(0)
{
  struct hostent *shost;

  _socket[0] = -1;
  _socket[1] = -1;
  if ((shost = gethostbyname(host.c_str())))
    {
      _sin.sin_addr = *(struct in_addr *)shost->h_addr;
      _sin.sin_port = htons(port);
      _sin.sin_family = AF_INET;
      _sizesin = sizeof(this->_sin);
      _is_init = true;
    }
}

bool Network::Client::connect(const int type)
{
  if (this->_is_init)
    {
      if (type == Network::TCP ||
	  type == (Network::TCP | Network::UDP))
	{
	  this->_socket[0] = socket(AF_INET, SOCK_STREAM, 0);
	  if (::connect(this->_socket[0], (struct sockaddr *)&this->_sin, sizeof(struct sockaddr)) == -1)
	    {
	      this->_is_connect = false;
	      return (this->_is_connect);
	    }
	  this->_is_connect = true;
	}
      if (type == Network::UDP ||
	  type == (Network::TCP | Network::UDP))
	this->_socket[1] = socket(AF_INET, SOCK_DGRAM, 0);
    }
  return (this->_is_connect);
}

void Network::Client::disconnect(const int type)
{
  if ((type == Network::TCP ||
       type == (Network::TCP | Network::UDP)) && (this->_socket[0] != -1))
    close(this->_socket[0]);
  if ((type == Network::UDP ||
       type == (Network::TCP | Network::UDP)) && (this->_socket[1] != -1))
    close(this->_socket[1]);
}

short Network::Client::getPort() const
{
  return ((this->_is_init) ? ntohs(this->_sin.sin_port) : 0);
}

int Network::Client::getSocket(const int type) const
{
  return ((type == Network::TCP) ? this->_socket[0] : this->_socket[1]);
}

void Network::Client::setSocket(const int socket, const int type)
{
  (type == Network::TCP) ? this->_socket[0] = socket : this->_socket[1] = socket;
}

const std::string Network::Client::getHost() const
{
  return (inet_ntoa(this->_sin.sin_addr));
}

void Network::Client::setPort(const short port)
{
  this->_sin.sin_port = htons(port);
}

int Network::Client::getSizeMsg()
{
  return (this->_sizemsg);
}

void Network::Client::setSizeMsg(const int size)
{
  this->_sizemsg = size;
}

void Network::Client::setHost(const std::string &host)
{
  struct hostent *shost;

  if ((shost = gethostbyname(host.c_str())))
    {
      _sin.sin_addr = *(struct in_addr *)shost->h_addr;
      _is_init = true;
      _sizesin = sizeof(this->_sin);
    }
  else
    _is_init = false;
}

bool Network::Client::isConnect() const
{
  return (this->_is_connect);
}

const std::string Network::Client::receive(const int type)
{
  int ret;
  char buffer[this->_sizemsg];

  if ((ret = (type == Network::TCP) ? recv(this->_socket[0], buffer, sizeof(buffer), 0) :
       recvfrom(this->_socket[1], buffer, sizeof(buffer - 1), 0,
		(struct sockaddr *)&this->_sin, &this->_sizesin)) > 0)
    {
      buffer[ret] = '\0';
      return (buffer);
    }
  return ("");
}

bool Network::Client::send(const std::string &buffer, const int type) const
{
  int ret;

  ret = 0;
  if (type == Network::TCP)
    ret = ::send(this->_socket[0], buffer.c_str(), buffer.size(), 0);
  else
    ret = sendto(this->_socket[1], buffer.c_str(), buffer.size(),
		 0, (struct sockaddr *)&this->_sin, this->_sizesin);
  return (ret > 0 ? true : false);
}

const struct sockaddr_in &Network::Client::getSockaddr() const
{
  return (this->_sin);
}

const socklen_t &Network::Client::getSockaddrSize() const
{
  return (this->_sizesin);
}
