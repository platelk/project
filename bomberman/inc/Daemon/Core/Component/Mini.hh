#ifndef __MINI_H__
# define __MINI_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Mini : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Mini(GameObject *owner = 0);
    virtual ~Mini();

    void	init();

    void	spellMini();
    void	eventMini(Trame &trame);

    void	update();
    std::string	serialize();
    Mini*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Mini*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__MINI_H__ */
