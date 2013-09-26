//
// BonusRender.cpp for BonusRender in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Component
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sun Jun  9 01:06:08 2013 ronan guiho
// Last update Sun Jun  9 21:38:02 2013 kevin platel
//

#include <iostream>

#include "Position.hh"
#include "BonusRender.hh"
#include "GameObject.hh"

namespace Daemon
{
  std::string const BonusRender::NAME = "bonusRender";
  BonusRender::BonusRender(GameObject *owner, const std::string &name, const float size,
			   const std::string &texture, const bool)
    : Render(owner, name, size), _size(size), _path_texture(texture)
  {
    this->setName(BonusRender::NAME);
  }

  BonusRender::~BonusRender()
  {
  }

  void BonusRender::initialize()
  {
    if (this->_path_texture != "")
      this->_texture = gdl::Image::load(this->_path_texture);
    this->_init = true;

    this->_rot.x = 0;
    this->_rot.y = 0;
    this->_rot.z = 0;

    this->_speed.x = (rand() % 5);
    this->_speed.y = (rand() % 5);
    this->_speed.z = (rand() % 5);

    this->_swipe = (rand() % 8) + 2;

    Daemon::Position *p = dynamic_cast<Daemon::Position*>(this->_owner->getComponent("position"));
    if (p)
      {
	this->_pos.x = p->getX();
	this->_pos.y = (this->_size / 2) + p->getZ();
	this->_depth = this->_pos.y;
	this->_pos.z = p->getY();
      }
  }

  void BonusRender::update()
  {
    this->_rot.x += this->_speed.x;
    this->_rot.x = static_cast<int>(this->_rot.x) % 360;

    this->_rot.y += this->_speed.y;
    this->_rot.y = static_cast<int>(this->_rot.y) % 360;

    this->_rot.z += this->_speed.z;
    this->_rot.z = static_cast<int>(this->_rot.z) % 360;

    this->_pos.y += this->_swipe;
    if ((this->_pos.y > this->_depth + (this->_size * 2.0)) ||
	(this->_pos.y < this->_depth))
      this->_swipe *= -1;
  }

  void BonusRender::draw()
  {
    glPushMatrix();
    glLoadIdentity();

    this->_texture.bind();

    glTranslatef(this->_pos.x, this->_pos.y, this->_pos.z);
    glRotatef(this->_rot.z, 0.0f, 0.0f, 1.0f);
    glRotatef(this->_rot.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->_rot.x, 1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->_size, -this->_size, this->_size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(this->_size, -this->_size, this->_size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(this->_size,  this->_size,  this->_size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->_size,  this->_size,  this->_size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->_size, -this->_size, -this->_size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->_size,  this->_size, -this->_size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( this->_size,  this->_size, -this->_size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( this->_size, -this->_size, -this->_size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->_size,  this->_size, -this->_size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->_size,  this->_size,  this->_size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( this->_size,  this->_size,  this->_size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( this->_size,  this->_size, -this->_size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->_size, -this->_size, -this->_size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( this->_size, -this->_size, -this->_size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( this->_size, -this->_size,  this->_size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->_size, -this->_size,  this->_size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( this->_size, -this->_size, -this->_size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( this->_size,  this->_size, -this->_size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( this->_size,  this->_size,  this->_size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( this->_size, -this->_size,  this->_size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->_size, -this->_size, -this->_size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->_size, -this->_size,  this->_size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->_size,  this->_size,  this->_size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->_size,  this->_size, -this->_size);
    glEnd();
    glPopMatrix();
  }

  std::string		BonusRender::serialize()
  {
    return this->createPackage(this->createData(this->_size) + this->createData(this->_path_texture));
  }

  BonusRender*		BonusRender::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;
    ss << this->unPack(s);

    return new BonusRender(owner, "", str_to_double(this->getData(ss)), this->getData(ss));
  }

  BonusRender*		BonusRender::clone(Daemon::GameObject* owner) const
  {
    return new BonusRender(owner, this->getModelName(), this->_size, this->_path_texture);
  }
}
