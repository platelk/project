#include "ThrowBomb.hh"
#include "Move.hh"
#include "Characteristic.hh"
#include "Colider.hh"
#include "Store.hh"

const std::string Daemon::ThrowBomb::NAME = "throw_bomb";

Daemon::ThrowBomb::ThrowBomb(GameObject *owner, double recover)
  : AComponent(ThrowBomb::NAME, "", owner), _recover(recover)
{
  this->_t.start();
  this->_t_st.start();
  if (owner)
    {
      owner->addEvent("throw_bomb", new Action<ThrowBomb>(*this, &Daemon::ThrowBomb::eventThrowBomb));
      this->_isInit = true;
    }
}

Daemon::ThrowBomb::~ThrowBomb()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("throw_bomb");
    }
}

void	Daemon::ThrowBomb::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("throw_bomb", new Action<ThrowBomb>(*this, &Daemon::ThrowBomb::eventThrowBomb));
      this->_isInit = true;
      this->_t.start();
      this->_t_st.start();
    }
}

void	Daemon::ThrowBomb::throwBomb(double dx, double dy, double dz, double f)
{
  Bomb	*bomb = new Bomb(this->_owner);
  Daemon::Position *ptr = dynamic_cast<Daemon::Position *>(this->_owner->getComponent("position"));
  Daemon::Position *ptr_bomb = dynamic_cast<Daemon::Position *>(bomb->getComponent("position"));
  Daemon::Move *move_bomb = dynamic_cast<Daemon::Move *>(bomb->getComponent("move"));

  if (ptr && ptr_bomb)
    {
      this->_t.reset();
      this->_t.start();
      Daemon::Colider *col = dynamic_cast<Daemon::Colider *>(bomb->getComponent(Daemon::Colider::NAME));
      Daemon::Colider *col_obj = dynamic_cast<Daemon::Colider *>(this->_owner->getComponent(Daemon::Colider::NAME));

      double	new_x = ptr->getX() + (dx * 1 * (col->getSize(0) + col_obj->getSize(0)));
      double	new_y = ptr->getY() + (dy * 1 * (col->getSize(0) + col_obj->getSize(0)));
      double	new_z = ptr->getZ() + (dz * 1 * (col->getSize(0) + col_obj->getSize(0)));

      ptr_bomb->setX(new_x);
      ptr_bomb->setY(new_y);
      ptr_bomb->setZ(new_z);
      this->_owner->addChild(bomb);
      bomb->setParent(this->_owner);
      bomb->init();
      f = f / 1.42;
      if (!move_bomb->move(dx, dy, dz, 0))
	{
	  Daemon::EventTree::core->removeEntity(bomb);
	  (this->_owner)->toDelete(bomb);
	}
      else
	{
	  Trame t(bomb->getId(), "tile", bomb->getType(), "", int_to_str(this->_owner->getId()), bomb->serialize());
	  Daemon::DaemonServer::sendq->push("0", t.toString());
	  t.setArgument("");
	  Trame t2(this->_owner->getId(), "tile", this->_owner->getType(), "", int_to_str(this->_owner->getId()), "");
	  t2.setEvent("has_throw_bomb");
	  Daemon::DaemonServer::sendq->push("0", t2.toString());
	  new_x = ptr->getX() + (dx * f * (col->getSize(0) + col_obj->getSize(0)));
	  new_y = ptr->getY() + (dy * f * (col->getSize(0) + col_obj->getSize(0)));
	  new_z = 60;
	  move_bomb->move_to(new_x, new_y, new_z, dx, dy, 0.4, 50*f + 90.0, ((50*f + (col->getSize(0) + col_obj->getSize(0))) / 90.0));
	}
    }
  else
    {
      Daemon::EventTree::core->removeEntity(bomb);
      (this->_owner->getParent())->toDelete(this->_owner);
    }
}

void	Daemon::ThrowBomb::eventThrowBomb(Trame &trame)
{
  std::vector<std::string> v = split_string(trame.getArgument(), "|");
  double	recover = 0.0;

  if (this->_owner && this->_owner->haveComponent(Characteristic::NAME))
    {
      recover = dynamic_cast<Daemon::Characteristic *>(this->_owner->getComponent(Characteristic::NAME))->getASPD();
    }
  if (this->_t.isTimeOut(recover))
    {
      this->_t.reset();
      this->_t.start();
      Daemon::Store *st = dynamic_cast<Daemon::Store *>(this->_owner->getComponent(Daemon::Store::NAME));
      if (st && st->take("bomb", 1))
	{
	  this->throwBomb(str_to_double(v.at(0))
			  , str_to_double(v.at(1))
			  , str_to_double(v.at(2))
			  , str_to_double(v.at(3)));
	}
      else if (!st)
	{
	  this->throwBomb(str_to_double(v.at(0))
			  , str_to_double(v.at(1))
			  , str_to_double(v.at(2))
			  , str_to_double(v.at(3)));
	}
    }

}

void	Daemon::ThrowBomb::update()
{
  if (this->_owner && this->_owner->haveComponent(Daemon::Store::NAME) && this->_t_st.isTimeOut(10))
    {
      Daemon::Store *st = dynamic_cast<Daemon::Store *>(this->_owner->getComponent(Daemon::Store::NAME));
      st->store("bomb", 1);
      this->_t_st.reset();
      this->_t_st.start();
    }
}

Daemon::ThrowBomb*	Daemon::ThrowBomb::clone(GameObject *owner) const
{
  return  new ThrowBomb(owner, this->_recover);
}

std::string	Daemon::ThrowBomb::serialize()
{
  return this->createPackage(this->createData(this->_recover));
}

Daemon::ThrowBomb*	Daemon::ThrowBomb::unserialize(std::stringstream &s, GameObject *owner)
{
	std::stringstream ss;
	ss << this->unPack(s);
	return new ThrowBomb(owner, str_to_double(this->getData(ss)));
}

double	Daemon::ThrowBomb::getRecover() const
{
  return this->_recover;
}
