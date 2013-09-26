//
// MouseEvent.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:27:39 2013 alexis leprovost
// Last update Mon May 20 13:18:47 2013 alexis leprovost
//

#include "Client/Event/MouseEvent.hh"

namespace Client
{
  std::string const	MouseEvent::CLICK = "click";
  std::string const	MouseEvent::MIDDLE_CLICK = "middleClick";
  std::string const	MouseEvent::RIGHT_CLICK = "rightClick";
  std::string const	MouseEvent::LEFT_CLICK = "leftClick";
  std::string const	MouseEvent::MOUSE_WHEEL = "mouseWheel";
  std::string const	MouseEvent::MOUSE_WHEEL_UP = "mouseWheelUp";
  std::string const	MouseEvent::MOUSE_WHEEL_DOWN = "mouseWheelDown";
  std::string const	MouseEvent::MOUSE_MOVE = "mouseMove";

  MouseEvent::MouseEvent(std::string const& type, int x, int y)
    : Event(Event::MOUSE, type), _position(Point(x, y))
  {

  }

  MouseEvent::~MouseEvent()
  {

  }

  int	MouseEvent::getPosX() const
  {
    return (this->_position.x);
  }

  int	MouseEvent::getPosY() const
  {
    return (this->_position.y);
  }

  void	MouseEvent::setPosX(int x)
  {
    this->_position.x = x;
  }

  void	MouseEvent::setPosY(int y)
  {
    this->_position.y = y;
  }
}
