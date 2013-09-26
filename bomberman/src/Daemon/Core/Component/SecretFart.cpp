//
// SecretFart.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/SecretFart.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 22:13:38 2013 kevin platel
// Last update Fri Jun  7 11:47:13 2013 phalip_z
//


#include "SecretFart.hh"

namespace Daemon
{
  const std::string &	SecretFart::NAME = "secret_fart";

  SecretFart::SecretFart(GameObject *owner)
    : AComponent(SecretFart::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<SecretFart>(*this, &Daemon::SecretFart::eventSecretFart));
	this->_isInit = true;
      }
  }

  SecretFart::~SecretFart()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	SecretFart::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<SecretFart>(*this, &Daemon::SecretFart::eventSecretFart));
	this->_isInit = true;
      }
  }

  void	SecretFart::spellSecretFart()
  {
    /*
    ** TO DO
    */
  }

  void	SecretFart::eventSecretFart(Trame &)
  {
    this->spellSecretFart();
  }

  void	SecretFart::update()
  {
  }

  std::string	SecretFart::serialize()
  {
    return this->createPackage("");
  }

  SecretFart*	SecretFart::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new SecretFart(owner);
  }

  SecretFart*	SecretFart::clone(GameObject *owner) const
  {
    return new SecretFart(owner);
  }
}
