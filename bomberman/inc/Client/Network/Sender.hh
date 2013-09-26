//
// Sender.hh for Sender in /home/guiho_r/projet/piscine/rush2/piscine_cpp_rush2-2016-guiho_r/src/iostreamgift/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jan 20 01:58:36 2013 ronan guiho
// Last update Mon Jun  3 18:38:56 2013 ronan guiho
//

#ifndef _SENDER_H_
#define _SENDER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

#include "AUDPMultiCast.hh"

class Sender : public AUDPMultiCast
{
public:
  Sender(const std::string &host, unsigned short port);
  virtual ~Sender();
  virtual int init();
  int send(std::string msg);
};

#endif /* _SENDER_H_ */
