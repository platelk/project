//
// Peach.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Peach.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:28:01 2013 kevin platel
// Last update Tue Jun 11 09:26:18 2013 alexis leprovost
//

#include "Peach.hh"
#include "Life.hh"
#include "Characteristic.hh"
#include "PlayerRender.hh"

const std::string &Peach::NAME = "peach";

Peach::Peach(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/peach/peach.fbx", 3));
  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(100);
  life->setCurrentHP(100);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(0);
  charac->setDamage(5);
  charac->setSpeed(2);
  charac->setASPD(3);
  charac->setStrength(4);
  charac->setRange(4);
}

Peach::~Peach()
{
}
