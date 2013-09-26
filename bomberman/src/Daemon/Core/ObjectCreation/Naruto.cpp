//
// Naruto.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Naruto.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:33:25 2013 kevin platel
// Last update Tue Jun 11 09:26:07 2013 alexis leprovost
//

#include "Naruto.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Naruto::NAME = "naruto";

Naruto::Naruto(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/naruto/naruto.fbx", 5));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(170);
  life->setCurrentHP(170);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(30);
  charac->setDamage(30);
  charac->setSpeed(1.5);
  charac->setASPD(2.5);
  charac->setStrength(2);
  charac->setRange(2);
}

Naruto::~Naruto()
{
}
