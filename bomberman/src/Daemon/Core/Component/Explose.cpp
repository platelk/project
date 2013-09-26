#include "Position.hh"
#include "Explose.hh"
#include "DeleteBuff.hh"
#include "Characteristic.hh"
#include "DispersalEffect.hh"
#include "Tools/Vector.hh"
#include "Client/Core.hh"

const std::string	Daemon::Explose::NAME = "explose";

Daemon::Explose::Explose(GameObject *owner, double timeout, int strength, int dmg)
  : AComponent(Explose::NAME, "bomb", owner), _timeout(timeout), _strength(strength), _dmg(dmg)
{
  if (this->_owner)
    {
      this->_owner->addEvent("cmd_explose", new Action<Explose>(*this, &Daemon::Explose::eventExplod));
      this->_isInit = true;
    }
}

Daemon::Explose::~Explose()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("cmd_explose");
    }
}

void	Daemon::Explose::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("cmd_explose", new Action<Explose>(*this, &Daemon::Explose::eventExplod));
      this->_isInit = true;
    }
  this->_time.start();
}

double		Daemon::Explose::getTimeOut() const
{
  return this->_timeout;
}

int			Daemon::Explose::getStrength() const
{
  long	d = 0;

  if (this->_owner && this->_owner->haveComponent(Characteristic::NAME))
    {
      d = dynamic_cast<Daemon::Characteristic *>(this->_owner->getComponent(Characteristic::NAME))->getDamage();
    }
  return (this->_strength + d);
}

void	Daemon::Explose::eventExplod(Trame &)
{
  this->explod();
}

void	Daemon::Explose::explod()
{
  if (this->_owner == 0)
    return ;
  Daemon::Position *p = dynamic_cast<Daemon::Position *>(this->_owner->getComponent("position"));
  if (Daemon::EventTree::root == 0)
    {
      Client::Core::sounds.getSound("bomb")->play();
    }
  if (p)
    {
      if (Daemon::EventTree::root)
	{
	  DispersalEffect *obj = new DispersalEffect((this->_owner)->getParent(), "", p->getX(), p->getZ(), p->getY(), 2000, 100, Vector(255, 0, 0));
	  Trame t(obj->getId(), "tile", obj->getType(), "", int_to_str(this->_owner->getId()), obj->serialize());
	  Daemon::DaemonServer::sendq->push("0", t.toString());
	}
      if (Daemon::EventTree::root)
	{
	  int	id = this->_owner->getId();
	  std::string strength = int_to_str(this->getStrength());
	  Daemon::EventTree::pushEvent(new Daemon::Trame(id,
							 "bomb_explose",
							 "",
							 "",
							 "",
							 p->getStrPos() + "|" + strength + "|" + int_to_str(this->_dmg)));
	  (this->_owner->getParent())->toDelete(this->_owner);
	}
      Daemon::EventTree::core->removeEntity(this->_owner);
    }
}

void	Daemon::Explose::update()
{
  if (this->_time.isTimeOut(this->_timeout))
    {
      this->explod();
    }
}

std::string	Daemon::Explose::serialize()
{
  return this->createPackage(this->createData(this->_timeout) + this->createData(this->_strength) + this->createData(this->_dmg));
}

Daemon::Explose*	Daemon::Explose::unserialize(std::stringstream &s, GameObject *owner)
{
  std::stringstream ss;

  ss << this->unPack(s);
  return (new Explose(owner, str_to_double(this->getData(ss)), str_to_int(this->getData(ss)), str_to_int(this->getData(ss))));
}

Daemon::Explose		*Daemon::Explose::clone(GameObject *owner) const
{
  return new Explose(owner, this->getTimeOut(), this->getStrength(), this->_dmg);
}
