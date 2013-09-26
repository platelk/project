//
// Bonus.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Bonus.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sat Jun  8 11:36:09 2013 kevin platel
// Last update Sun Jun  9 20:13:21 2013 kevin platel
//

#include "Bonus.hh"

namespace Daemon
{
  const std::string & Bonus::NAME = "bonus";

  Bonus::Bonus(GameObject *owner)
    : AComponent(Bonus::NAME, "", owner)
  {
    this->_func["resi"] = &Bonus::applyResi;
    this->_func["speed"] = &Bonus::applySpeed;
    this->_func["aspd"] = &Bonus::applyASPD;
    this->_func["strength"] = &Bonus::applyStrength;
    this->_func["range"] = &Bonus::applyRange;
  }

  Bonus::~Bonus()
  {
  }

  void			Bonus::randomBonus()
  {
    std::map<std::string, void (Bonus::*)()>::iterator it = this->_func.begin();

    int nb = rand() % this->_func.size();

    while (nb)
      {
	it++;
	nb--;
      }
    this->applyBonus(it->first);
  }

  Characteristic*	Bonus::getCharac()
  {
    if (this->_owner && this->_owner->haveComponent(Characteristic::NAME))
      {
	return dynamic_cast<Characteristic *>(this->_owner->getComponent(Characteristic::NAME));
      }
    return 0;
  }

  void	Bonus::init()
  {
  }

  void	Bonus::applyResi()
  {
    Characteristic *charac = this->getCharac();
    if (charac)
      {
	charac->setResi(charac->getResi() + (this->_isActive ? 10 : -10));
      }
  }

  void	Bonus::applySpeed()
  {
    Characteristic *charac = this->getCharac();
    if (charac)
      {
	charac->setSpeed(charac->getSpeed() + (this->_isActive ? 1 : -1));
      }
  }

  void	Bonus::applyASPD()
  {
    Characteristic *charac = this->getCharac();
    if (charac)
      {
	charac->setResi(charac->getResi() + (this->_isActive ? 1 : -1));
      }
  }

  void	Bonus::applyStrength()
  {
    Characteristic *charac = this->getCharac();
    if (charac)
      {
	charac->setResi(charac->getResi() + (this->_isActive ? 5 : -5));
      }
  }

  void	Bonus::applyRange()
  {
    Characteristic *charac = this->getCharac();
    if (charac)
      {
	charac->setResi(charac->getResi() + (this->_isActive ? 300 : -300));
      }
  }

  void	Bonus::applyBonus(const std::string &name)
  {
    this->_isActive = true;
    this->_t.reset();
    this->_t.start();
    this->_bonus_name = name;
    (this->*(this->_func[this->_bonus_name]))();
  }

  void	Bonus::update()
  {
    if (this->_isActive && this->_t.isTimeOut(5))
      {
	this->_isActive = false;
	(this->*(this->_func[this->_bonus_name]))();
      }
  }

  std::string	Bonus::serialize()
  {
    return this->createPackage("");
  }

  Bonus*	Bonus::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Bonus(owner);
  }

  Bonus*	Bonus::clone(Daemon::GameObject *owner) const
  {
    return new Bonus(owner);
  }
}
