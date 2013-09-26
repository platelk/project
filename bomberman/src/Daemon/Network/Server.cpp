//
// Server.cpp for Server in /home/guiho_r/depot/dev_bomberman/network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri May 10 13:33:28 2013 ronan guiho
// Last update Sun Jun  9 20:27:23 2013 ronan guiho
//

#include <sstream>
#include <unistd.h>

#include "Network/Server.hh"
#include "Logging/ChannelConsole.hh"

Network::Server::Server(const short port)
  : _is_run(false), _log("Server")
{
  _socket[0] = -1;
  _socket[1] = -1;
  _sin.sin_addr.s_addr = htonl(INADDR_ANY);
  _sin.sin_family = AF_INET;
  _sin.sin_port = htons(port);
  _log.addChannel(new Logging::ChannelConsole);
}

short Network::Server::getPort() const
{
  return (ntohs(this->_sin.sin_port));
}

Network::Client *Network::Server::acceptConnection()
{
  int sock;
  socklen_t size;
  struct sockaddr_in cin;
  Network::Client *client;
  std::stringstream ss;

  size = sizeof(cin);
  sock = accept(this->_socket[0], (struct sockaddr *)&cin, &size);
  client = new Network::Client(inet_ntoa(cin.sin_addr), this->getPort());
  ss << sock;
  client->setSocket(sock);
  return (client);
}

bool Network::Server::run(const int type)
{
  std::stringstream ss;

  ss << this->getPort();
  if (type == Network::TCP ||
      type == (Network::TCP | Network::UDP))
    {
      this->_socket[0] = socket(AF_INET, SOCK_STREAM, 0);
      if ((bind(this->_socket[0], (struct sockaddr *)&(this->_sin), sizeof(this->_sin))) == -1)
	return (false);
      listen(this->_socket[0], 100);
    }
  if (type == Network::UDP ||
      type == (Network::TCP | Network::UDP))
    {
      this->_socket[1] = socket(AF_INET, SOCK_DGRAM, 0);
      if ((bind(this->_socket[1], (struct sockaddr *)&(this->_sin), sizeof(this->_sin))) == -1)
	return (false);
    }
  this->_is_run = true;
  return (true);
}

int Network::Server::getSocket(const int type)
{
  return ((type == Network::TCP) ? this->_socket[0] : this->_socket[1]);
}

void Network::Server::stop()
{
  close(this->_socket[0]);
  close(this->_socket[1]);
  Logging::Message msg("Server stop by user", "Network", Logging::Message::NOTICE);
  this->_log << msg;
}

bool Network::Server::isRunning() const
{
  return (this->_is_run);
}

std::string Network::Server::receive(Client *client, const int type)
{
  int ret;
  socklen_t sizesin;
  char buffer[1024];
  struct sockaddr_in sin;

  sizesin = sizeof(sin);
  if (type == Network::TCP)
    return (client->receive());
  else
    if ((ret = recvfrom(this->_socket[1], buffer, sizeof(buffer), 0,
			(struct sockaddr *)&sin, &sizesin)) > 0)
      {
	buffer[ret] = '\0';
	return (buffer);
      }
  return ("");
}

bool Network::Server::send(Network::Client *client, const std::string &buffer, const int type)
{
  if (type == Network::TCP)
    return (client->send(buffer));
  else
    if ((sendto(this->_socket[1], buffer.c_str(), buffer.size(),
		0, (struct sockaddr *)&client->getSockaddr(), client->getSockaddrSize())) > 0)
      return (true);
  return (false);
}
