#ifndef __LEVELUP_H__
# define __LEVELUP_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class LevelUp : public AComponent
  {
  private:
    Timer	_t;
    Timer	_laps;
    bool	_hasLaunched;

    int		_resi;
    long	_dmg;
    double	_speed;
    double	_aspd;
    size_t	_strength;
    double	_range;
  public:
    static const std::string &NAME;

    LevelUp(GameObject *owner = 0);
    virtual ~LevelUp();

    void	spellLevelUp();
    void	eventLevelUp(Trame &trame);

    void	init();

    void	update();
    std::string	serialize();
    LevelUp*	unserialize(std::stringstream &s, GameObject *owner = 0);
    LevelUp*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__LEVELUP_H__ */
