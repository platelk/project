#ifndef __AUTOBONUS_H__
# define __AUTOBONUS_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class AutoBonus : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    AutoBonus(GameObject *owner = 0);
    virtual ~AutoBonus();

    void	spellAutoBonus();
    void	eventAutoBonus(Trame &trame);
    virtual void	init();

    void	update();
    std::string	serialize();
    AutoBonus*	unserialize(std::stringstream &s, GameObject *owner = 0);
    AutoBonus*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__AUTOBONUS_H__ */
