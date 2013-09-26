//
// SacBoy.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/SacBoy.cpp in /home/vink/projet/cpp/bomberman/inc/Daemon/Core/Object
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 13:20:58 2013 kevin platel
// Last update Tue Jun 11 09:26:47 2013 alexis leprovost
//

#include "SacBoy.hh"
#include "Life.hh"
#include "Characteristic.hh"
#include "PlayerRender.hh"

const std::string &SacBoy::NAME = "sacboy";

SacBoy::SacBoy(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/sacboy/sacboy.fbx", 45));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(180);
  life->setCurrentHP(180);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(25);
  charac->setDamage(5);
  charac->setSpeed(1.5);
  charac->setASPD(2);
  charac->setStrength(3);
  charac->setRange(3);
}

SacBoy::~SacBoy()
{
}
