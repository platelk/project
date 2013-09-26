#ifndef __HACK_H__
# define __HACK_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Hack : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Hack(GameObject *owner = 0);
    virtual ~Hack();

    void	spellHack();
    void	eventHack(Trame &trame);

    void	init();

    void	update();
    std::string	serialize();
    Hack*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Hack*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__HACK_H__ */
