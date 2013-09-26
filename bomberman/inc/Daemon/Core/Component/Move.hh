#ifndef __MOVE_H__
#define __MOVE_H__

#include "AComponent.hh"
#include "Position.hh"
#include "Trame.hh"

namespace Daemon
{
  class Move : public AComponent
  {
  private:
    double	_to_x;
    double	_to_y;
    double _to_z;
    double _dx;
    double _dy;
    double _dz;
    double _move_speed;
    bool	_moving;
    Timer	_t;
    int		_iter;
    int		_pivot;
  public:
    static const	std::string	NAME;

    Move(GameObject *owner);
    ~Move();

    bool		move(double dx, double dy, double dz, double speed);
    bool		move_to(double x, double y, double z, double dx, double dy, double dz, double speed, int iter);
    /* data */
    void		eventMove(Trame &trame);
    void		update();
    std::string		serialize();
    Move		*unserialize(std::stringstream &s, GameObject *owner = 0);
    Move		*clone(GameObject *owner = 0) const;

    virtual void	init();

    void		setToX(double x);
    void		setToY(double y);
    void		setToZ(double z);
    void		setToDx(double dx);
    void		setToDy(double dy);
    void		setToDz(double dz);
    void		setMoveSpeed(double move_speed);

    double		getToX() const;
    double		getToY() const;
    double		getToZ() const;
    double		getToDx() const;
    double		getToDy() const;
    double		getToDz() const;
    double		getMoveSpeed() const;
  };
}
#endif
