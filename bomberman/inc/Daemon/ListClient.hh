//
// ListClient.hh for ListClient in /home/guiho_r/depot/bomberman/inc/Daemon
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Mon May 13 14:49:08 2013 ronan guiho
// Last update Sun Jun  9 12:02:32 2013 ronan guiho
//

#ifndef __LIST_CLIENT_HH__
#define __LIST_CLIENT_HH__

#include <map>
#include <queue>

#include "Network/Client.hh"
#include "DaemonClient.hh"
#include "Thread/Thread.hpp"
#include "Thread/Mutex.hh"
#include "Logging/Logger.hpp"

namespace Daemon
{
  class ListClient
  {
  public:
    typedef std::map<std::string, DaemonClient *> ListDaemonClient;
  private:
    int _freq;
    int _id_ref;
    Logging::Logger _log;
    Mutex _mutex;
    Thread<ListClient *, void *> _thread;
    std::queue<std::string> _id_free;
    ListDaemonClient _list_client;
  public:
    ListClient(const int freq);
    int getCountClient() const;
    DaemonClient *addClient(Network::Client *client);
    int getRefreshFrequency() const;
    void setRefreshFrequency(const int freq);
    DaemonClient *getClient(const std::string &id);
    ListDaemonClient &getAllClient();
    bool isClient(const std::string &id);
    Mutex *getMutex();
    void disconnectAll();
  private:
    void checkClientIntegrity();
    void deleteClient(const std::string &id);
    static void *update(ListClient *list);
  };
}

#endif
