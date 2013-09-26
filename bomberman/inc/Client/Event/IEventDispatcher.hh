//
// IEventDispatcher.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Event
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 13 10:48:48 2013 alexis leprovost
// Last update Wed May 15 21:24:52 2013 alexis leprovost
//

#ifndef __IEVENT_DISPATCHER_HH__
#define __IEVENT_DISPATCHER_HH__

#include <string>
#include <sys/types.h>

#include "Client/Event/EventListener.hh"

namespace Client
{
  class Event;

  class IEventDispatcher
  {
  public:
    virtual ~IEventDispatcher() {}

    virtual void	addEventListener(std::string const& type,
					 EventListener::func callback,
					 int priority = 0) = 0;
    virtual void	removeEventListener(std::string const& type) = 0;
    virtual void	removeAllEventListener(std::string const& type) = 0;
    virtual size_t	dispatchEvent(Event* event, bool peddle = false) const = 0;
    virtual size_t	dispatchEvent(std::string const& type, bool peddle = false) const = 0;
    virtual bool	hasEventListener(std::string const& type) const = 0;
  };
}

#include "Client/Event/Event.hh"

#endif
