//
// Gohan.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Gohan.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:24:34 2013 kevin platel
// Last update Tue Jun 11 09:24:34 2013 alexis leprovost
//

#include "Gohan.hh"
#include "PlayerRender.hh"
#include "Characteristic.hh"
#include "Life.hh"

const std::string &Gohan::NAME = "gohan";

Gohan::Gohan(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/gohan/gohan.fbx", 0.5));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(175);
  life->setCurrentHP(175);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(5);
  charac->setDamage(30);
  charac->setSpeed(2);
  charac->setASPD(2.5);
  charac->setStrength(2);
  charac->setRange(2);
}

Gohan::~Gohan()
{

}
