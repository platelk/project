//
// Falco.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Falco.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:30:47 2013 kevin platel
// Last update Tue Jun 11 09:24:11 2013 alexis leprovost
//

#include "Falco.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Falco::NAME = "falco";

Falco::Falco(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
  this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/falco/falco.fbx", 10));

  Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
  life->setMaxHp(175);
  life->setCurrentHP(175);

  Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
  charac->setResi(20);
  charac->setDamage(20);
  charac->setSpeed(1.5);
  charac->setASPD(4);
  charac->setStrength(4);
  charac->setRange(4);
}

Falco::~Falco()
{
}
