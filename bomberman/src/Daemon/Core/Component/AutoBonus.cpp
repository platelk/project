//
// AutoBonus.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/AutoBonus.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 22:43:18 2013 kevin platel
// Last update Fri Jun  7 11:33:03 2013 phalip_z
//

#include "AutoBonus.hh"

namespace Daemon
{
  const std::string	& AutoBonus::NAME = "auto_bonus";

  AutoBonus::AutoBonus(GameObject *owner)
    : AComponent(AutoBonus::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<AutoBonus>(*this, &Daemon::AutoBonus::eventAutoBonus));
	this->_isInit = true;
      }
  }

  AutoBonus::~AutoBonus()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	AutoBonus::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<AutoBonus>(*this, &Daemon::AutoBonus::eventAutoBonus));
	this->_isInit = true;
      }
  }

  void	AutoBonus::spellAutoBonus()
  {
    /*
    ** TO DO
    */
  }

  void	AutoBonus::eventAutoBonus(Trame &)
  {
    this->spellAutoBonus();
  }

  void	AutoBonus::update()
  {
  }

  std::string	AutoBonus::serialize()
  {
    return this->createPackage("");
  }

  AutoBonus*	AutoBonus::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new AutoBonus(owner);
  }

  AutoBonus*	AutoBonus::clone(GameObject *owner) const
  {
    return new AutoBonus(owner);
  }
}
