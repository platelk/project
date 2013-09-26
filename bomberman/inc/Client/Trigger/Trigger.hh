//
// Trigger.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 15:57:03 2013 alexis leprovost
// Last update Mon Jun 10 21:59:42 2013 alexis leprovost
//

#ifndef _TRIGGER_H_
#define _TRIGGER_H_

#include "Client/Interface/Widget.hh"
#include "Client/Event/Event.hh"

namespace Client
{
  namespace Trigger
  {
    void	dispatch(Widget* widget, Event* event);
    void	initialize(Widget* widget, Event* event);
    void	update(Widget* widget, Event* event);
    void	draw(Widget* widget, Event* event);
    void	state(Widget* widget, Event* event);
    void	dynamic(Widget* widget, Event* event);
    void	quit(Widget* widget, Event* event);
    void	target(Widget* widget, Event* event);
    void	random(Widget* widget, Event* event);
    void	route(Widget* widget, Event* event);
    void	synchronisation(Widget* widget, Event* event);
    void	menu(Widget* widget, Event* event);
    void	game(Widget* widget, Event* event);
    void	save(Widget* widget, Event* event);
    void	settings(Widget* widget, Event* event);
    void	connect(Widget* widget, Event* event);
    void	start(Widget* widget, Event* event);
    void	select(Widget* widget, Event* event);
    void	soundGame(Widget* widget, Event* event);
    void	saveMap(Widget* widget, Event* event);
    void	end(Widget* widget, Event* event);
    void	escape(Widget* widget, Event* event);
    void	disconnect(Widget* widget, Event* event);
  }
}

#endif /* _TRIGGER_H_ */
