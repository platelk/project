//
// AUDPMultiCast.cpp for AUDPMultiCast in /home/guiho_r/projet/piscine/rush2/piscine_cpp_rush2-2016-guiho_r/src/iostreamgift/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jan 20 02:03:33 2013 ronan guiho
// Last update Mon Jun  3 18:53:10 2013 ronan guiho
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

#include "Client/Network/AUDPMultiCast.hh"

AUDPMultiCast::AUDPMultiCast(const std::string &host, unsigned short port) : _host(host), _port(port)
{ }

AUDPMultiCast::~AUDPMultiCast()
{

}

void AUDPMultiCast::setHost(const std::string &host)
{
  this->_host = host;
}

std::string AUDPMultiCast::getHost() const
{
  return (this->_host);
}

unsigned short AUDPMultiCast::getPort() const
{
  return (this->_port);
}

SOCKET AUDPMultiCast::getSocket() const
{
  return (this->_sock);
}

int AUDPMultiCast::createSocket()
{
  if ((this->_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    return (-1);
  return (0);
}
