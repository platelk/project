//
// Sonic.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Sonic.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 01:09:43 2013 kevin platel
// Last update Tue Jun 11 09:28:00 2013 alexis leprovost
//

#include "Sonic.hh"
#include "Life.hh"
#include "Characteristic.hh"
#include "PlayerRender.hh"

const std::string &Sonic::NAME = "sonic";

Sonic::Sonic(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/sonic/sonic.fbx", 50));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(150);
  life->setCurrentHP(150);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(0);
  charac->setDamage(5);
  charac->setSpeed(3);
  charac->setASPD(2);
  charac->setStrength(1);
  charac->setRange(1);
}

Sonic::~Sonic()
{
}
