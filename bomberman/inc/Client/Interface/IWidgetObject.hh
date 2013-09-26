//
// IWidgetObject.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 10:14:08 2013 alexis leprovost
// Last update Sun Jun  9 17:48:08 2013 alexis leprovost
//

#ifndef _IWIDGETOBJECT_H_
#define _IWIDGETOBJECT_H_

#include <string>

#include "Client/Event/Event.hh"
#include "Client/Interface/Widget.hh"

namespace Client
{
  class IWidgetObject : public Widget
  {
  public:
    IWidgetObject(std::string const& name) : Widget(name) {}
    virtual ~IWidgetObject() {}

    virtual void	initialize() = 0;
    virtual void	update(Event* event) = 0;
    virtual void	draw() = 0;
    virtual void	unload() = 0;
  };
}

#endif /* _IWIDGETOBJECT_H_ */
