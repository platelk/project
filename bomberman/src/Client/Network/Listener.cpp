//
// Listener.cpp for Listener in /home/guiho_r/projet/piscine/rush2/piscine_cpp_rush2-2016-guiho_r/src/iostreamgift/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jan 20 02:21:43 2013 ronan guiho
// Last update Mon Jun  3 18:52:57 2013 ronan guiho
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <stdio.h>

#include "Client/Network/Listener.hh"

Listener::Listener(const std::string &host, unsigned short port) : AUDPMultiCast(host, port)
{

}

Listener::~Listener()
{

}

int Listener::init()
{
  this->_addr.sin_family = AF_INET;
  this->_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  this->_addr.sin_port = htons(this->_port);
  this->createSocket();
  this->bindSocket();
  return (0);
}

int Listener::bindSocket()
{
  if (bind(this->_sock, (struct sockaddr *)&this->_addr, sizeof(this->_addr)) < 0)
    return (-1);
  this->_req.imr_multiaddr.s_addr = inet_addr(this->_host.c_str());
  this->_req.imr_interface.s_addr = htonl(INADDR_ANY);
  if (setsockopt(this->_sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &this->_req, sizeof(this->_req)) < 0)
    return (-1);
  return (0);
}

std::string Listener::recv()
{
  int rtrn;
  char buffer[1024];
  socklen_t addrlen;
  std::string out_buffer;

  addrlen = sizeof(this->_addr);
  if ((rtrn = recvfrom(this->_sock, buffer, sizeof(buffer), 0,		\
		       (struct sockaddr *) &this->_addr, &addrlen)) > 0)
    {
      buffer[rtrn] = '\0';
      out_buffer = buffer;
    }
  return (out_buffer);
}
