#ifndef __TELEPORTATION_H__
# define __TELEPORTATION_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Teleportation : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Teleportation(GameObject *owner = 0);
    virtual ~Teleportation();

    void	init();

    void	spellTeleportation();
    void	eventTeleportation(Trame &trame);

    void	update();
    std::string	serialize();
    Teleportation*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Teleportation*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__TELEPORTATION_H__ */
