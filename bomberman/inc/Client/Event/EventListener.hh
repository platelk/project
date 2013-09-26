//
// Eventlistener.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 13 10:26:48 2013 alexis leprovost
// Last update Mon May 13 18:34:21 2013 alexis leprovost
//

#ifndef _EVENTLISTENER_H_
#define _EVENTLISTENER_H_

#include <sys/types.h>
#include <string>

#include "Client/Event/Event.hh"

namespace Client
{
  class Widget;

  class EventListener
  {
  public:
    typedef void	(*func)(Widget*, Event*);
  private:
    std::string				_type;
    EventListener::func			_callback;
    int					_priority;
  public:
    class Compare
    {
    private:
      std::string	_type;
    public:
      Compare(std::string const& type);
      ~Compare();

      bool	operator()(EventListener const& eventListener);
    };

    class Function
    {
    private:
      std::string	_type;
      Widget*		_widget;
      Event*		_event;
      size_t		_executed;
    public:
      Function(std::string const& type, Widget* widget, Event* event);
      ~Function();

      size_t	getNbExecuted() const;

      void	operator()(EventListener const& eventListener);
    };

    EventListener(std::string const& type,
		  EventListener::func callback,
		  int priority = 0);
    ~EventListener();

    std::string const&		getType() const;
    int				getPriority() const;
    EventListener::func		getCallback() const;

    bool	operator<(EventListener const& eventListener) const;

    void	execute(Widget* bloc, Event* event) const;
  };
}

#include "Client/Event/IEventDispatcher.hh"

#endif /* _EVENTLISTENER_H_ */
