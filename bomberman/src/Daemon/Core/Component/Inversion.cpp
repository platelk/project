//
// Inversion.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Inversion.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:24:39 2013 kevin platel
// Last update Fri Jun  7 11:40:56 2013 phalip_z
//

#include "Inversion.hh"
#include "Life.hh"

namespace Daemon
{
  const std::string	& Inversion::NAME = "inversion";

  Inversion::Inversion(GameObject *owner)
    : AComponent(Inversion::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Inversion>(*this, &Daemon::Inversion::eventInversion));
	this->_isInit = true;
      }
  }

  Inversion::~Inversion()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Inversion::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Inversion>(*this, &Daemon::Inversion::eventInversion));
	this->_isInit = true;
      }
    this->_t.start();
  }

  void	Inversion::spellInversion()
  {
    if (this->_owner && this->_t.isTimeOut(30))
      {
	Daemon::Life *ptr = dynamic_cast<Daemon::Life *>(this->_owner->getComponent(Daemon::Life::NAME));
	if (ptr)
	  {
	    this->_t.reset();
	    this->_t.start();
	    this->_laps.start();
	    ptr->healMode();
	    this->_owner->hasBeenModify = true;
	  }
      }
  }

  void	Inversion::eventInversion(Trame &)
  {
    this->spellInversion();
  }

  void	Inversion::update()
  {
    if (this->_laps.isTimeOut(10))
      {
	Daemon::Life *ptr = dynamic_cast<Daemon::Life *>(this->_owner->getComponent(Daemon::Life::NAME));
	if (ptr)
	  {
	    this->_laps.reset();
	    ptr->dmgMode();
	    this->_owner->hasBeenModify = true;
	  }
      }
  }

  std::string	Inversion::serialize()
  {
    return this->createPackage("");
  }

  Inversion*	Inversion::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Inversion(owner);
  }

  Inversion*	Inversion::clone(GameObject *owner) const
  {
    return new Inversion(owner);
  }
}
