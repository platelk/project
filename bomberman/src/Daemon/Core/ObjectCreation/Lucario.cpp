//
// Lucario.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Lucario.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 15:35:12 2013 kevin platel
// Last update Tue Jun 11 09:25:18 2013 alexis leprovost
//

#include "Lucario.hh"
#include "PlayerRender.hh"
#include "Life.hh"
#include "Characteristic.hh"

const std::string &Lucario::NAME = "lucario";

Lucario::Lucario(Listener *owner, const std::string &id)
  : Player(owner, id, 120, 0, 0, 0)
{
this->addComponent(new Daemon::PlayerRender(this, "assets/models/characters/lucario/lucario.fbx", 7));

Daemon::Life *life = dynamic_cast<Daemon::Life *>(this->getComponent(Daemon::Life::NAME));
life->setMaxHp(120);
life->setCurrentHP(120);

Daemon::Characteristic* charac = dynamic_cast<Daemon::Characteristic*>(this->getComponent(Daemon::Characteristic::NAME));
 charac->setResi(15);
  charac->setDamage(35);
  charac->setSpeed(2);
  charac->setASPD(3.5);
  charac->setStrength(3);
  charac->setRange(3);
}

Lucario::~Lucario()
{
}
