//
// Listener.hh for Listener in /home/guiho_r/projet/piscine/rush2/piscine_cpp_rush2-2016-guiho_r/src/iostreamgift/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jan 20 02:20:13 2013 ronan guiho
// Last update Mon Jun  3 18:39:09 2013 ronan guiho
//

#ifndef _LISTENER_H_
#define _LISTENER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

#include "AUDPMultiCast.hh"

class Listener : public AUDPMultiCast
{
private:
  struct ip_mreq _req;
public:
  Listener(const std::string &host, unsigned short port);
  virtual ~Listener();
  virtual int init();
  int bindSocket();
  std::string recv();
};

#endif /* _LISTENER_H_ */
