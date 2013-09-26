#ifndef __SPEEDUP_H__
# define __SPEEDUP_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class SpeedUp : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    SpeedUp(GameObject *owner = 0);
    virtual ~SpeedUp();

    void	init();

    void	spellSpeedUp();
    void	eventSpeedUp(Trame &trame);

    void	update();
    std::string	serialize();
    SpeedUp*	unserialize(std::stringstream &s, GameObject *owner = 0);
    SpeedUp*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__SPEEDUP_H__ */
