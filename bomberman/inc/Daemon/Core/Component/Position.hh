#ifndef __POSITION_H__
#define __POSITION_H__

#include <iostream>
#include "AComponent.hh"
#include "EventTree.hh"
#include "Timer.hh"

namespace Daemon
{
  class Position : public AComponent
  {
  private:
    double	_x;
    double	_y;
    double	_z;

    double	_dx;
    double	_dy;
    double	_dz;

  public:
    static const	std::string	NAME;

    Position(GameObject *owner,
	     double x = 0, double y = 0, double z = 0,
	     double dx = 0, double dy = 0, double dz = 0);

    ~Position();

    /* data */

    void	init();

    void	setPos(double x, double y, double z, double dx, double dy, double dz);
    void	eventSetPos(Daemon::Trame &trame);

    void	update();
    std::string	serialize();
    Position	*unserialize(std::stringstream &s, GameObject *owner = 0);
    Position	*clone(GameObject *owner = 0) const;

    void	setX(double x);
    void	setY(double y);
    void	setZ(double z);

    void	setDx(double dx);
    void	setDy(double dy);
    void	setDz(double dz);

    double		getX() const;
    double		getY() const;
    double		getZ() const;

    double	getDx() const;
    double	getDy() const;
    double	getDz() const;

    std::string	getStrPos() const;
    std::string	getStrDir() const;
    std::string getStr() const;

    double	haveMove;
  };
}


#endif
