#ifndef __COLIDER_H__
#define __COLIDER_H__

#include "AComponent.hh"
#include "Position.hh"

namespace Daemon
{
  class Colider : public AComponent
  {
  private:
    class Circle
    {
    public:
      Colider	*_parent;
      int	_x;
      int	_y;
      int	_size;
    public:
      Circle(Colider *parent, int x, int y, int size);
      ~Circle();

      /* data */
      bool	colide(Circle &c);
      int		getX() const;
      int		getY() const;
      int		getSize() const;
      void       	setSize(int size);
      std::string	serialize() const;
    };

    std::deque<Colider::Circle>	_colide;
  public:
    static const	std::string	NAME;
    Colider(GameObject *owner);
    virtual ~Colider();

    /* data */
    void	clear();
    bool	colide(Colider &c);
    void	update();
    void	addCircle(int x, int y, int size);
    int		getSize(size_t i = 0);
    void       	setSize(int size, size_t i = 0);
    std::string	serialize();
    Colider *unserialize(std::stringstream &s, Daemon::GameObject *owner = 0);
    Colider *clone(Daemon::GameObject *owner = 0) const;

  };
}

#endif
