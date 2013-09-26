#ifndef __INVERSION_H__
# define __INVERSION_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Inversion : public AComponent
  {
  private:
    Timer	_t;
    Timer	_laps;
  public:
    static const std::string &NAME;

    Inversion(GameObject *owner = 0);
    virtual ~Inversion();

    void	spellInversion();
    void	eventInversion(Trame &trame);

    void	init();

    void	update();
    std::string	serialize();
    Inversion*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Inversion*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__INVERSION_H__ */
