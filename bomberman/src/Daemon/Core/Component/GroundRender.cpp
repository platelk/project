//
// GroundRender.cpp for GroundRender in /home/guiho_r/depot/bomberman/src/Daemon/Core/Component
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// o
// Started on  Fri Jun  7 21:04:05 2013 ronan guiho
// Last update Sun Jun  9 12:54:03 2013 ronan guiho
//

#include <iostream>

#include "Position.hh"
#include "GroundRender.hh"
#include "GameObject.hh"

namespace Daemon
{

  std::string const	GroundRender::NAME = "groundRender";

  GroundRender::GroundRender(GameObject *owner, const std::string &name, const float width, const float heigth)
    : Render(owner, name, heigth * width), _heigth(heigth), _width(width)
  {
    this->setName(GroundRender::NAME);
  }

  GroundRender::~GroundRender()
  {
  }

  void GroundRender::initialize()
  {
    this->_texture = gdl::Image::load(this->_modelName);
    this->_init = true;
  }

  void GroundRender::update()
  {

  }

  void GroundRender::draw()
  {
    Daemon::Position *p = dynamic_cast<Daemon::Position*>(this->_owner->getComponent("position"));
    if (p)
      {
	glPushMatrix();
	glLoadIdentity();
	this->_texture.bind();
	if (this->_owner) {
	  for (int i = 0; i < this->_width; i += 512) {
	    for (int j = 0; j < this->_heigth; j += 512) {
	      glBegin(GL_QUADS);
	      glTexCoord2f(0.0f, 0.0f);
	      glVertex3f(p->getX() + i, 0, p->getY() + j + 530);

	      glTexCoord2f(0.0f, 1.0f);
	      glVertex3f(p->getX() + i, 0, p->getY() + j);

	      glTexCoord2f(1.0f, 1.0f);
	      glVertex3f(p->getX() + i + 530, 0, p->getY() + j);

	      glTexCoord2f(1.0f, 0.0f);
	      glVertex3f(p->getX() + i + 530, 0, p->getY() + j + 530);
	      glEnd();
	    }
	  }
	}
	glPopMatrix();
      }
  }

  std::string		GroundRender::serialize()
  {
    return this->createPackage(this->createData(this->_modelName)
			       + this->createData(this->_width)
			       + this->createData(this->_heigth));
  }

  GroundRender*		GroundRender::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;
    ss << this->unPack(s);

    return new GroundRender(owner, this->getData(ss), str_to_double(this->getData(ss)), str_to_double(this->getData(ss)));
  }

  GroundRender*		GroundRender::clone(Daemon::GameObject* owner) const
  {
    return new GroundRender(owner, this->getName(), this->_width, this->_heigth);
  }
}
