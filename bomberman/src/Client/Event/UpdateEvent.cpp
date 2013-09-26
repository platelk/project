//
// UpdateEvent.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Thu May 16 11:43:17 2013 alexis leprovost
// Last update Tue May 28 16:05:08 2013 alexis leprovost
//

#include "Client/Event/UpdateEvent.hh"

namespace Client
{
  std::string const	UpdateEvent::OBJECT = "object";

  UpdateEvent::UpdateEvent(std::string const& type, Event* event)
    : Event(Event::UPDATE, type), _event(event)
  {

  }

  UpdateEvent::~UpdateEvent()
  {

  }

  Event*	        UpdateEvent::getEvent() const
  {
    return (this->_event);
  }
}
