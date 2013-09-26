#include "Life.hh"
#include "Position.hh"
#include "Characteristic.hh"
#include "Colider.hh"
#include "Explose.hh"
#include "BonusBox.hh"
#include "Bonus.hh"
#include "BonusSpawn.hh"
#include "BonusRender.hh"

const	std::string	Daemon::Life::NAME = "life";

Daemon::Life::Life(GameObject *owner, size_t current_hp, size_t max_hp)
  : AComponent(Life::NAME, "player", owner), _hp(current_hp), _max_hp(max_hp), _canTakeDamage(true)
{
  this->_coefficient = 1;
  if (owner)
    {
      owner->addEvent("take_dmg", new Action<Life>(*this, &Daemon::Life::eventTakeDamage));
      owner->addEvent("healt_dmg", new Action<Life>(*this, &Daemon::Life::eventHealtDamage));
      owner->addEvent("bomb_explose", new Action<Life>(*this, &Daemon::Life::eventBombExplod));
      owner->addEvent("die", new Action<Life>(*this, &Daemon::Life::eventDie));
      this->_isInit = true;
    }
}

Daemon::Life::~Life()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("take_dmg");
      this->_owner->removeEvent("healt_dmg");
      this->_owner->removeEvent("bomb_explose");
      this->_owner->addEvent("die", new Action<Life>(*this, &Daemon::Life::eventDie));
    }
}

void	Daemon::Life::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("take_dmg", new Action<Life>(*this, &Daemon::Life::eventTakeDamage));
      this->_owner->addEvent("healt_dmg", new Action<Life>(*this, &Daemon::Life::eventHealtDamage));
      this->_owner->addEvent("bomb_explose", new Action<Life>(*this, &Daemon::Life::eventBombExplod));
      this->_owner->addEvent("die", new Action<Life>(*this, &Daemon::Life::eventDie));
      this->_isInit = true;
    }
}

size_t	Daemon::Life::getLife() const
{
  return this->_hp;
}

size_t	Daemon::Life::getMaxLife() const
{
  return this->_max_hp;
}


void	Daemon::Life::setCurrentHP(size_t current_hp)
{
  this->_hp = current_hp;
}

void	Daemon::Life::setMaxHp(size_t max_hp)
{
  this->_max_hp = max_hp;
}

void	Daemon::Life::dmgMode()
{
  this->_coefficient = 1;
}

void	Daemon::Life::healMode()
{
  this->_coefficient = -1;
}

void	Daemon::Life::takeDamage(size_t dmg)
{
  if (this->_hp == 0 || !this->_canTakeDamage)
    return ;
  else if (dmg >= this->_hp)
    {
      if (Daemon::EventTree::root)
	{
	  if ((this->_owner)->haveComponent(Daemon::Explose::NAME))
	    {
	      Daemon::Explose *ptr = dynamic_cast<Daemon::Explose *>(this->_owner->getComponent(Daemon::Explose::NAME));
	      ptr->explod();
	    }
	  if (Daemon::EventTree::root && this->_owner && this->_owner->haveComponent(Daemon::BonusSpawn::NAME))
	    {
	      Daemon::Position *pos = dynamic_cast<Position *>(this->_owner->getComponent(Position::NAME));
	      BonusBox *box = new BonusBox(this->_owner->getParent(), "", pos->getX(), pos->getY(), pos->getZ(), 100.0);
	  box->hasBeenModify = true;
	  Trame t(box->getId(), "tile", box->getType(), "", int_to_str(this->_owner->getId()), box->serialize());
	  Daemon::DaemonServer::sendq->push("0", t.toString());
	    }
	  Daemon::Trame *trame = new Trame("");
	  trame->init(this->_owner->getId(), "die", this->getName(), "", int_to_str(this->_owner->getId()), "");
	  Daemon::DaemonServer::sendq->push("0", trame->toString());
	  Daemon::EventTree::pushEvent(trame);

	}
      this->_hp = 0;
    }
  else
    {
      int	coef = 0;
      if (this->_owner->haveComponent(Daemon::Characteristic::NAME))
	{
	  coef = (dynamic_cast<Daemon::Characteristic *>(this->_owner->getComponent(Daemon::Characteristic::NAME)))->getResi();
	}
      if (this->_canTakeDamage)
	{
	  this->_hp -= this->_coefficient * ((dmg - dmg * (static_cast<float>(coef) / 100.0)));
	  if (this->_owner)
	    this->_owner->hasBeenModify = true;
	}
    }
}

void	Daemon::Life::damage(bool can)
{
  this->_canTakeDamage = can;
}

bool	Daemon::Life::canTakeDamage() const
{
  return this->_canTakeDamage;
}

void	Daemon::Life::die()
{
  if (this->_owner)
    {
      this->_owner->clearEvent();
      if (Daemon::EventTree::root && this->_owner && this->_owner->getParent())
	(this->_owner->getParent())->removeChild(this->_owner);
    }
  Daemon::EventTree::core->removeEntity(this->_owner);
}

void	Daemon::Life::eventDie(Trame &)
{
  this->die();
}

void	Daemon::Life::healtDamage(size_t dmg)
{
  this->_hp += dmg;
  if (this->_owner)
    this->_owner->hasBeenModify = true;
}

void	Daemon::Life::bombExplod(int x, int y, int, int strength, int dmg)
{
  if (this->_owner)
    {
      Daemon::Position *p = dynamic_cast<Daemon::Position *>(this->_owner->getComponent("position"));
      Daemon::Colider col(0);
      Daemon::Colider colSecond(0);
      Daemon::Colider *colider = dynamic_cast<Daemon::Colider *>(this->_owner->getComponent(Daemon::Colider::NAME));
      col.addCircle(x, y, strength);
      colSecond.addCircle(p->getX(), p->getY(), 1);
      if (colider && ((colider->colide(col))))
	{
	  this->takeDamage(dmg);
	}
    }
}

size_t	Daemon::Life::currentHealt() const
{
	return this->_hp;
}

void	Daemon::Life::eventTakeDamage(Trame &trame)
{
	this->takeDamage(str_to_int(trame.getArgument()));
}

void	Daemon::Life::eventHealtDamage(Trame &trame)
{
	this->healtDamage(str_to_int(trame.getArgument()));
}

void	Daemon::Life::eventBombExplod(Trame &trame)
{
	std::vector<std::string> v = split_string(trame.getArgument(), "|");

	this->bombExplod(str_to_double(v.at(0)), str_to_double(v.at(1)),
			 str_to_double(v.at(2)), str_to_int(v.at(3)), str_to_int(v.at(4)));
}

void	Daemon::Life::update()
{
	Daemon::AComponent::update();
}

std::string	Daemon::Life::serialize()
{
  return this->createPackage(this->createData(static_cast<int>(this->_hp)) + this->createData(static_cast<int>(this->_max_hp)));
}

Daemon::AComponent*	Daemon::Life::unserialize(std::stringstream &s, GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new Life(owner, str_to_int(this->getData(ss)), str_to_int(this->getData(ss)));
}

Daemon::Life *	Daemon::Life::clone(Daemon::GameObject *owner) const
{
  return (new Life(owner, this->currentHealt(), this->_max_hp));
}
