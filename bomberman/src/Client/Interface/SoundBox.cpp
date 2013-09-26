//
// SoundBox.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Thu Jun  6 17:36:08 2013 alexis leprovost
// Last update Sat Jun  8 19:21:16 2013 phalip_z
//

#include <iostream>

#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/SoundBox.hh"
#include "Client/Controller/Input.hh"

namespace Client
{
  SoundBox::SoundBox(std::string const& normal, std::string const& select,
		     Color const& color, bool isSelect, size_t power)
    : Button(normal, select, isSelect),
      _bar(color),
      _power(power)
  {

  }

  SoundBox::~SoundBox()
  {

  }

  void	SoundBox::initialize()
  {
    Button::initialize();
    this->_bar.initialize();
  }

  void	SoundBox::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);
    JoystickEvent*	joystickEvent = dynamic_cast<JoystickEvent*>(event);

    this->_normal.update(event);
    this->_select.update(event);
    this->_bar.update(event);
    if (keyboardEvent && this->_isSelect)
      {
	if (keyboardEvent->getKeyCode() == Input::Keys::Left)
	  {
	    --this->_power;
	    if (static_cast<int>(this->_power) < 0)
	      this->_power = 0;
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Right)
	  {
	    ++this->_power;
	    if (this->_power > 100)
	      this->_power = 100;
	  }
      }
    if (joystickEvent && this->_isSelect)
      {
	Point position = joystickEvent->getAxisPosition();
	if (position.x < 0)
	  {
	    --this->_power;
	    if (static_cast<int>(this->_power) < 0)
	      this->_power = 0;
	  }
	if (position.x > 0)
	  {
	    ++this->_power;
	    if (this->_power > 100)
	      this->_power = 100;
	  }
      }
  }

  void	SoundBox::draw()
  {
    if (!this->isHidden())
      {
	if (this->_isSelect)
	  this->_select.draw();
	else
	  this->_normal.draw();
	size_t	width = this->_bar.getWidth();
	this->_bar.setWidth(width * (this->_power / 100.0f));
	this->_bar.draw();
	this->_bar.setWidth(width);
      }
  }

  void	SoundBox::unload()
  {
    this->_normal.unload();
    this->_select.unload();
    this->_bar.unload();
  }

  void	SoundBox::setWidthBar(size_t width)
  {
    this->_bar.setWidth(width);
  }

  void	SoundBox::setHeightBar(size_t height)
  {
    this->_bar.setHeight(height);
  }

  void	SoundBox::setPositionBar(int x, int y, int z)
  {
    this->_bar.setPosition(x, y, z);
  }

  void	SoundBox::setColorBar(float red, float green, float blue)
  {
    this->_bar.setColor(red, green, blue);
  }

  void	SoundBox::setPowerBar(size_t power)
  {
    this->_power = power;
  }

  size_t	SoundBox::getPowerBar() const
  {
    return (this->_power);
  }
}
