//
// Sender.cpp for Sender in /home/guiho_r/projet/piscine/rush2/piscine_cpp_rush2-2016-guiho_r/src/iostreamgift/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jan 20 02:10:28 2013 ronan guiho
// Last update Mon Jun  3 18:52:41 2013 ronan guiho
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

#include "Client/Network/Sender.hh"

Sender::Sender(const std::string &host, unsigned short port) : AUDPMultiCast(host, port)
{ }

Sender::~Sender()
{

}

int Sender::init()
{
  this->_addr.sin_family = AF_INET;
  this->_addr.sin_addr.s_addr = inet_addr(this->_host.c_str());
  this->_addr.sin_port=htons(this->_port);
  this->createSocket();
  return (0);
}

int Sender::send(std::string msg)
{
  if (sendto(this->_sock , msg.c_str(), msg.length(), 0, \
	     (struct sockaddr *)&this->_addr, sizeof(this->_addr)) < 0)
    return (-1);
  return (0);
}
