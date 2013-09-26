#ifndef __CHARACTERISTIC_H__
# define __CHARACTERISTIC_H__

#include <iostream>
#include "AComponent.hh"
#include "EventTree.hh"

namespace Daemon
{
  class Characteristic : public AComponent
  {
  private:
    int		_resi;
    long	_dmg;
    double	_speed;
    double	_aspd;
    size_t	_strength;
    double	_range;

  public:
    static const std::string	& NAME;

    Characteristic(GameObject *owner = 0,
		   int resi = 0,
		   long dmg = 0,
		   double speed = 1.0,
		   double aspd = 4.0,
		   float strength = 1,
		   double range = 1.0);
    virtual ~Characteristic();

    int		getResi() const;
    long	getDamage() const;
    double	getSpeed() const;
    double	getASPD() const;
    float	getStrength() const;
    double	getRange() const;

    void	setResi(int resi);
    void	setDamage(long damage);
    void	setSpeed(double speed);
    void	setASPD(double aspd);
    void	setStrength(float strength);
    void	setRange(double range);

    void		update();
    std::string		serialize();
    Characteristic*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Characteristic*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__CHARACTERISTIC_H__ */
