//
// Render.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Mon May 27 11:52:16 2013 alexis leprovost
// Last update Sun Jun  9 11:09:14 2013 alexis leprovost
//

#include <cmath>

#include "Characteristic.hh"
#include "Render.hh"
#include "Position.hh"
#include "Client/Core.hh"
#include "PlayerRender.hh"

#define ABS(x)	((x) > 0 ? (x) : ((x) * -1))

namespace Daemon
{
  std::string const	Render::NAME = "render";

  Render::Render(GameObject* owner, std::string const& name, float size)
    : AComponent(Render::NAME, Render::NAME, owner),
      _modelName(name),
      _size(size),
      _init(false),
      _anim(""),
      _speed(1.0),
      _update(false),
      _model(0)
  {
  }

  Render::~Render()
  {
  }

  std::string const&	Render::getModelName() const
  {
    return (this->_modelName);
  }

  void			Render::setModelName(std::string const& name)
  {
    this->_modelName = name;
  }

  void			Render::setSize(float size)
  {
    this->_size = size;
  }

  float			Render::getSize() const
  {
    return (this->_size);
  }

  bool			Render::isInit() const
  {
    return (this->_init);
  }

  void			Render::initialize()
  {
    if (!this->_init && this->_modelName != "")
      {
	this->_init = true;
	this->_model = &Client::Core::modelManager.get(this->_modelName);
	this->_update = true;
      }
  }

  void			Render::update()
  {
    if (this->_init && this->_update)
      {
	this->_update = false;
	Client::Core::modelManager.get(this->_modelName).update(*Client::Core::gameClock);
      }
  }

  void			Render::draw()
  {
    if (this->_init && this->_owner)
      {
	Position*	position = dynamic_cast<Position*>(this->_owner->getComponent(Position::NAME));
	if (position)
	  {
	    glPushMatrix();
	    glLoadIdentity();
	    glTranslatef(position->getX(), position->getZ(), position->getY());
	    float  angle = atan(ABS(position->getDy()) / ABS(position->getDx()));
	    angle = (angle * 180.0f) / M_PI;
	    if (position->getDy() > 0 && position->getDx() > 0)
	      angle = 360 - angle;
	    else if (position->getDy() < 0 && position->getDx() < 0)
	      angle = 180.0f - angle;
	    else if (position->getDy() > 0 && position->getDx() < 0)
	      angle += 180.0;
	    else
	      angle = angle;
	    angle = static_cast<int>(angle + 90) % 360;
	    glRotatef(angle, 0.0f, 1.0f, 0.0f);
	    glScalef(this->_size, this->_size, this->_size);
	    this->_model->draw();
	    glPopMatrix();
	  }
	this->_update = true;
      }
  }

  Render*		Render::clone(Daemon::GameObject* owner) const
  {
    return (new Render(owner, this->getModelName(), this->getSize()));
  }

  std::string		Render::serialize()
  {
    return (this->createPackage(this->createData(this->getModelName()) +
				this->createData(this->getSize())));
  }

  AComponent*		Render::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;

    ss << this->unPack(s);
    return (new Render(owner, this->getData(ss), str_to_double(this->getData(ss))));
  }
}
