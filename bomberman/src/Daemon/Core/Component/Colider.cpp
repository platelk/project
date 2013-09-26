#include <sstream>

#include "Colider.hh"
#include "Position.hh"

const std::string	Daemon::Colider::NAME = "colider";

Daemon::Colider::Circle::Circle(Daemon::Colider *parent, int x, int y, int size)

{
  this->_parent = parent;
  this->_x = x;
  this->_y = y;
  this->_size = size;
}

Daemon::Colider::Circle::~Circle()
{
}

bool	Daemon::Colider::Circle::colide(Circle &c)
{
  double	vx = c.getX() - this->getX();
  double	vy = c.getY() - this->getY();
  double	dist = vx*vx + vy*vy;

  if ((dist >= ((c.getSize()) * (this->getSize()))))
    return false;
  return true;
}

int		Daemon::Colider::Circle::getX() const
{
  Daemon::Position *p = 0;
  if (this->_parent && this->_parent->getOwner())
    p = dynamic_cast<Daemon::Position*>(_parent->getOwner()->getComponent("position"));
  if (p)
    return this->_x + p->getX();
  else
    return this->_x;
}

int		Daemon::Colider::Circle::getY() const
{
  Daemon::Position *p = 0;
  if (this->_parent && this->_parent->getOwner())
    p = dynamic_cast<Daemon::Position*>(_parent->getOwner()->getComponent("position"));

  if (p)
    return this->_y + p->getY();
  else
    return this->_y;
}

int		Daemon::Colider::Circle::getSize() const
{
  return this->_size;
}

void		Daemon::Colider::Circle::setSize(int size)
{
  this->_size = size;
}

Daemon::Colider::Colider(GameObject *owner)
  : AComponent(Colider::NAME, "", owner)
{
}

Daemon::Colider::~Colider()
{

}

bool	Daemon::Colider::colide(Colider &c)
{
  for (size_t i = 0; i < this->_colide.size(); ++i)
    {
      for (size_t j = 0; j < c._colide.size(); ++j)
	{
	  if (this->_colide[i].colide(c._colide[j]))
	    return true;
	}
    }
  return false;
}

void	Daemon::Colider::addCircle(int x, int y, int size)
{
  this->_colide.push_back(Colider::Circle(this, x, y, size));
}

void	Daemon::Colider::update()
{
}

void	Daemon::Colider::clear()
{
  this->_colide.clear();
}

std::string	Daemon::Colider::serialize()
{
  std::string s = this->createData(static_cast<int>(this->_colide.size()));
  for (size_t i = 0; i < this->_colide.size(); ++i)
    {
      s += this->createData(this->_colide[i]._x);
      s += this->createData(this->_colide[i]._y);
      s += this->createData(this->_colide[i]._size);
    }
  return this->createPackage(s);
}

Daemon::Colider	*Daemon::Colider::unserialize(std::stringstream &s, GameObject *owner)
{
  int	i = 0;
  int	x = 0;
  int	y = 0;
  int	size = 0;
  Daemon::Colider *ptr = new Colider(owner);
  std::stringstream ss;
  ss << this->unPack(s);
  std::string g = this->getData(ss);
  i = str_to_int(g);
  while (i)
    {
      x = str_to_int(this->getData(ss));
      y = str_to_int(this->getData(ss));
      size = str_to_int(this->getData(ss));
      ptr->addCircle(x, y, size);
      i--;
    }
  return ptr;
}

int	Daemon::Colider::getSize(size_t idx)
{
  if (idx <= (this->_colide.size()-1))
    {
      return this->_colide[idx].getSize();
    }
  return 0;
}

void	Daemon::Colider::setSize(int size, size_t i)
{
  if (i <= (this->_colide.size()))
    this->_colide[i].setSize(size);
}


Daemon::Colider	*Daemon::Colider::clone(GameObject *owner) const
{
  Colider *ptr = new Colider(owner);

  for (size_t i = 0; i < this->_colide.size(); i++)
    ptr->addCircle(this->_colide[i]._x, this->_colide[i]._y, this->_colide[i]._size);
  return ptr;
}
