//
// Pit.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Pit.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 01:05:15 2013 kevin platel
// Last update Tue Jun 11 09:26:32 2013 alexis leprovost
//

#include "Pit.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Pit::NAME = "pit";

Pit::Pit(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/pit/pit.fbx", 10));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(130);
  life->setCurrentHP(130);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(0);
  charac->setDamage(15);
  charac->setSpeed(2);
  charac->setASPD(3);
  charac->setStrength(5);
  charac->setRange(5);
}

Pit::~Pit()
{
}
