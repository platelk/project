//
// DaemonServer.hh
// 
// Made by Guiho Ronan
// 
// Started on  Sun May 12 16:40:03 2013 Guiho Ronan
// Last update Sun Jun  9 12:05:47 2013 ronan guiho
//

#ifndef __DAEMON_SERVER_HH__
#define __DAEMON_SERVER_HH__

#include <string>

#include "Thread.hpp"
#include "ListClient.hh"
#include "SendQueue.hpp"
#include "ExecuteQueue.hpp"
#include "ClientBuffer.hpp"
#include "Network/Server.hh"

namespace Daemon
{
  class DaemonServer
  {
  public:
    typedef ExecuteQueue<std::string> ExecuteQ;
    typedef SendQueue<std::string> SendQ;
  private:
    Network::Server _network;
    ListClient _list;
    ClientBuffer<std::string> _udp_buffer;
    Thread<DaemonServer *, void *> _thread;
  public:
    static const int MAX_MSG;
    static const double TIMEOUT_MSG;
    static const double TIMEOUT_SELECT;
    static const std::string KEY;
    static const std::string SEPARATOR;
    static ExecuteQ *execq;
    static SendQ *sendq;
    DaemonServer(const short port);
    bool run();
    void stop();
    bool isRunning();
    void sendTo(const std::string &id, const std::string &data);
    void disconnectAll();
  private:
    static void *execute(DaemonServer *daemon);
    void executeBuffer();
  };
}

#endif
