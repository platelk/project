//
// Mini.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Mini.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:42:48 2013 kevin platel
// Last update Fri Jun  7 11:42:06 2013 phalip_z
//

#include "Mini.hh"

namespace Daemon
{
  const std::string	& Mini::NAME = "mini";

  Mini::Mini(GameObject *owner)
    : AComponent(Mini::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Mini>(*this, &Daemon::Mini::eventMini));
	this->_isInit = true;
      }
  }

  Mini::~Mini()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	Mini::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Mini>(*this, &Daemon::Mini::eventMini));
	this->_isInit = true;
      }
  }

  void	Mini::spellMini()
  {
    /*
    ** TO DO
    */
  }

  void	Mini::eventMini(Trame &)
  {
    this->spellMini();
  }

  void	Mini::update()
  {
  }

  std::string	Mini::serialize()
  {
    return this->createPackage("");
  }

  Mini*	Mini::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Mini(owner);
  }

  Mini*	Mini::clone(GameObject *owner) const
  {
    return new Mini(owner);
  }
}
