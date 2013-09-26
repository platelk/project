#include "Position.hh"
#include "Bomb.hh"

const	std::string	Daemon::Position::NAME = "position";

Daemon::Position::Position(GameObject *owner, double x, double y, double z, double dx, double dy, double dz)
  : AComponent(Position::NAME, "", owner), _x(x), _y(y), _z(z), _dx(dx), _dy(dy), _dz(dz)
{
  this->haveMove = false;
  if (owner)
    {
      owner->addEvent("set_pos", new Action<Position>(*this, &Daemon::Position::eventSetPos));
      this->_isInit = true;
    }
}

Daemon::Position::~Position()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("set_pos");
    }
}

void	Daemon::Position::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("set_pos", new Action<Position>(*this, &Daemon::Position::eventSetPos));
      this->_isInit = true;
    }
}

void	Daemon::Position::update()
{
  // if (Daemon::DaemonServer::sendq && Daemon::EventTree::root && this->haveMove)
  //   {
  //     double id = (this->_owner ? this->_owner->getId() : -1);
  //     Trame trame(id, "set_pos", "", "", double_to_str(id), this->getStr());
  //     Daemon::DaemonServer::sendq->push("0", trame.toString());
  //     this->haveMove = false;
  //   }
}

void	Daemon::Position::setX(double x)
{
  this->_x = x;
}

void	Daemon::Position::setY(double y)
{
  this->_y = y;
}

void	Daemon::Position::setZ(double z)
{
  this->_z = z;
}

void	Daemon::Position::setDx(double dx)
{
  this->_dx = dx;
}

void	Daemon::Position::setDy(double dy)
{
  this->_dy = dy;
}

void	Daemon::Position::setDz(double dz)
{
  this->_dz = dz;
}

void	Daemon::Position::setPos(double x, double y, double z, double dx, double dy, double dz)
{
  this->setX(x);
  this->setY(y);
  this->setZ(z);

  this->setDx(dx);
  this->setDy(dy);
  this->setDz(dz);
}

void	Daemon::Position::eventSetPos(Daemon::Trame &trame)
{
  std::vector<std::string> v = split_string(trame.getArgument(), '|');
  this->setPos(str_to_double(v[0]), str_to_double(v[1]), str_to_double(v[2]),
	       str_to_double(v[3]), str_to_double(v[4]), str_to_double(v[5]));
}

double		Daemon::Position::getX() const
{
  return this->_x;
}

double		Daemon::Position::getY() const
{
  return this->_y;
}

double		Daemon::Position::getZ() const
{
  return this->_z;
}

double	Daemon::Position::getDx() const
{
  return this->_dx;
}

double	Daemon::Position::getDy() const
{
  return this->_dy;
}

double	Daemon::Position::getDz() const
{
  return this->_dz;
}

std::string	Daemon::Position::getStrPos() const
{
  return double_to_str(this->getX()) + "|" + double_to_str(this->getY()) + "|" + double_to_str(this->getZ());
}

std::string	Daemon::Position::getStrDir() const
{
  return double_to_str(this->getDx()) + "|" + double_to_str(this->getDy()) + "|" + double_to_str(this->getDz());
}

std::string	Daemon::Position::getStr() const
{
  return this->getStrPos() + "|" + this->getStrDir();
}

Daemon::Position	*Daemon::Position::clone(Daemon::GameObject *owner) const
{
  return new Position(owner, this->getX(), this->getY(), this->getZ(), this->getDx(), this->getDy(), this->getDz());
}

std::string		Daemon::Position::serialize()
{
  return this->createPackage(this->createData(this->getX())
			     + this->createData(this->getY())
			     + this->createData(this->getZ())
			     + this->createData(this->getDx())
			     + this->createData(this->getDy())
			     + this->createData(this->getDz()));
}

Daemon::Position*	Daemon::Position::unserialize(std::stringstream &s, Daemon::GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new Position(owner, str_to_double(this->getData(ss)), str_to_double(this->getData(ss)), str_to_double(this->getData(ss)), str_to_double(this->getData(ss)), str_to_double(this->getData(ss)), str_to_double(this->getData(ss)));
}
