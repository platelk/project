//
// BonusSpwan.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/BonusSpwan.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sat Jun  8 17:20:19 2013 kevin platel
// Last update Sun Jun  9 21:43:49 2013 kevin platel
//

#include "BonusSpawn.hh"
#include "BonusBox.hh"
#include "Position.hh"

namespace Daemon
{
  const std::string &BonusSpawn::NAME = "bonus_spawn";

  BonusSpawn::BonusSpawn(GameObject *owner)
    : AComponent(BonusSpawn::NAME, "", owner)
  {
  }

  BonusSpawn::~BonusSpawn()
  {
  }

  void	BonusSpawn::update()
  {
  }

  std::string	BonusSpawn::serialize()
  {
    return this->createPackage("");
  }

  BonusSpawn*	BonusSpawn::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new BonusSpawn(owner);
  }

  BonusSpawn*	BonusSpawn::clone(GameObject *owner) const
  {
    return new BonusSpawn(owner);
  }
}
