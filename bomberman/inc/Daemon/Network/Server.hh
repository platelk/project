//
// Server.hh for Server in /home/guiho_r/depot/dev_bomberman/network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri May 10 13:16:28 2013 ronan guiho
// Last update Mon May 13 10:38:07 2013 ronan guiho
//

#ifndef __SERVER_HH__
#define __SERVER_HH__

#include <string>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Network/Client.hh"
#include "Network/NetworkType.hh"
#include "Logging/Logger.hpp"

namespace Network
{
  class Server
  {
  private:
    int _socket[2];
    bool _is_run;
    struct sockaddr_in _sin;
    Logging::Logger _log;
  public:
    Server(const short port);
    void stop();
    short getPort() const;
    bool isRunning() const;
    Client *acceptConnection();
    int getSocket(const int type = TCP);
    bool run(const int type = TCP);
    std::string receive(Client *client, const int type = TCP);
    bool send(Client *client, const std::string &msg, const int type = TCP);
  };
}

#endif
