//
// Link.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Link.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:30:14 2013 kevin platel
// Last update Tue Jun 11 09:25:00 2013 alexis leprovost
//

#include "Link.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Link::NAME = "link";

Link::Link(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/link/link.fbx", 8));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(145);
  life->setCurrentHP(145);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(10);
  charac->setDamage(20);
  charac->setSpeed(1.5);
  charac->setASPD(2.5);
  charac->setStrength(2);
  charac->setRange(2);
}

Link::~Link()
{
}
