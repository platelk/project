//
// JoystickEvent.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 20 15:32:12 2013 alexis leprovost
// Last update Mon May 20 17:51:02 2013 alexis leprovost
//

#include "Client/Event/JoystickEvent.hh"

namespace Client
{
  std::string const	JoystickEvent::AXIS = "axis";
  std::string const	JoystickEvent::BUTTON = "button";
  std::string const	JoystickEvent::TRIGGER = "trigger";

  JoystickEvent::JoystickEvent(std::string const& type, int id, int x, int y)
    : Event(Event::JOYSTICK, type),
      _id(id),
      _axis(Point(x, y)),
      _leftTrigger(false),
      _button(-1)
  {

  }

  JoystickEvent::JoystickEvent(std::string const& type, int id, int button)
    : Event(Event::JOYSTICK, type),
      _id(id),
      _axis(Point(0, 0)),
      _leftTrigger(false),
      _button(button)
  {

  }

  JoystickEvent::JoystickEvent(std::string const& type, int id, bool leftTrigger)
    : Event(Event::JOYSTICK, type),
      _id(id),
      _axis(Point(0, 0)),
      _leftTrigger(leftTrigger),
      _button(-1)
  {

  }

  JoystickEvent::JoystickEvent(std::string const& type, int id)
    : Event(Event::JOYSTICK, type),
      _id(id),
      _axis(Point(0, 0)),
      _leftTrigger(false),
      _button(-1)
  {

  }

  JoystickEvent::~JoystickEvent()
  {

  }

  Point const&	JoystickEvent::getAxisPosition()
  {
    return (this->_axis);
  }

  bool		JoystickEvent::isLeftTrigger()
  {
    return (this->_leftTrigger);
  }

  bool		JoystickEvent::isRightTrigger()
  {
    return (!this->_leftTrigger);
  }

  int		JoystickEvent::getButton()
  {
    return (this->_button);
  }

  int		JoystickEvent::getId()
  {
    return (this->_id);
  }

  void		JoystickEvent::setAxisPosition(int x, int y)
  {
    this->_axis.x = x;
    this->_axis.y = y;
  }

  void		JoystickEvent::setAxisPosition(Point const& axis)
  {
    this->_axis.x = axis.x;
    this->_axis.y = axis.y;
  }

  void		JoystickEvent::setLeftTrigger()
  {
    this->_leftTrigger = true;
  }

  void		JoystickEvent::setRightTrigger()
  {
    this->_leftTrigger = false;
  }

  void		JoystickEvent::setButton(int button)
  {
    this->_button = button;
  }
}
