//
// Ground.cpp for Ground in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 18:15:26 2013 ronan guiho
// Last update Sun Jun  9 02:08:22 2013 ronan guiho
//

#include "ObjectCreation.hh"
#include "Position.hh"
#include "Network.hh"
#include "Update.hh"

#include "Ground.hh"

const std::string Ground::NAME = "ground";

Ground::Ground(Listener *parent, const std::string &, const int x, const int y,
	       const int z, const int, const std::string &)
  : GameObject(Ground::NAME, parent)
{
  this->addComponent(new Daemon::Position(this, x, y, z));
}


Ground::~Ground()
{

}

Ground *Ground::clone(Listener *owner) const
{
  Ground *obj = new Ground(owner);

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
