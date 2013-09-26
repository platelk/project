//
// UpdateEvent.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Thu May 16 11:43:49 2013 alexis leprovost
// Last update Tue May 28 16:04:17 2013 alexis leprovost
//

#ifndef _UPDATEEVENT_H_
#define _UPDATEEVENT_H_

#include <string>

#include "Client/Event/Event.hh"

namespace Client
{
  class UpdateEvent : public Event
  {
  private:
    Event*			_event;
  public:
    UpdateEvent(std::string const& type, Event *event);
    virtual ~UpdateEvent();

    Event*			getEvent() const;

    static std::string const	OBJECT;
  };
}

#endif /* _UPDATEEVENT_H_ */
