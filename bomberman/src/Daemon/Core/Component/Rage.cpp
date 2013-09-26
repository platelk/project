//
// Rage.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Rage.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:39:07 2013 kevin platel
// Last update Fri Jun  7 11:45:49 2013 phalip_z
//

#include "Rage.hh"

namespace Daemon
{
  const std::string	& Rage::NAME = "rage";

  Rage::Rage(GameObject *owner)
    : AComponent(Rage::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Rage>(*this, &Daemon::Rage::eventRage));
	this->_isInit = true;
      }
  }

  Rage::~Rage()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Rage::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Rage>(*this, &Daemon::Rage::eventRage));
	this->_isInit = true;
      }
  }

  void	Rage::spellRage()
  {
    /*
    ** TO DO
    */
  }

  void	Rage::eventRage(Trame &)
  {
    this->spellRage();
  }

  void	Rage::update()
  {
  }

  std::string	Rage::serialize()
  {
    return this->createPackage("");
  }

  Rage*	Rage::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Rage(owner);
  }

  Rage*	Rage::clone(GameObject *owner) const
  {
    return new Rage(owner);
  }
}
