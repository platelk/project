//
// KeyboardEvent.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:27:49 2013 alexis leprovost
// Last update Wed May 15 22:21:08 2013 alexis leprovost
//

#include "Client/Event/KeyboardEvent.hh"

namespace Client
{
  std::string const	KeyboardEvent::KEY_DOWN = "keyDown";
  std::string const	KeyboardEvent::KEY_UP = "keyUp";

  KeyboardEvent::KeyboardEvent(std::string const& type, size_t keyCode,
			       bool ctrl, bool shift)
    : Event(Event::KEYBOARD, type), _keyCode(keyCode), _ctrl(ctrl), _shift(shift)
  {

  }

  KeyboardEvent::~KeyboardEvent()
  {

  }

  void	KeyboardEvent::setKeyCode(size_t keyCode)
  {
    this->_keyCode = keyCode;
  }

  void	KeyboardEvent::setCtrl(bool ctrl)
  {
    this->_ctrl = ctrl;
  }

  void	KeyboardEvent::setShift(bool shift)
  {
    this->_shift = shift;
  }

  size_t	KeyboardEvent::getKeyCode() const
  {
    return (this->_keyCode);
  }

  bool	KeyboardEvent::isPressedCtrl() const
  {
    return (this->_ctrl);
  }

  bool	KeyboardEvent::isPressedShift() const
  {
    return (this->_shift);
  }
}
