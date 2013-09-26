//
// Darunia.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Darunia.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:27:13 2013 kevin platel
// Last update Tue Jun 11 09:18:22 2013 alexis leprovost
//

#include "Characteristic.hh"
#include "Darunia.hh"
#include "PlayerRender.hh"
#include "Life.hh"

const std::string &Darunia::NAME = "darunia";

Darunia::Darunia(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/darunia/darunia.fbx", 3.5));
  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(200);
  life->setCurrentHP(200);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(50);
  charac->setDamage(50);
  charac->setSpeed(1);
  charac->setASPD(1);
  charac->setStrength(0);
  charac->setRange(70);
}

Darunia::~Darunia()
{
}
