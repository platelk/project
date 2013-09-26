//
// Box.cpp for Box in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sat Jun  8 23:51:57 2013 ronan guiho
// Last update Sun Jun  9 10:33:19 2013 kevin platel
//

#include "Box.hh"
#include "Position.hh"
#include "Colider.hh"

const std::string Box::NAME = "box";

Box::Box(Listener *parent, const std::string &, const int x, const int y, const int z,
	 const float size)
  : GameObject(Box::NAME, parent)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, size);

  this->addComponent(new Daemon::Position(this, x, y, z));
  this->addComponent(ptr);
}

Box::~Box()
{

}

Box *Box::clone(Listener *owner) const
{
  Box *obj = new Box(owner, "", 0, 0, 0, 0);

  std::map<std::string, Daemon::AComponent *>::const_iterator it = this->_component.begin();
  if (this->_component.size())
    {
      while (it != this->_component.end())
	{
	  obj->addComponent((it->second)->clone(obj));
	  it++;
	}
    }
  return (obj);
}
