//
// ListClient.cpp for ListClient in /home/guiho_r/depot/bomberman/inc/Daemon
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Mon May 13 14:52:17 2013 ronan guiho
//

#include <string>
#include <sstream>
#include <unistd.h>

#include "LockScope.hh"
#include "ListClient.hh"
#include "DaemonClient.hh"
#include "DaemonServer.hh"
#include "Logging/ChannelConsole.hh"
#include "Core/Trame/Trame.hh"

Daemon::ListClient::ListClient(const int freq)
  :  _freq(freq), _id_ref(1), _log("ListClient"), _thread(&Daemon::ListClient::update)
{
  _thread.run(this);
  _log.addChannel(new Logging::ChannelConsole);
}

Daemon::DaemonClient *Daemon::ListClient::addClient(Network::Client *client)
{
  LockScope lock(this->_mutex);
  Daemon::DaemonClient *dclient;
  std::stringstream ss;

  if (!this->_id_free.empty())
    {
      ss << this->_id_free.front();
      this->_id_free.pop();
    }
  else
    ss << (++this->_id_ref);
  dclient = new Daemon::DaemonClient(ss.str(), client);
  this->_list_client[ss.str()] = dclient;
  dclient->setState(Daemon::DaemonClient::AUTH);
  Daemon::Trame trame(-1, "connexion", "", "", "", ss.str());
  client->send(trame.toString());
  return (dclient);
}

void Daemon::ListClient::checkClientIntegrity()
{
  LockScope lock(this->_mutex);
  std::queue<Daemon::DaemonClient *> qdelete;

  for (Daemon::ListClient::ListDaemonClient::iterator it = this->_list_client.begin();
       it != this->_list_client.end() && this->_list_client.size() > 0; ++it)
    {
      if ((*it).second)
	if ((((*it).second)->getThread()->isStop()) == true)
	  qdelete.push((*it).second);
    }
  while (!qdelete.empty())
    {
      this->deleteClient(qdelete.front()->getID());
      qdelete.pop();
    }
}

void Daemon::ListClient::deleteClient(const std::string &id)
{
  Daemon::DaemonClient *client;
  if ((client = this->getClient(id)))
    {
      Daemon::Trame trame(-1, "deconnexion", "", "", "", id);
      Daemon::DaemonServer::execq->push(trame.toString());
      this->_list_client.erase(this->_list_client.find(id));
      this->_id_free.push(id);
    }
}

void Daemon::ListClient::disconnectAll()
{
  LockScope lock(this->_mutex);

  for (Daemon::ListClient::ListDaemonClient::iterator it = this->_list_client.begin();
       it != this->_list_client.end(); ++it)
    (*it).second->getClient()->disconnect();
}

int Daemon::ListClient::getRefreshFrequency() const
{
  return (this->_freq);
}

int Daemon::ListClient::getCountClient() const
{
  return (this->_list_client.size());
}

void Daemon::ListClient::setRefreshFrequency(const int freq)
{
  this->_freq = freq;
}

bool Daemon::ListClient::isClient(const std::string &id)
{
  LockScope lock(this->_mutex);

  for (Daemon::ListClient::ListDaemonClient::iterator it = this->_list_client.begin();
       it != this->_list_client.end(); ++it)
    if ((*it).first == id)
      return (true);
  return (false);
}

Daemon::DaemonClient *Daemon::ListClient::getClient(const std::string &id)
{
  return (this->_list_client[id]);
}

void *Daemon::ListClient::update(Daemon::ListClient *list)
{
  while (true)
    {
      usleep(list->getRefreshFrequency());
      list->checkClientIntegrity();
    }
  return (0);
}

Daemon::ListClient::ListDaemonClient &Daemon::ListClient::getAllClient()
{
  LockScope lock(this->_mutex);

  return (this->_list_client);
}

Mutex *Daemon::ListClient::getMutex()
{
  return (&this->_mutex);
}
