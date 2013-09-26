//
// Restart.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Restart.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:28:09 2013 kevin platel
// Last update Fri Jun  7 11:46:41 2013 phalip_z
//

#include "Restart.hh"

namespace Daemon
{
  const std::string	& Restart::NAME = "restart";

  Restart::Restart(GameObject *owner)
    : AComponent(Restart::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Restart>(*this, &Daemon::Restart::eventRestart));
	this->_isInit = true;
      }
  }

  Restart::~Restart()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Restart::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Restart>(*this, &Daemon::Restart::eventRestart));
	this->_isInit = true;
      }
  }

  void	Restart::spellRestart()
  {
    /*
    ** TO DO
    */
  }

  void	Restart::eventRestart(Trame &)
  {
    this->spellRestart();
  }

  void	Restart::update()
  {
  }

  std::string	Restart::serialize()
  {
    return this->createPackage("");
  }

  Restart*	Restart::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Restart(owner);
  }

  Restart*	Restart::clone(GameObject *owner) const
  {
    return new Restart(owner);
  }
}
