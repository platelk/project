//
// AUDPMultiCast.hh for AUDPMulticast in /home/guiho_r/projet/piscine/rush2/piscine_cpp_rush2-2016-guiho_r/src/iostreamgift/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jan 20 01:53:08 2013 ronan guiho
// Last update Mon Jun  3 18:39:33 2013 ronan guiho
//

#ifndef _AUDPMULTICAST_H_
#define _AUDPMULTICAST_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

typedef int SOCKET;

class AUDPMultiCast
{
protected:
  SOCKET _sock;
  struct sockaddr_in _addr;
  std::string _host;
  unsigned short _port;
protected:
  void setHost(const std::string &);
  std::string getHost() const;
  unsigned short getPort() const;
  SOCKET getSocket() const;
public:
  AUDPMultiCast(const std::string &host, unsigned short port);
  virtual ~AUDPMultiCast();
  virtual int createSocket();
  virtual int init() = 0;
};

#endif /* _AUDPMULTICAST_H_ */
