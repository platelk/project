//
// DispersalEffect.cpp for DispersalEffect.cpp in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Component
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sat Jun  8 17:02:11 2013 ronan guiho
// Last update Sat Jun  8 17:14:19 2013 ronan guiho
//

#include "ObjectCreation.hh"
#include "Position.hh"
#include "Update.hh"

#include "DispersalRender.hh"
#include "DispersalEffect.hh"

const std::string DispersalEffect::NAME = "dispersalEffect";

DispersalEffect::DispersalEffect(Listener *parent, const std::string &, const int x, const int y,
				 const int z, const int count, const double size, const std::string &texture)
  : GameObject(DispersalEffect::NAME, parent)
{
  this->addComponent(new Daemon::Position(this, x, y, z));
  this->addComponent(new Daemon::DispersalRender(this, "", size, count, texture));
}

DispersalEffect::DispersalEffect(Listener *parent, const std::string &, const int x, const int y,
				 const int z, const int count, const double size, const Vector color)
  : GameObject(DispersalEffect::NAME, parent)
{
  this->addComponent(new Daemon::Position(this, x, y, z));
  this->addComponent(new Daemon::DispersalRender(this, "", size, count, color));
}

DispersalEffect::~DispersalEffect()
{

}

DispersalEffect *DispersalEffect::clone(Listener *owner) const
{
  DispersalEffect *obj = new DispersalEffect(owner, "", 0, 0, 0, 0, 0.0f, "");

  std::map<std::string, Daemon::AComponent *>::const_iterator it = this->_component.begin();
  if (this->_component.size())
    {
      while (it != this->_component.end())
	obj->addComponent((it->second)->clone(obj));
      it++;
    }
  return (obj);
}
