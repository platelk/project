//
// LevelUp.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/LevelUp.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 21:40:57 2013 kevin platel
// Last update Fri Jun  7 11:29:43 2013 phalip_z
//

#include "LevelUp.hh"
#include "Characteristic.hh"
#include "Render.hh"

namespace Daemon
{
  const std::string	& LevelUp::NAME = "level_up";

  LevelUp::LevelUp(GameObject *owner)
    : AComponent(LevelUp::NAME, "player", owner)
  {
    if (owner)
      {
	owner->addEvent("spell", new Action<LevelUp>(*this, &Daemon::LevelUp::eventLevelUp));
	// Add to each component
	this->_isInit = true;
      }
    this->_hasLaunched = false;
  }

  LevelUp::~LevelUp()
  {
    // Add to each component
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("spell");
      }
  }

  void	LevelUp::init()
  {
    // Add to each component
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("spell", new Action<LevelUp>(*this, &Daemon::LevelUp::eventLevelUp));
	// Add to each component
	this->_isInit = true;
      }
    this->_t.start();
  }

  void	LevelUp::spellLevelUp()
  {
    if (this->_owner && this->_t.isTimeOut(30))
      {
	Characteristic *charac = dynamic_cast<Characteristic *>(this->_owner->getComponent(Characteristic::NAME));
	Render		*render = dynamic_cast<Render *>(this->_owner->getComponent(Render::NAME));

	if (charac && render)
	  {
	    this->_resi = charac->getResi();
	    this->_dmg = charac->getDamage();
	    this->_speed = charac->getSpeed() * 0.5;
	    this->_aspd = charac->getASPD();
	    this->_strength = charac->getStrength();
	    this->_range = charac->getRange();

	    charac->setResi(charac->getResi() * 2);
	    charac->setDamage(charac->getDamage() * 2);
	    charac->setSpeed(charac->getSpeed() * 0.5);
	    charac->setASPD(charac->getASPD() * 2);
	    charac->setStrength(charac->getStrength() * 2);
	    charac->setRange(charac->getRange() * 2);

	    this->_t.reset();
	    this->_t.start();
	    this->_laps.start();
	    this->_hasLaunched = true;
	    this->_owner->hasBeenModify = true;
	  }
      }
  }

  void	LevelUp::eventLevelUp(Trame &)
  {
    this->spellLevelUp();
  }

  void	LevelUp::update()
  {
    if (this->_owner && this->_hasLaunched && this->_laps.isTimeOut(10))
      {
	Characteristic *charac = dynamic_cast<Characteristic *>(this->_owner->getComponent(Characteristic::NAME));
	Render		*render = dynamic_cast<Render *>(this->_owner->getComponent(Render::NAME));

	if (charac && render)
	  {
	    charac->setResi(charac->getResi() - this->_resi);
	    charac->setDamage(charac->getDamage() - this->_dmg);
	    charac->setSpeed(charac->getSpeed() + this->_speed);
	    charac->setASPD(charac->getASPD() - this->_aspd);
	    charac->setStrength(charac->getStrength() - this->_strength);
	    charac->setRange(charac->getRange() - this->_range);

	    this->_t.reset();
	    this->_t.start();
	    this->_laps.reset();
	    this->_hasLaunched = false;
	    this->_owner->hasBeenModify = true;
	  }
      }
  }

  std::string	LevelUp::serialize()
  {
    return this->createPackage("");
  }

  LevelUp*	LevelUp::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new LevelUp(owner);
  }

  LevelUp*	LevelUp::clone(GameObject *owner) const
  {
    return new LevelUp(owner);
  }
}
