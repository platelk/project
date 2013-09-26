//
// ServerBroadcast.cpp for ServerBroadcast in /home/guiho_r/depot/bomberman/inc/Client/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Mon Jun  3 18:06:18 2013 ronan guiho
// Last update Mon Jun  3 20:55:37 2013 ronan guiho
//

#include <vector>
#include <string>
#include <sstream>

#include "utils.hh"
#include "Client/Network/ServerBroadcast.hh"

ServerBroadcast::ServerBroadcast(const std::string &title, const std::string &host, const short port)
  : _title(title), _host(host), _port(port)
{
}

ServerBroadcast::ServerBroadcast(const ServerBroadcast &broad)
  : _title(broad.getTitle()), _host(broad.getHost()), _port(broad.getPort())
{
}

void ServerBroadcast::setTitle(const std::string &title)
{
  this->_title = title;
}

void ServerBroadcast::setPort(const short port)
{
  this->_port = port;
}

void ServerBroadcast::setHost(const std::string &host)
{
  this->_host = host;
}

const std::string &ServerBroadcast::getTitle() const
{
  return (this->_title);
}

const std::string &ServerBroadcast::getHost() const
{
  return (this->_host);
}

short ServerBroadcast::getPort() const
{
  return (this->_port);
}

std::string ServerBroadcast::serialize() const
{
  std::stringstream ss;
  std::string seria;

  ss << this->_port;
  seria = this->_title + "|" + this->_host + "|" + ss.str();
  return (seria);
}

void ServerBroadcast::unserialize(const std::string &data)
{
  std::stringstream ss;
  std::vector<std::string> serv = split_string(data, '|');

  if (serv.size() == 3)
    {
      this->_title = serv[0];
      this->_host = serv[1];
      ss << serv[2];
      ss >> this->_port;
    }
}
