//
// Particle.cpp for Particle in /home/guiho_r/depot/particule_engine/src
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Wed Jun  5 18:31:46 2013 ronan guiho
// Last update Sun Jun  9 11:55:25 2013 ronan guiho
//

#include <cstdlib>
#include <iostream>

#include "GL/gl.h"

#include "Particle.hh"
#include "DispersalRender.hh"

Particle::Particle(const Vector &pos, const Vector &dir, const Vector &rot,
		   const Vector &gravity, const Vector &speed,
		   const float life, const float fade, const float size,
		   const Pattern pattern, const gdl::Image &texture)
  : _pos(pos.x, pos.y, pos.z), _dir(dir.x, dir.y, dir.z), _rot(rot.x, rot.y, rot.z),
    _gravity(gravity.x, gravity.y, gravity.z), _speed(speed.x, speed.y, speed.z),
    _life(life), _fade(fade), _alive(false), _size(size, size, size),
    _pattern(pattern), _texture(texture), _path_texture("copy")
{
}

Particle::Particle(const Vector &pos, const Vector &dir, const Vector &rot,
		   const Vector &gravity, const Vector &speed,
		   const float life, const float fade, const float size,
		   const Pattern pattern, const Vector &color)
  : _pos(pos.x, pos.y, pos.z), _dir(dir.x, dir.y, dir.z), _rot(rot.x, rot.y, rot.z),
    _gravity(gravity.x, gravity.y, gravity.z), _speed(speed.x, speed.y, speed.z),
    _life(life), _fade(fade), _alive(false), _size(size, size, size), _color(color.x, color.y, color.z),
    _pattern(pattern), _path_texture("")
{
}

Particle::Particle(const Particle &p)
  : _pos(p.getPosition().x, p.getPosition().y, p.getPosition().z),
    _dir(p.getDirection().x, p.getDirection().y, p.getDirection().z),
    _rot(p.getRotation().x, p.getRotation().y, p.getRotation().z),
    _gravity(p.getGravity().x, p.getGravity().y, p.getGravity().z),
    _speed(p.getSpeed().x, p.getSpeed().y, p.getSpeed().z),
    _life(p.getLife()), _fade(p.getFade()), _alive(p.isAlive()),
    _size(p.getSize().x, p.getSize().y, p.getSize().z),
    _color(p.getColor().x, p.getColor().y, p.getColor().z),
    _pattern(p.getPattern()), _path_texture(p.getPathTexture())
{
}

void Particle::reset(const Particle &p)
{
  this->_pos.x = p.getDirection().x;
  this->_pos.y = p.getDirection().y;
  this->_pos.z = p.getDirection().z;
  this->_dir.x = p.getDirection().x;
  this->_dir.y = p.getDirection().y;
  this->_dir.z = p.getDirection().z;
  this->_rot.x = p.getRotation().x;
  this->_rot.y = p.getRotation().y;
  this->_rot.z = p.getRotation().z;
  this->_gravity.x = p.getGravity().x;
  this->_gravity.y = p.getGravity().y;
  this->_gravity.z = p.getGravity().z;
  this->_speed.x = p.getSpeed().x;
  this->_speed.y = p.getSpeed().y;
  this->_speed.z = p.getSpeed().z;
  this->_life = p.getLife();
  this->_alive = true;
  this->_fade = p.getFade();
}

void Particle::setPosition(const Vector &pos)
{
  this->_pos.x = pos.x;
  this->_pos.z = pos.y;
  this->_pos.z = pos.y;
}

const Vector &Particle::getPosition() const
{
  return (this->_pos);
}

const Vector &Particle::getRotation() const
{
  return (this->_rot);
}

const Vector &Particle::getSpeed() const
{
  return (this->_speed);
}

const Vector &Particle::getColor() const
{
  return (this->_color);
}

const Vector &Particle::getSize() const
{
  return (this->_size);
}

const Vector &Particle::getDirection() const
{
  return (this->_dir);
}

const Vector &Particle::getGravity() const
{
  return (this->_gravity);
}

const Pattern &Particle::getPattern() const
{
  return (this->_pattern);
}

const std::string &Particle::getPathTexture() const
{
  return (this->_path_texture);
}

float Particle::getLife() const
{
  return (this->_life);
}

float Particle::getFade() const
{
  return (this->_fade);
}

bool Particle::isAlive() const
{
  return (this->_alive);
}

void Particle::initialize()
{
}

void Particle::update()
{

  this->_pos.x += this->_dir.x / (this->_speed.x * 1000 );
  this->_pos.y += this->_dir.y / (this->_speed.y * 1000 );
  this->_pos.z += this->_dir.z / (this->_speed.z * 1000 );

  this->_dir.x += this->_gravity.x;
  this->_dir.y += this->_gravity.y;
  this->_dir.z += this->_gravity.z;

  this->_life -= this->_fade;
  this->_alive = (this->_life <= 0) ? false : true;


  this->_rot.x += rand() % 360;
  this->_rot.y += rand() % 360;
  this->_rot.z += rand() % 360;
}

void Particle::draw()
{
  glPushMatrix();
  glLoadIdentity();

  Daemon::DispersalRender::TEXTURE.bind();

  //if (this->_path_texture != "")
  //this->_texture.bind();


  glTranslatef(this->_pos.x, this->_pos.y, this->_pos.z);
  glRotatef(this->_rot.x, 1.0f, 0.0f, 0.0f);
  glRotatef(this->_rot.y, 0.0f, 1.0f, 0.0f);
  glRotatef(this->_rot.z, 0.0f, 0.0f, 1.0f);

  glBegin(GL_TRIANGLES);
  /*if (this->_path_texture == "")
    glColor4f(this->_color.x, this->_color.y, this->_color.z, this->_life);*/
  if (this->_pattern == ISO)
    {
      glTexCoord3f(0.0f, 1.0f, 0.0f);
      glVertex3f(0.0f, this->_size.x, 0.0f);
      glTexCoord3f(1.0f, 0.0f, 0.0f);
      glVertex3f(-this->_size.y, 0.0f, 0.0f);
      glTexCoord3f(0.0f, 0.0f, 1.0f);
      glVertex3f(this->_size.z, 0.0f, 0.0f);
    }
  else if (this->_pattern == RECT)
    {
      glTexCoord3f(0.0f, 1.0f, 0.0f);
      glVertex3f(0.0f, this->_size.x / 2.0f, 0.0f);
      glTexCoord3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0, 0.0f, 0.0f);
      glTexCoord3f(0.0f, 0.0f, 1.0f);
      glVertex3f(this->_size.z, 0.0f, 0.0f);
    }
  else
    {
      glTexCoord3f(0.0f, 1.0f, 0.0f);
      glVertex3f(0.0f, rand() % (int)this->_size.x, 0.0f);
      glTexCoord3f(1.0f, 0.0f, 0.0f);
      glVertex3f(-(rand() % (int)this->_size.y), 0.0f, 0.0f);
      glTexCoord3f(0.0f, 0.0f, 1.0f);
      glVertex3f((rand() % (int)this->_size.z), 0.0f, 0.0f);
    }
  glEnd();
  glPopMatrix();
}
