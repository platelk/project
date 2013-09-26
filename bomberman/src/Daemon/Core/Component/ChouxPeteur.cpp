//
// ChouxPeteur.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/ChouxPeteur.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 00:05:47 2013 kevin platel
// Last update Fri Jun  7 11:34:00 2013 phalip_z
//

#include "ChouxPeteur.hh"

namespace Daemon
{
  const std::string	& ChouxPeteur::NAME = "choux_peteur";

  ChouxPeteur::ChouxPeteur(GameObject *owner)
    : AComponent(ChouxPeteur::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<ChouxPeteur>(*this, &Daemon::ChouxPeteur::eventChouxPeteur));
	this->_isInit = true;
      }
  }

  ChouxPeteur::~ChouxPeteur()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	ChouxPeteur::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<ChouxPeteur>(*this, &Daemon::ChouxPeteur::eventChouxPeteur));
	this->_isInit = true;
      }
  }

  void	ChouxPeteur::spellChouxPeteur()
  {
    /*
    ** TO DO
    */
  }

  void	ChouxPeteur::eventChouxPeteur(Trame &)
  {
    this->spellChouxPeteur();
  }

  void	ChouxPeteur::update()
  {
  }

  std::string	ChouxPeteur::serialize()
  {
    return this->createPackage("");
  }

  ChouxPeteur*	ChouxPeteur::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new ChouxPeteur(owner);
  }

  ChouxPeteur*	ChouxPeteur::clone(GameObject *owner) const
  {
    return new ChouxPeteur(owner);
  }
}
