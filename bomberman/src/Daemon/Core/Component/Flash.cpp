//
// Flash.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Flash.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 22:37:52 2013 kevin platel
// Last update Fri Jun  7 11:39:51 2013 phalip_z
//

#include "Flash.hh"
#include "DaemonServer.hh"

namespace Daemon
{
  const std::string	& Flash::NAME = "fash";

  Flash::Flash(GameObject *owner)
    : AComponent(Flash::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Flash>(*this, &Daemon::Flash::eventFlash));
	owner->addEvent("flash", new Action<Flash>(*this, &Daemon::Flash::eventExecFlash));
	this->_isInit = true;
      }
  }

  Flash::~Flash()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Flash::init()
  {
    if (this->_owner && !this->_isInit)
      this->_owner->addEvent("spell", new Action<Flash>(*this, &Daemon::Flash::eventFlash));
      this->_isInit = true;
  }

  void	Flash::spellFlash()
  {
    if (this->_t.isTimeOut(30) && this->_owner)
      {
	Trame trame(this->_owner->getId(), "flash", this->_owner->getType(), "", "", this->serialize());
	Daemon::DaemonServer::sendq->push("0", trame.toString());
	this->_t.reset();
      }
  }

  void	Flash::execFlash()
  {
  }

  void	Flash::eventFlash(Trame &)
  {
    this->spellFlash();
  }

  void	Flash::eventExecFlash(Trame &)
  {
    this->execFlash();
  }

  void	Flash::update()
  {
  }

  std::string	Flash::serialize()
  {
    return this->createPackage("");
  }

  Flash*	Flash::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Flash(owner);
  }

  Flash*	Flash::clone(GameObject *owner) const
  {
    return new Flash(owner);
  }
}
