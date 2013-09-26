#ifndef __BONUSSPWAN_H__
# define __BONUSSPWAN_H__

#include <iostream>
#include "AComponent.hh"
#include "Characteristic.hh"
#include "Timer.hh"

namespace Daemon
{
  class BonusSpawn : public AComponent
  {
  public:
    static const std::string &NAME;
    BonusSpawn(GameObject *owner = 0);
    ~BonusSpawn();

    void	update();
    std::string serialize();
    BonusSpawn* unserialize(std::stringstream &s, GameObject *owner = 0);
    BonusSpawn* clone(GameObject *owner = 0) const;
  };
}

#endif /* !__BONUSSPWAN_H__ */
