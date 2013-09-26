//
// Mario.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Mario.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sun Jun  2 16:14:24 2013 kevin platel
// Last update Tue Jun 11 09:25:32 2013 alexis leprovost
//

#include "Mario.hh"
#include "Characteristic.hh"
#include "Life.hh"
#include "PlayerRender.hh"

const std::string &Mario::NAME = "mario";

Mario::Mario(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/mario/mario.fbx", 200));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(150);
  life->setCurrentHP(150);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(15);
  charac->setDamage(10);
  charac->setSpeed(1.5);
  charac->setASPD(2);
  charac->setStrength(3);
  charac->setRange(3);
}

Mario::~Mario()
{
}
