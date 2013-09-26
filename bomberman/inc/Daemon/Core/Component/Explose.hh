#ifndef __EXPLOSE_H__
#define __EXPLOSE_H__


#include <iostream>
#include "AComponent.hh"
#include "EventTree.hh"
#include "Timer.hh"

namespace Daemon
{
  class Explose : public AComponent
  {
  private:
    Timer		_time;
    double		_timeout;
    int			_strength;
    int			_dmg;
  public:
    static const std::string NAME;

    Explose(GameObject *owner, double timeout, int strength, int dmg);
    ~Explose();

    /* data */
    void	explod();
    void	eventExplod(Trame &trame);

    void	init();
    void	update();
    std::string	serialize();
    Explose	*unserialize(std::stringstream &s, GameObject *owner = 0);
    Explose	*clone(GameObject *owner = 0) const;

    double		getTimeOut() const;
    int			getStrength() const;
  };
}

#endif
