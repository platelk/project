//
// Megaman.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Megaman.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:38:38 2013 kevin platel
// Last update Tue Jun 11 09:25:54 2013 alexis leprovost
//

#include "Megaman.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Megaman::NAME = "megaman";

Megaman::Megaman(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/megaman/megaman.fbx", 70));
  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(110);
  life->setCurrentHP(110);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(20);
  charac->setDamage(25);
  charac->setSpeed(2);
  charac->setASPD(4);
  charac->setStrength(2);
  charac->setRange(2);
}

Megaman::~Megaman()
{
}
