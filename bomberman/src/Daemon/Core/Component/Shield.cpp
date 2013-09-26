//
// Shield.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Shield.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:32:55 2013 kevin platel
// Last update Fri Jun  7 11:48:02 2013 phalip_z
//

#include "Shield.hh"

namespace Daemon
{
  const std::string	& Shield::NAME = "level_up";

  Shield::Shield(GameObject *owner)
    : AComponent(Shield::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Shield>(*this, &Daemon::Shield::eventShield));
	this->_isInit = true;
      }
  }

  Shield::~Shield()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Shield::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Shield>(*this, &Daemon::Shield::eventShield));
	this->_isInit = true;
      }
  }

  void	Shield::spellShield()
  {
    /*
    ** TO DO
    */
  }

  void	Shield::eventShield(Trame &)
  {
    this->spellShield();
  }

  void	Shield::update()
  {
  }

  std::string	Shield::serialize()
  {
    return this->createPackage("");
  }

  Shield*	Shield::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Shield(owner);
  }

  Shield*	Shield::clone(GameObject *owner) const
  {
    return new Shield(owner);
  }
}
