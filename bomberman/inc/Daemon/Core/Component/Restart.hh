#ifndef __RESTART_H__
# define __RESTART_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Restart : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Restart(GameObject *owner = 0);
    virtual ~Restart();

    void	init();

    void	spellRestart();
    void	eventRestart(Trame &trame);

    void	update();
    std::string	serialize();
    Restart*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Restart*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__RESTART_H__ */
