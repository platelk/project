//
// EventListener.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 13 10:26:21 2013 alexis leprovost
// Last update Tue May 14 09:42:29 2013 alexis leprovost
//

#include "Client/Event/EventListener.hh"

namespace Client
{
  EventListener::Compare::Compare(std::string const& type)
    : _type(type)
  {

  }

  EventListener::Compare::~Compare()
  {

  }

  bool	EventListener::Compare::operator()(EventListener const& eventListener)
  {
    return (eventListener.getType() == this->_type);
  }

  EventListener::Function::Function(std::string const& type, Widget* widget, Event* event)
    : _type(type), _widget(widget), _event(event), _executed(0)
  {

  }

  EventListener::Function::~Function()
  {

  }

  size_t	EventListener::Function::getNbExecuted() const
  {
    return (this->_executed);
  }

  void	EventListener::Function::operator()(EventListener const& eventListener)
  {
    if (eventListener.getType() == this->_type)
      {
	eventListener.execute(this->_widget, this->_event);
	++this->_executed;
      }
  }

  EventListener::EventListener(std::string const& type,
			       EventListener::func callback,
			       int priority)
    : _type(type), _callback(callback), _priority(priority)
  {

  }

  EventListener::~EventListener()
  {

  }

  std::string const&		EventListener::getType() const
  {
    return (this->_type);
  }

  int				EventListener::getPriority() const
  {
    return (this->_priority);
  }

  EventListener::func		EventListener::getCallback() const
  {
    return (this->_callback);
  }

  bool	EventListener::operator<(EventListener const& eventListener) const
  {
    return (this->getPriority() < eventListener.getPriority());
  }

  void	EventListener::execute(Widget* bloc, Event* event) const
  {
    this->_callback(bloc, event);
  }
}
