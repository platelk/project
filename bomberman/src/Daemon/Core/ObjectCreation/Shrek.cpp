//
// Shrek.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Shrek.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:23:33 2013 kevin platel
// Last update Tue Jun 11 09:26:57 2013 alexis leprovost
//

#include "Shrek.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Shrek::NAME = "shrek";

Shrek::Shrek(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/shrek/shrek.fbx", 10));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(190);
  life->setCurrentHP(190);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(35);
  charac->setDamage(35);
  charac->setSpeed(1);
  charac->setASPD(1);
  charac->setStrength(5);
  charac->setRange(5);
}

Shrek::~Shrek()
{
}
