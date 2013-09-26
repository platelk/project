#include "Move.hh"
#include "IAction.hh"
#include "EventTree.hh"
#include "Core.hh"
#include "Colider.hh"
#include "Characteristic.hh"
#include "Bonus.hh"
#include "BonusBox.hh"
#include "BonusRender.hh"

const	std::string	Daemon::Move::NAME = "move";

Daemon::Move::Move(GameObject *owner)
  : AComponent(Move::NAME, "", owner), _move_speed(1)
{
  this->_moving = false;
  if (owner)
    {
      owner->addEvent("move", new Action<Move>(*this, &Daemon::Move::eventMove));
      this->_isInit = true;
    }
}

Daemon::Move::~Move()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("move");
    }
}

void	Daemon::Move::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("move", new Action<Move>(*this, &Daemon::Move::eventMove));
      this->_isInit = true;
    }
}

bool	Daemon::Move::move(double dx, double dy, double dz, double speed)
{
  if (this->_owner)
    {
      Daemon::Position *ptr = dynamic_cast<Daemon::Position *>(this->_owner->getComponent("position"));
      Daemon::Colider *col = dynamic_cast<Daemon::Colider *>(this->_owner->getComponent("colider"));

      if (this->_owner->haveComponent(Characteristic::NAME))
	speed *= dynamic_cast<Daemon::Characteristic *>(this->_owner->getComponent(Characteristic::NAME))->getSpeed();
      if (ptr)
	{
	  double	nx = ptr->getX();
	  double	ny = ptr->getY();
	  double	nz = ptr->getZ();

	  ptr->setX(ptr->getX() + dx*speed);
	  ptr->setY(ptr->getY() + dy*speed);
	  ptr->setZ(ptr->getZ() + dz*speed);
	  ptr->setDx(dx);
	  ptr->setDy(dy);
	  ptr->setDz(dz);
	  for (size_t i = 0; col && i < Daemon::EventTree::core->_entity.size(); ++i)
	    {
	      if (Daemon::EventTree::core->_entity[i]->haveComponent("colider"))
		{
		  Daemon::Colider *c = dynamic_cast<Daemon::Colider *>(Daemon::EventTree::core->_entity[i]->getComponent("colider"));
		  if (col->colide(*c) && col != c && Daemon::EventTree::core->_entity[i]->haveComponent(BonusRender::NAME))
		    {
		      Trame t(Daemon::EventTree::core->_entity[i]->getId(), "die", "", "",
			      int_to_str(Daemon::EventTree::core->_entity[i]->getId()), "");
		      (Daemon::EventTree::core->_entity[i]->getParent())->toDelete(Daemon::EventTree::core->_entity[i]);
		      Daemon::Bonus *b = new Daemon::Bonus(this->_owner);
		      Daemon::DaemonServer::sendq->push("0", t.toString());
		      b->randomBonus();
		      this->_owner->addComponent(b);
		      break;
		    }
		  else if (col->colide(*c) && col != c)
		    {
		      ptr->setX(nx);
		      ptr->setY(ny);
		      ptr->setZ(nz);
		      return false;
		    }
		}
	    }
	  if (this->_owner)
	    this->_owner->hasBeenModify = true;
	  Trame trame(this->_owner->getId(), "has_move", this->_owner->getType(), "",
				      double_to_str(this->_owner->getId()), "");
	  Daemon::DaemonServer::sendq->push("0", trame.toString());
	  return true;
	}
      return false;
    }
  return false;
}

bool	Daemon::Move::move_to(double x, double y, double z, double dx, double dy, double dz, double speed, int iter)
{
  this->setToX(x);
  this->setToY(y);
  this->setToZ(z);
  this->setToDx(dx);
  this->setToDy(dy);
  this->setToDz(dz);
  this->setMoveSpeed(speed);
  this->_moving = true;
  this->_t.reset();
  this->_t.start();
  this->_iter = iter;
  this->_pivot = iter / 2;
  return true;
}

void	Daemon::Move::eventMove(Trame &trame)
{
  std::vector<std::string> v = split_string(trame.getArgument(), "|");

  this->move(str_to_double(v.at(0))
  	     , str_to_double(v.at(1))
  	     , str_to_double(v.at(2)), 20.0);
}

void	Daemon::Move::setToX(double x)
{
  this->_to_x = x;
}

void	Daemon::Move::setToY(double y)
{
  this->_to_y = y;
}
void	Daemon::Move::setToZ(double z)
{
  this->_to_z = z;
}

void	Daemon::Move::setToDx(double dx)
{
  this->_dx = dx;
}

void	Daemon::Move::setToDy(double dy)
{
  this->_dy = dy;
}

void	Daemon::Move::setToDz(double dz)
{
  this->_dz = dz;
}

void	Daemon::Move::setMoveSpeed(double move_speed)
{
  this->_move_speed = move_speed;
}

double	Daemon::Move::getToX() const
{
  return this->_to_x;
}

double	Daemon::Move::getToY() const
{
  return this->_to_y;
}

double	Daemon::Move::getToZ() const
{
  return this->_to_z;
}

double	Daemon::Move::getToDx() const
{
  return this->_dx;
}

double	Daemon::Move::getToDy() const
{
  return this->_dy;
}

double	Daemon::Move::getToDz() const
{
  return this->_dz;
}

double	Daemon::Move::getMoveSpeed() const
{
  return  this->_move_speed;
}

void	Daemon::Move::update()
{
  if (this->_moving && this->_t.isTimeOut(0.1))
    {
      Daemon::Position *ptr = dynamic_cast<Daemon::Position *>(this->_owner->getComponent("position"));
      if (ptr->getX() == this->getToX())
	this->setToDx(0.0);
      if (ptr->getY() == this->getToY())
	this->setToDy(0.0);
      if (ptr->getZ() == this->getToZ())
	this->setToDz(0.0);
      if (this->_iter <= 0 || (this->getToDx() + this->getToDy() + this->getToDz()) == 0)
	{
	  ptr->setZ(0);
	  this->_moving = false;
	}
      else
	{
	  this->setToDz(this->_pivot >= this->_iter ? -this->getToDz(): this->getToDz());
	  if (!this->move(this->getToDx(), this->getToDy(), this->getToDz(), this->getMoveSpeed()))
	    {
	      this->_moving = false;
	      ptr->setZ(0);
	    }
	}
      this->_iter--;
      this->_t.reset();
      this->_t.start();
    }
}

std::string			Daemon::Move::serialize()
{
  return this->createPackage(this->createData(double_to_str(this->getMoveSpeed())));
}

Daemon::Move		*Daemon::Move::unserialize(std::stringstream &s, GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new Move(owner);
}

Daemon::Move		*Daemon::Move::clone(GameObject *owner) const
{
  return new Move(owner);
}
