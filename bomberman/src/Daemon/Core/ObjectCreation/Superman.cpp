//
// Superman.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Superman.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:35:37 2013 kevin platel
// Last update Tue Jun 11 09:28:09 2013 alexis leprovost
//

#include "Superman.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Superman::NAME = "superman";

Superman::Superman(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/superman/superman.fbx", 170));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(150);
  life->setCurrentHP(150);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(15);
  charac->setDamage(30);
  charac->setSpeed(2);
  charac->setASPD(3);
  charac->setStrength(3);
  charac->setRange(3);
}

Superman::~Superman()
{
}
