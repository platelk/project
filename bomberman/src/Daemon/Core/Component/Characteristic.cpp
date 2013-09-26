//
// Characteristic.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Characteristic.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 18:18:22 2013 kevin platel
// Last update Sat Jun  8 08:18:05 2013 alexis leprovost
//

#include "Characteristic.hh"

namespace Daemon
{
  const	std::string &	Characteristic::NAME = "characteristic";

  Characteristic::Characteristic(GameObject *owner, int resi, long dmg, double speed, double aspd, float strength, double range)
    : AComponent(Characteristic::NAME, "player", owner), _resi(resi), _dmg(dmg), _speed(speed), _aspd(aspd), _strength(strength), _range(range)
  {
  }

  Characteristic::~Characteristic()
  {
  }

  int	Characteristic::getResi() const
  {
    return this->_resi;
  }

  long	Characteristic::getDamage() const
  {
    return this->_dmg;
  }

  double	Characteristic::getSpeed() const
  {
    return this->_speed;
  }

  double	Characteristic::getASPD() const
  {
    return this->_aspd;
  }

  float	Characteristic::getStrength() const
  {
    return this->_strength;
  }

  double	Characteristic::getRange() const
  {
    return this->_range;
  }

  void		Characteristic::setResi(int resi)
  {
    if (resi <= 100 && resi >= -100)
      this->_resi = resi;
  }

  void		Characteristic::setDamage(long damage)
  {
    this->_dmg = damage;
  }

  void		Characteristic::setSpeed(double speed)
  {
    this->_speed = speed;
  }

  void		Characteristic::setASPD(double aspd)
  {
    if (aspd >= 0.0)
      this->_aspd = aspd;
  }

  void		Characteristic::setStrength(float strength)
  {
    if (strength >= 1)
      this->_strength = strength;
  }

  void		Characteristic::setRange(double range)
  {
    if (range >= 1.0)
      this->_range = range;
  }

  void		Characteristic::update()
  {
  }

  std::string	Characteristic::serialize()
  {
    return this->createPackage(this->createData(this->getResi())
			       + this->createData(static_cast<int>(this->getDamage()))
			       + this->createData(this->getSpeed())
			       + this->createData(this->getASPD())
			       + this->createData(this->getStrength())
			       + this->createData(this->getRange()));
  }

  Characteristic*	Characteristic::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;
    ss << this->unPack(s);
    return new Characteristic(owner, str_to_int(this->getData(ss)),
			      str_to_int(this->getData(ss)),
			      str_to_double(this->getData(ss)),
			      str_to_double(this->getData(ss)),
			      str_to_double(this->getData(ss)),
			      str_to_double(this->getData(ss)));
  }

  Characteristic*	Characteristic::clone(GameObject *owner) const
  {
    return new Characteristic(owner, this->_resi, this->_dmg, this->_speed, this->_aspd,
			      this->_strength, this->_range);
  }
}
