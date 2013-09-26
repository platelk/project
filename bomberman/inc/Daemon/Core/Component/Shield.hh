#ifndef __SHIELD_H__
# define __SHIELD_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Shield : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Shield(GameObject *owner = 0);
    virtual ~Shield();

    void	init();

    void	spellShield();
    void	eventShield(Trame &trame);

    void	update();
    std::string	serialize();
    Shield*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Shield*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__SHIELD_H__ */
