//
// ServerBroadcast.hh for ServerBroadcast in /home/guiho_r/depot/bomberman/inc/Client/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Mon Jun  3 17:24:16 2013 ronan guiho
// Last update Mon Jun  3 20:34:49 2013 ronan guiho
//

#ifndef __SERVER_BROADCAST_HH__
#define __SERVER_BROADCAST_HH__

#include <string>

class ServerBroadcast
{
private:
  std::string _title;
  std::string _host;
  short _port;
public:
  ServerBroadcast(const std::string &title, const std::string &host, const short port);
  ServerBroadcast(const ServerBroadcast &broadcast);
  void setTitle(const std::string &title);
  void setPort(const short port);
  void setHost(const std::string &host);
  const std::string &getTitle() const;
  const std::string &getHost() const;
  short getPort() const;
  std::string serialize() const;
  void unserialize(const std::string &data);
};

#endif
