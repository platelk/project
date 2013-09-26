//
// Teleportation.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Teleportation.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 22:45:45 2013 kevin platel
// Last update Fri Jun  7 11:48:57 2013 phalip_z
//

#include "Teleportation.hh"

namespace Daemon
{
  const std::string	& Teleportation::NAME = "teleportation";

  Teleportation::Teleportation(GameObject *owner)
    : AComponent(Teleportation::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Teleportation>(*this, &Daemon::Teleportation::eventTeleportation));
	this->_isInit = true;
      }
  }

  Teleportation::~Teleportation()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Teleportation::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Teleportation>(*this, &Daemon::Teleportation::eventTeleportation));
	this->_isInit = true;
      }
  }

  void	Teleportation::spellTeleportation()
  {
    /*
    ** TO DO
    */
  }

  void	Teleportation::eventTeleportation(Trame &)
  {
    this->spellTeleportation();
  }

  void	Teleportation::update()
  {
  }

  std::string	Teleportation::serialize()
  {
    return this->createPackage("");
  }

  Teleportation*	Teleportation::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Teleportation(owner);
  }

  Teleportation*	Teleportation::clone(GameObject *owner) const
  {
    return new Teleportation(owner);
  }
}
