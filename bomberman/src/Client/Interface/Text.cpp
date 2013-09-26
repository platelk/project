//
// Text.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 19:49:41 2013 alexis leprovost
// Last update Sun Jun  9 08:34:44 2013 alexis leprovost
//

#include "GL/gl.h"
#include "GL/glu.h"

#include "Image.hpp"
#include "Client/Interface/Text.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/Image.hh"

namespace Client
{
  TextManager	Text::manager;
  bool		Text::init = false;
  Text::Manual	Text::manual;

  Text::Text(std::string const& text, size_t size, Color const& color)
    : IWidgetObject(Interface::TEXT),
      _text(text),
      _size(size),
      _color(color)
  {
    if (Text::manual.empty())
      {
	char	c;
	int	i;

	i = -1;
	for (c = 65; c < 91; ++c)
	  Text::manual[c] = ++i;
	i = -1;
	for (c = 97; c < 123; ++c)
	  Text::manual[c] = ++i;
	i = 25;
	for (c = 48; c < 58; ++c)
	  Text::manual[c] = ++i;
	i = 74;
	for (c = 48; c < 58; ++c)
	  Text::manual[c] = ++i;
	Text::manual[' '] = 57;
	Text::manual['+'] = 67;
	Text::manual['-'] = 68;
	Text::manual['*'] = 69;
	Text::manual['/'] = 70;
	Text::manual['.'] = 49;
	Text::manual[1] = 73;
	Text::manual[2] = 74;
	Text::manual[3] = 71;
	Text::manual[4] = 72;
	Text::manual[5] = 59;
	if (!Text::init)
	  {
	    for (i = 0; i < 36; ++i)
	      Text::manager.add(i);
	    for (i = 75; i < 85; ++i)
	      Text::manager.add(i);
	    Text::manager.add(49);
	    Text::manager.add(57);
	    Text::manager.add(59);
	    Text::manager.add(67);
	    Text::manager.add(68);
	    Text::manager.add(69);
	    Text::manager.add(70);
	    Text::manager.add(71);
	    Text::manager.add(72);
	    Text::manager.add(73);
	    Text::manager.add(74);
	    Text::manager.add(127);
	    Text::init = true;
	  }
      }
  }

  Text::~Text()
  {

  }

  void	Text::setColor(float red, float green, float blue)
  {
    this->_color.red = red;
    this->_color.green = green;
    this->_color.blue = blue;
  }

  void	Text::setSize(size_t size)
  {
    this->_size = size;
  }

  void	Text::setText(std::string const& text)
  {
    this->_text = text;
  }

  size_t	Text::getSize() const
  {
    return (this->_size);
  }

  std::string const&	Text::getText() const
  {
    return (this->_text);
  }

  Color const&		Text::getColor() const
  {
    return (this->_color);
  }

  void	Text::initialize()
  {

  }

  void	Text::update(Event*)
  {

  }

  void	Text::draw()
  {
    for (size_t i = 0; i < this->_text.size(); ++i)
      {
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(this->getX() + static_cast<int>(i * this->_size), this->getY(), this->getZ());
	glRotatef(this->_rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(this->_rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(this->_rotation.z, 0.0f, 0.0f, 1.0f);
	static_cast<gdl::Image>(Text::manager.get(Text::manual[this->_text[i]])).bind();
	glColor3f(this->_color.red, this->_color.green, this->_color.blue);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, this->_size, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(this->_size, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(this->_size, this->_size, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glPopMatrix();
      }
  }

  void	Text::unload()
  {

  }

  void	Text::setRotation(float x, float y, float z)
  {
    this->_rotation.x = x;
    this->_rotation.y = y;
    this->_rotation.z = z;
  }
}
