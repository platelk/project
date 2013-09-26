//
// Double.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Double.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:34:37 2013 kevin platel
// Last update Fri Jun  7 11:38:30 2013 phalip_z
//

#include "Double.hh"

namespace Daemon
{
  const std::string	& Double::NAME = "double";

  Double::Double(GameObject *owner)
    : AComponent(Double::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<Double>(*this, &Daemon::Double::eventDouble));
	this->_isInit = true;
      }
  }

  Double::~Double()
  {
    if (this->_owner && this->_isInit)
      this->_owner->removeEvent("spell");
  }

  void	Double::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<Double>(*this, &Daemon::Double::eventDouble));
	this->_isInit = true;
      }
  }

  void	Double::spellDouble()
  {
    /*
    ** TO DO
    */
  }

  void	Double::eventDouble(Trame &)
  {
    this->spellDouble();
  }

  void	Double::update()
  {
  }

  std::string	Double::serialize()
  {
    return this->createPackage("");
  }

  Double*	Double::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Double(owner);
  }

  Double*	Double::clone(GameObject *owner) const
  {
    return new Double(owner);
  }
}
