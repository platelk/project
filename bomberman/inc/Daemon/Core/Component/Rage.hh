#ifndef __RAGE_H__
# define __RAGE_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Rage : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Rage(GameObject *owner = 0);
    virtual ~Rage();

    void	init();

    void	spellRage();
    void	eventRage(Trame &trame);

    void	update();
    std::string	serialize();
    Rage*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Rage*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__RAGE_H__ */
