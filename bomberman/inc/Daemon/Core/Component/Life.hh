#ifndef __LIFE_H__
#define __LIFE_H__

#include <iostream>
#include "AComponent.hh"
#include "EventTree.hh"

namespace Daemon
{
  class Life : public AComponent
  {
  private:
    size_t		_hp;
    size_t		_max_hp;
    bool		_canTakeDamage;
    int			_coefficient;
  public:
    static const	std::string	NAME;

    Life(GameObject *owner, size_t current_hp, size_t max_hp);
    virtual ~Life();

    void	init();

    /* data */
    size_t	getLife() const;
    size_t	getMaxLife() const;

    void	setCurrentHP(size_t current_hp);
    void	setMaxHp(size_t max_hp);
    void	dmgMode();
    void	healMode();
    void	takeDamage(size_t dmg);
    void	healtDamage(size_t dmg);
    void	bombExplod(int x, int y, int z, int strength, int dmg);
    size_t	currentHealt() const;

    void	damage(bool can);
    bool	canTakeDamage() const;

    void	die();

    void	eventTakeDamage(Trame &trame);
    void	eventHealtDamage(Trame &trame);
    void	eventBombExplod(Trame &trame);
    void	eventDie(Trame &trame);

    void	update();
    std::string 	serialize();
    AComponent*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Life	*clone(Daemon::GameObject *owner = 0) const;
  };
}

#endif
