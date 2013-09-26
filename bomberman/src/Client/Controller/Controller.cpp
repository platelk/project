//
// Controller.cpp for /home/phalip_z/projet_tek2/Bomberman/controller/src/Controller.cpp in /home/phalip_z//projet_tek2/Bomberman/controller
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Sat May 18 22:21:57 2013 phalip_z
// Last update Tue Jun  4 15:06:39 2013 phalip_z
//

#include <iostream>

#include	"Client/Event/MouseEvent.hh"
#include	"Client/Event/KeyboardEvent.hh"
#include	"Client/Event/JoystickEvent.hh"
#include	"Client/Controller/Controller.hh"

namespace Client
{
  Controller::Controller()
  {
    this->_mouse[Input::Mouse::Left] = MouseEvent::LEFT_CLICK;
    this->_mouse[Input::Mouse::Right] = MouseEvent::RIGHT_CLICK;
    this->_mouse[Input::Mouse::Middle] = MouseEvent::MIDDLE_CLICK;
  }

  Controller::~Controller()
  {

  }

  bool	Controller::hasEvent(void) const
  {
    return (!this->_event.empty());
  }

  bool	Controller::_isControlDown(Input &input)
  {
    return (input.isKeyDown(Input::Keys::LControl) ||
	    input.isKeyDown(Input::Keys::RControl));
  }

  bool	Controller::_isControl(Input::Keys::Key key)
  {
    return (key == Input::Keys::LControl || key == Input::Keys::RControl);
  }

  bool	Controller::_isShiftDown(Input &input)
  {
    return (input.isKeyDown(Input::Keys::LShift) ||
	    input.isKeyDown(Input::Keys::RShift));
  }

  bool	Controller::_isShift(Input::Keys::Key key)
  {
    return (key == Input::Keys::LShift || key == Input::Keys::RShift);
  }

  void	Controller::_setKeyboardEvent(Input& input)
  {
    KeyboardEvent	*keyboardEvent;

    for (int i = 0; i <= Input::Keys::Count; ++i)
      if (input.isKeyDown(static_cast<Input::Keys::Key>(i)) &&
	  !this->_isShift(static_cast<Input::Keys::Key>(i)) &&
	  !this->_isControl(static_cast<Input::Keys::Key>(i)))
	{
	  keyboardEvent = new KeyboardEvent("keyDown", i);
	  if (this->_isControlDown(input))
	    keyboardEvent->setCtrl(true);
	  if (this->_isShiftDown(input))
	    keyboardEvent->setShift(true);
	  this->_event.push(keyboardEvent);
	}
  }

  void	Controller::_setMouseEvent(Input& input)
  {
    for (int i = 0; i <= Input::Mouse::Left; ++i)
      if (input.isMouseButtonDown(static_cast<Input::Mouse::Button>(i)))
	this->_event.push(new MouseEvent(this->_mouse[i],
					 input.getMousePositionX(),
					 input.getMousePositionY()));
    if (input.isMouseMove())
      this->_event.push(new MouseEvent(MouseEvent::MOUSE_MOVE,
				       input.getMousePositionX(),
				       input.getMousePositionY()));
  }

  void	Controller::_setJoystickEvent(Input& input)
  {
    int	nbJoystick = input.getNbJoysticks();
    int	j;
    int x;
    int y;
    int	i;

    for (i = 0; i <= Input::JoystickButton::START; ++i)
      for (j = 0; j <= nbJoystick; ++j)
	if (input.isJoystickButtonDown(static_cast<Input::JoystickButton::Button>(i), j))
	  this->_event.push(new JoystickEvent(JoystickEvent::BUTTON, j, i));
    for (j = 0; j <= nbJoystick; ++j)
      {
	x = input.getJoystickAxis(Input::JoystickAxes::AX, j);
	y = input.getJoystickAxis(Input::JoystickAxes::AY, j);
	if (x || y)
	  this->_event.push(new JoystickEvent(JoystickEvent::AXIS, j, x, y));
	x = input.getJoystickAxis(Input::JoystickAxes::BX, j);
	y = input.getJoystickAxis(Input::JoystickAxes::BY, j);
	if (x || y)
	  this->_event.push(new JoystickEvent(JoystickEvent::AXIS, j, x, y));
	if (input.getJoystickAxis(Input::JoystickAxes::AZ, j))
	  this->_event.push(new JoystickEvent(JoystickEvent::TRIGGER, j, true));
	if (input.getJoystickAxis(Input::JoystickAxes::BZ, j))
	  this->_event.push(new JoystickEvent(JoystickEvent::TRIGGER, j, false));
      }
  }

  void	Controller::setInput(Input &input)
  {
    this->_setKeyboardEvent(input);
    this->_setMouseEvent(input);
    this->_setJoystickEvent(input);
  }

  Event *Controller::getEvent(void)
  {
    Event *tmp = this->_event.front();

    this->_event.pop();
    return (tmp);
  }
}
