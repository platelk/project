//
// Network.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Network.cpp in /home/vink/projet/cpp/bomberman/inc/Daemon/Core/Component
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon May 20 18:06:23 2013 kevin platel
// Last update Sun Jun  9 21:22:49 2013 kevin platel
//

#include "Network.hh"
#include "EventTree.hh"

const	std::string	Daemon::Networks::NAME = "network";

Daemon::Networks::Networks(GameObject *owner, const std::string &id)
  : AComponent(Networks::NAME, "", owner), _id(id), _state(false), _sync(false)
{
  if (owner)
    {
      owner->addEvent("connected", new Action<Networks>(*this, &Daemon::Networks::eventConnected));
      owner->addEvent("send_to", new Action<Networks>(*this, &Daemon::Networks::eventSendTo));
      owner->addEvent("deconnexion", new Action<Networks>(*this, &Daemon::Networks::eventDisconnect));
      this->_isInit = true;
    }
}

Daemon::Networks::~Networks()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("connected");
      this->_owner->removeEvent("send_to");
      this->_owner->removeEvent("deconnexion");
    }
}

void	Daemon::Networks::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("connected", new Action<Networks>(*this, &Daemon::Networks::eventConnected));
      this->_owner->addEvent("send_to", new Action<Networks>(*this, &Daemon::Networks::eventSendTo));
      this->_owner->addEvent("deconnexion", new Action<Networks>(*this, &Daemon::Networks::eventDisconnect));
      this->_isInit = true;
    }
}

std::string	Daemon::Networks::getId()
{
  return (this->_id);
}

void		Daemon::Networks::setId(const std::string &id)
{
  this->_id = id;
}

void		Daemon::Networks::sendTo(const std::string &msg)
{
  Daemon::DaemonServer::sendq->push(this->_id, msg);
}

void		Daemon::Networks::setState(const std::string &state)
{
  if ("success" == state)
    {
      this->_state = true;
      /*
      ** TO CHANGE
      */
      this->_sync = true;
    }
  else
    this->_state = false;
}

void		Daemon::Networks::eventConnected(Trame &)
{
  this->setState("success");
}

void		Daemon::Networks::eventSendTo(Trame &trame)
{
  this->setState(trame.getArgument());
}

void		Daemon::Networks::eventDisconnect(Trame &trame)
{
  if (trame.getArgument() == this->getId())
    {
      Daemon::EventTree::core->removeEntity(this->_owner);
      (this->_owner->getParent())->removeChild(this->_owner);
    }
}

bool		Daemon::Networks::isSync()
{
  return this->_sync;
}

void		Daemon::Networks::sync(bool s)
{
  this->_sync = s;
}

void		Daemon::Networks::eventSync(Trame &)
{
  this->sync(true);
}

void		Daemon::Networks::update()
{
}

std::string	Daemon::Networks::serialize()
{
  return this->createPackage("");
}

Daemon::Networks*	Daemon::Networks::unserialize(std::stringstream &s, GameObject *owner)
{
  std::stringstream	ss;

  ss << this->unPack(s);
  return new Daemon::Networks(owner);
}

Daemon::Networks*	Daemon::Networks::clone(Daemon::GameObject *owner) const
{
  return new Daemon::Networks(owner);
}
