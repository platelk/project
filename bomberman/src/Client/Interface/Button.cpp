//
// Button.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 10:19:04 2013 alexis leprovost
// Last update Sat Jun  8 10:55:41 2013 alexis leprovost
//

#include <iostream>

#include "Color.hpp"
#include "Client/Interface/Camera.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Controller/Input.hh"

namespace Client
{
  Button::Button(std::string const& normal, std::string const& select, bool isSelect)
    : IWidgetObject(Interface::BUTTON),
      _normal(normal),
      _select(select),
      _isSelect(isSelect),
      _target(""),
      _hasTarget(false)
  {
    this->_link[ButtonManager::Top] = -1;
    this->_link[ButtonManager::Right] = -1;
    this->_link[ButtonManager::Bottom] = -1;
    this->_link[ButtonManager::Left] = -1;
  }

  Button::Button(Color const& normal, Color const& select, bool isSelect)
    : IWidgetObject(Interface::BUTTON),
      _normal(normal),
      _select(select),
      _isSelect(isSelect),
      _target(""),
      _hasTarget(false)
  {
    this->_link[ButtonManager::Top] = -1;
    this->_link[ButtonManager::Right] = -1;
    this->_link[ButtonManager::Bottom] = -1;
    this->_link[ButtonManager::Left] = -1;
  }

  Button::~Button()
  {

  }

  void	Button::initialize()
  {
    this->_normal.initialize();
    this->_select.initialize();
  }

  void	Button::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);
    JoystickEvent*	joystickEvent = dynamic_cast<JoystickEvent*>(event);

    this->_normal.update(event);
    this->_select.update(event);
    if (((keyboardEvent &&
	  keyboardEvent->getKeyCode() == Input::Keys::Enter) ||
	 (joystickEvent &&
	  joystickEvent->getButton() == Input::JoystickButton::A)) &&
	this->_isSelect)
      {
	Event event(Event::STATE, Event::STATE);
	this->dispatchEvent(&event);
      }
  }

  void	Button::draw()
  {
    if (this->_isSelect)
      this->_select.draw();
    else
      {
	if (this->isHidden())
	  this->_normal.setColor(0.5f, 0.5f, 0.5f);
	else
	  this->_normal.setColor(1.0f, 1.0f, 1.0f);
	this->_normal.draw();
      }
  }

  void	Button::unload()
  {
    this->_normal.unload();
    this->_select.unload();
  }

  void	Button::setTarget(std::string const& target)
  {
    this->_target = target;
  }

  bool	Button::hasTarget() const
  {
    return (this->_hasTarget);
  }

  std::string const&	Button::getTarget() const
  {
    return (this->_target);
  }

  void	Button::setLink(ButtonManager::Sens sens, size_t n)
  {
    this->_link[static_cast<int>(sens)] = n;
  }

  size_t	Button::getLink(ButtonManager::Sens sens) const
  {
    return (this->_link[sens]);
  }

  void	Button::select(bool isSelect)
  {
    this->_isSelect = isSelect;
  }

  void	Button::setX(int x)
  {
    Widget::setX(x);
    this->_normal.setX(x);
    this->_select.setX(x);
  }

  void	Button::setY(int y)
  {
    Widget::setY(y);
    this->_normal.setY(y);
    this->_select.setY(y);
  }

  void	Button::setZ(int z)
  {
    Widget::setZ(z);
    this->_normal.setZ(z);
    this->_select.setZ(z);
  }

  void	Button::setPosition(int x, int y, int z)
  {
    Widget::setPosition(x, y, z);
    this->_normal.setPosition(x, y, z);
    this->_select.setPosition(x, y, z);
  }

  void	Button::setWidth(size_t width)
  {
    Widget::setWidth(width);
    this->_normal.setWidth(width);
    this->_select.setWidth(width);
  }

  void	Button::setHeight(size_t height)
  {
    Widget::setHeight(height);
    this->_normal.setHeight(height);
    this->_select.setHeight(height);
  }
}
