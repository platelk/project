//
// SpeedUp.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/SpeedUp.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 22:12:01 2013 kevin platel
// Last update Fri Jun  7 11:48:28 2013 phalip_z
//

#include "SpeedUp.hh"

namespace Daemon
{
  const std::string &	SpeedUp::NAME = "speed_up";

  SpeedUp::SpeedUp(GameObject *owner)
    : AComponent(SpeedUp::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<SpeedUp>(*this, &Daemon::SpeedUp::eventSpeedUp));
	this->_isInit = true;
      }
  }

  SpeedUp::~SpeedUp()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	SpeedUp::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<SpeedUp>(*this, &Daemon::SpeedUp::eventSpeedUp));
	this->_isInit = true;
      }
  }

  void	SpeedUp::spellSpeedUp()
  {
    /*
    ** TO DO
    */
  }

  void	SpeedUp::eventSpeedUp(Trame &)
  {
    this->spellSpeedUp();
  }

  void	SpeedUp::update()
  {
  }

  std::string	SpeedUp::serialize()
  {
    return this->createPackage("");
  }

  SpeedUp*	SpeedUp::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new SpeedUp(owner);
  }

  SpeedUp*	SpeedUp::clone(GameObject *owner) const
  {
    return new SpeedUp(owner);
  }
}
