//
// Client.hh for Client in /home/guiho_r/depot/dev_bomberman/network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri May 10 10:24:14 2013 ronan guiho
// Last update Tue May 28 16:22:47 2013 ronan guiho
//

#ifndef __CLIENT_HH__
#define __CLIENT_HH__

#include <string>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Network/NetworkType.hh"

namespace Network
{
  class Client
  {
  private:
    int _socket[2];
    bool _is_connect;
    bool _is_init;
    std::string host;
    int _sizemsg;
    socklen_t _sizesin;
    struct sockaddr_in _sin;
  public:
    Client(const std::string &host, const short port);
    bool connect(const int = TCP);
    void disconnect(const int type = TCP);
    short getPort() const;
    int getSocket(const int type = TCP) const;
    void setSocket(const int socket, const int type = TCP);
    const std::string getHost() const;
    void setPort(const short port);
    void setSizeMsg(const int size);
    int getSizeMsg();
    void setHost(const std::string &host);
    const struct sockaddr_in &getSockaddr() const;
    const socklen_t &getSockaddrSize() const;
    bool isConnect() const;
    const std::string receive(const int type = TCP);
    bool send(const std::string &buffer, const int type = TCP) const;
  };
}

#endif
