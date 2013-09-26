//
// Tooling.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Tooling.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:29:34 2013 kevin platel
// Last update Fri Jun  7 11:50:10 2013 phalip_z
//

#include "Tooling.hh"

namespace Daemon
{
  const std::string	& Tooling::NAME = "tooling";

  Tooling::Tooling(GameObject *owner)
    : AComponent(Tooling::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Tooling>(*this, &Daemon::Tooling::eventTooling));
	this->_isInit = true;
      }
  }

  Tooling::~Tooling()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Tooling::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Tooling>(*this, &Daemon::Tooling::eventTooling));
	this->_isInit = true;
      }
  }

  void	Tooling::spellTooling()
  {
    /*
    ** TO DO
    */
  }

  void	Tooling::eventTooling(Trame &)
  {
    this->spellTooling();
  }

  void	Tooling::update()
  {
  }

  std::string	Tooling::serialize()
  {
    return this->createPackage("");
  }

  Tooling*	Tooling::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Tooling(owner);
  }

  Tooling*	Tooling::clone(GameObject *owner) const
  {
    return new Tooling(owner);
  }
}
