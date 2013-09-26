//
// ClientNetwork.hh for ClientNetwork in /home/guiho_r/depot/bomberman/inc/Client/Network
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Tue May 28 10:55:07 2013 ronan guiho
// Last update Mon Jun 10 22:15:45 2013 alexis leprovost
//

#ifndef __CLIENT_NETWORK_HH__
#define __CLIENT_NETWORK_HH__

#include <string>

#include "Thread.hpp"
#include "Aggregator.hh"
#include "ClientBuffer.hpp"
#include "Network/Client.hh"
#include "ExecuteQueue.hpp"
#include "ClientSendQueue.hpp"

class ClientNetwork
{
public:
  typedef Daemon::ExecuteQueue<std::string> ExecuteQ;
  typedef ClientSendQueue<std::string> CSendQ;
private:
  Network::Client *_net;
  Daemon::ClientBuffer<std::string> _buffer;
  Thread<ClientNetwork *, void *> *_thread;
  Aggregator *_agr;
  bool	_connect;
public:
  static const int MAX_MSG;
  static const double TIMEOUT_MSG;
  static const double TIMEOUT_SELECT;
  static const std::string KEY;
  static const std::string SEPARATOR;
  static ExecuteQ *execq;
  static CSendQ *sendq;
  ClientNetwork();
  bool connect(const std::string &host, const short port);
  void disconnect();
  bool isConnect() const;
  int execute();
private:
  void executeBuffer();
  void treatment(const std::string &trame);
  static void *run(ClientNetwork *client);
};

#endif
