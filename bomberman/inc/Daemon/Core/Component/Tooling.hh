#ifndef __TOOLING_H__
# define __TOOLING_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Tooling : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Tooling(GameObject *owner = 0);
    virtual ~Tooling();

    void	init();

    void	spellTooling();
    void	eventTooling(Trame &trame);

    void	update();
    std::string	serialize();
    Tooling*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Tooling*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__TOOLING_H__ */
