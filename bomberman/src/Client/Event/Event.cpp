//
// Event.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Sun May 12 12:28:00 2013 alexis leprovost
// Last update Sun Jun  9 16:58:17 2013 alexis leprovost
//

#include "Client/Event/Event.hh"

namespace Client
{
  std::string const	Event::MOUSE = "mouse";
  std::string const	Event::KEYBOARD = "keyboard";
  std::string const	Event::JOYSTICK = "joystick";
  std::string const	Event::CAMERA = "camera";
  std::string const	Event::UPDATE = "update";
  std::string const	Event::DRAW = "draw";
  std::string const	Event::STATE = "state";
  std::string const	Event::NETWORK = "network";
  std::string const	Event::INITIALIZE = "initialize";
  std::string const	Event::SYNCHRONISATION = "synchronisation";
  std::string const	Event::START = "start";
  std::string const	Event::END = "end";
  std::string const	Event::SAVE = "save";

  Event::Event(std::string const& type, std::string const& name)
    : _type(type), _name(name)
  {

  }

  Event::~Event()
  {

  }

  std::string const&	Event::getType() const
  {
    return (this->_type);
  }

  std::string const&	Event::getName() const
  {
    return (this->_name);
  }
}
