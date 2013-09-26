//
// Recover.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Recover.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 20:28:43 2013 kevin platel
// Last update Mon Jun  3 20:59:06 2013 kevin platel
//

#include "Characteristic.hh"
#include "Recover.hh"
#include "Store.hh"

namespace Daemon
{
  const std::string &Recover::NAME = "recover";

  Recover::Recover(GameObject *owner, double recover)
    : AComponent(Recover::NAME, "", owner), _recover(recover)
  {
  }

  Recover::~Recover()
  {
  }

  void		Recover::init()
  {
    this->_t.start();
  }

  double	Recover::getRecover() const
  {
    return this->_recover;
  }

  void		Recover::setRecover(double recover)
  {
    this->_recover = recover;
  }

  void		Recover::update()
  {
    if (this->_t.isTimeOut(this->_recover) && this->_owner && this->_owner->haveComponent(Store::NAME))
      {
	Store *s = dynamic_cast<Store *>(this->_owner->getComponent(Store::NAME));
	if (s->haveStock("bomb"))
	  {
	    s->store("bomb", 1);
	  }
	this->_t.reset();
      }
  }

  std::string	Recover::serialize()
  {
    return this->createPackage(this->createData(this->getRecover()));
  }

  Recover	*Recover::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;
    ss << this->unPack(s);

    return new Recover(owner, str_to_double(this->getData(ss)));
  }

  Recover	*Recover::clone(GameObject *owner) const
  {
    return new Recover(owner);
  }
}
