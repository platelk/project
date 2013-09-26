//
// Kratos.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Kratos.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:32:12 2013 kevin platel
// Last update Tue Jun 11 09:24:48 2013 alexis leprovost
//

#include "Kratos.hh"
#include "PlayerRender.hh"
#include "Characteristic.hh"
#include "Life.hh"

const std::string &Kratos::NAME = "kratos";

Kratos::Kratos(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/kratos/kratos.fbx", 200));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(200);
  life->setCurrentHP(200);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(15);
  charac->setDamage(35);
  charac->setSpeed(2);
  charac->setASPD(2.5);
  charac->setStrength(3);
  charac->setRange(3);
}

Kratos::~Kratos()
{
}
