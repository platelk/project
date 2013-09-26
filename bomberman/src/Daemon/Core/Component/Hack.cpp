//
// Hack.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Hack.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:44:19 2013 kevin platel
// Last update Fri Jun  7 11:40:20 2013 phalip_z
//

#include "Hack.hh"
#include "EventTree.hh"

namespace Daemon
{
  const std::string	& Hack::NAME = "hack";

  Hack::Hack(GameObject *owner)
    : AComponent(Hack::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Hack>(*this, &Daemon::Hack::eventHack));
	this->_isInit = true;
      }
  }

  Hack::~Hack()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Hack::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Hack>(*this, &Daemon::Hack::eventHack));
	this->_isInit = true;
      }
  }

  void	Hack::spellHack()
  {
    if (this->_owner)
      {
	Daemon::Trame	*trame = new Daemon::Trame(this->_owner->getId(), "cmd_explose", "", "", "", "");
	Daemon::EventTree::pushEvent(trame);
      }
  }

  void	Hack::eventHack(Trame &)
  {
    this->spellHack();
  }

  void	Hack::update()
  {
  }

  std::string	Hack::serialize()
  {
    return this->createPackage("");
  }

  Hack*	Hack::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Hack(owner);
  }

  Hack*	Hack::clone(GameObject *owner) const
  {
    return new Hack(owner);
  }
}
