#ifndef __THROW_BOMB_H__
#define __THROW_BOMB_H__

#include "AComponent.hh"
#include "GameObject.hh"
#include "Bomb.hh"
#include "Position.hh"
#include "Timer.hh"

namespace Daemon
{
  class ThrowBomb : public AComponent
  {
    Timer	_t;
    Timer	_t_st;
    double	_recover;
  public:
    static const std::string NAME;

    ThrowBomb(GameObject *owner, double recover = 1);
    ~ThrowBomb();

    void	init();

    void	throwBomb(double dx, double dy, double dz, double f);
    /* data */
    void	eventThrowBomb(Trame &trame);

    void		update();
    std::string	serialize();
    ThrowBomb 	*unserialize(std::stringstream &s, GameObject *owner = 0);
    ThrowBomb	*clone(GameObject *owner) const;

    double	getRecover() const;
  };
}

#endif
