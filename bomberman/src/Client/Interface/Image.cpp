//
// Image.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 13:17:30 2013 alexis leprovost
// Last update Sun Jun  9 08:32:00 2013 alexis leprovost
// Last update Sat Jun  1 11:20:55 2013 alexis leprovost
//

#include "GL/gl.h"
#include "GL/glu.h"

#include <iostream>

#include "Client/Interface/Image.hh"
#include "Client/Interface/Interface.hh"

namespace Client
{
  Image::Image(std::string const& filename, Color const& color)
    : IWidgetObject(Interface::IMAGE),
      _color(color),
      _filename(filename),
      _rotation(Vector(0.0f, 0.0f, 0.0f)),
      _isInit(false)
  {

  }

  Image::Image(float red, float green, float blue, std::string const& filename)
    : IWidgetObject(Interface::IMAGE),
      _color(Color(red, green, blue)),
      _filename(filename),
      _rotation(Vector(0.0f, 0.0f, 0.0f)),
      _isInit(false)
  {

  }

  Image::Image(Color const& color, std::string const& filename)
    : IWidgetObject(Interface::IMAGE),
      _color(color),
      _filename(filename),
      _rotation(Vector(0.0f, 0.0f, 0.0f)),
      _isInit(false)
  {

  }

  Image::~Image()
  {

  }

  bool	Image::isInit() const
  {
    return (this->_isInit);
  }

  void	Image::initialize()
  {
    if (!this->_isInit)
      {
	this->_texture = gdl::Image::load(this->_filename);
	this->_isInit = true;
      }
  }

  void	Image::update(Event*)
  {

  }

  void	Image::draw()
  {
    if (this->_isInit && !this->isHidden())
      {
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(static_cast<float>(this->getX()), static_cast<float>(this->getY())
		     , static_cast<float>(this->getZ()));
	glRotatef(this->_rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(this->_rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(this->_rotation.z, 0.0f, 0.0f, 1.0f);
	this->_texture.bind();
	glBegin(GL_QUADS);
	glColor3f(this->_color.red, this->_color.green, this->_color.blue);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, this->getHeight(), 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(this->getWidth(), 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(this->getWidth(), this->getHeight(), 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glPopMatrix();
      }
  }

  void	Image::unload()
  {

  }

  void	Image::setFilename(std::string const& filename)
  {
    this->_isInit = false;
    this->_filename = filename;
  }

  std::string const&	Image::getFilename() const
  {
    return (this->_filename);
  }

  void	Image::setColor(float red, float green, float blue)
  {
    this->_color = Color(red, green, blue);
  }

  void	Image::setColor(Color const& color)
  {
    this->_color = color;
  }

  Color const&	Image::getColor() const
  {
    return (this->_color);
  }

  void		Image::setRotation(float x, float y, float z)
  {
    this->_rotation.x = x;
    this->_rotation.y = y;
    this->_rotation.z = z;
  }
}
