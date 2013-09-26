//
// DaemonClient.hh
// 
// Made by Guiho Ronan
// 
// Started on  Sun May 12 17:50:53 2013 Guiho Ronan
// Last update Tue May 28 11:24:42 2013 ronan guiho
//

#ifndef __DAEMON_CLIENT_HH__
#define __DAEMON_CLIENT_HH__

#include <map>
#include <queue>
#include <string>

#include "Aggregator.hh"
#include "ClientBuffer.hpp"
#include "Network/Client.hh"
#include "Thread/Thread.hpp"
#include "ExecuteQueue.hpp"

namespace Daemon
{
  class DaemonClient
  {
  public:
    typedef ExecuteQueue<std::string> ExecuteQ;
    typedef enum { AUTH = 0, INGAME, WAIT } StateClient;
  private:
    std::string _id;
    Network::Client *_client;
    Mutex _mutex;
    Thread<DaemonClient *, void *> _thread;
    ClientBuffer<std::string> _buffer;
    ExecuteQ *_exec;
    StateClient _state;
    Aggregator *_agr;
  public:
    static const int MAX_MSG;
    static const double TIMEOUT_MSG;
    static const double TIMEOUT_SELECT;
    static const double TIMEOUT_AUTH;
    DaemonClient(const std::string &id, Network::Client *client);
    Network::Client *getClient();
    const std::string &getID() const;
    Thread<DaemonClient *, void *> *getThread();
    void pushToBuffer(const std::string &msg);
    void pushToAggreg(const std::string &msg);
    bool isTimeoutBuffer();
    void executeBuffer();
    void stop();
    void setState(const StateClient state);
    const StateClient &getState() const;
    bool waitAuthentification();
  private:
    static void *run(Daemon::DaemonClient *client);
  };
}

#endif
