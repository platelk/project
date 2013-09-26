//
// Widget.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 13 13:29:32 2013 alexis leprovost
// Last update Sun Jun  9 09:28:48 2013 alexis leprovost
//

#ifndef __WIDGET_HH__
#define __WIDGET_HH__

#include <sys/types.h>
#include <list>
#include <string>

#include "Vector.hh"
#include "Client/Event/Event.hh"
#include "Client/Event/IEventDispatcher.hh"
#include "Client/Event/EventListener.hh"

namespace Client
{
  class IWidgetObject;

  class Widget : public IEventDispatcher
  {
  protected:
    std::string			_name;
    size_t			_width;
    size_t			_height;
    Vector			_localPosition;
    Vector			_globalPosition;
    int				_flag;
    Widget*			_parent;
    std::list<Widget*>		_children;
    std::list<IWidgetObject*>	_contents;
    std::list<EventListener>	_events;
  public:
    class Compare
    {
    private:
      std::string	_name;
    public:
      Compare(std::string const& name);
      ~Compare();

      bool	operator() (Widget* widget) const;
    };

    class Function
    {
    private:
      Event*		_event;
      std::string	_type;
      bool		_peddle;
      size_t		_executed;
    public:
      Function(Event* event, bool peddle);
      Function(std::string const& type, bool peddle);
      ~Function();

      size_t	getNbExecuted() const;

      void	operator()(Widget* widget);
    };

    Widget(std::string const& name, Widget* parent = 0);
    virtual ~Widget();

    void	addChild(Widget* widget, size_t n = -1);
    void	removeChild(std::string const& name);
    void	removeChildAt(size_t n);
    void	removeAllChild();

    void	addWidgetObject(IWidgetObject* widgetObject, size_t n = -1);
    void	removeWidgetObject(std::string const& name);
    void	removeWidgetObjectAt(size_t n);
    void	removeAllWidgetObject();

    virtual void	addEventListener(std::string const& type,
					 EventListener::func callback,
					 int priority = 0);
    virtual void	removeEventListener(std::string const& type);
    virtual void	removeAllEventListener(std::string const& type);
    virtual size_t	dispatchEvent(Event* event, bool peddle = false) const;
    virtual size_t	dispatchEvent(std::string const& type, bool peddle = false) const;
    virtual bool	hasEventListener(std::string const& type) const;

    size_t	getNbChild() const;
    Widget*	getChild(std::string const& name) const;
    Widget*	getChildAt(size_t n) const;

    size_t		getNbWidgetObject() const;
    IWidgetObject*	getWidgetObject(std::string const& name) const;
    IWidgetObject*	getWidgetObjectAt(size_t n) const;

    Widget*		getParent() const;
    size_t		getWidth() const;
    size_t		getHeight() const;
    int			getLocalX() const;
    int			getLocalY() const;
    int			getLocalZ() const;
    int			getX() const;
    int			getY() const;
    int			getZ() const;
    std::string const&	getName() const;

    void	setWidth(size_t width);
    void	setHeight(size_t height);
    void	setLocalX(int x);
    void	setLocalY(int y);
    void	setLocalZ(int z);
    void	setLocalPosition(int x, int y, int z = 0);
    void	setX(int x);
    void	setY(int y);
    void	setZ(int z);
    void	setPosition(int x, int y, int z = 0);
    void	setName(std::string const& name);
    void	setParent(Widget* parent);

    bool	isDefinedPosition() const;
    bool	isHidden() const;

    void	hide();
    void	show();
  };
}

#include "Client/Interface/IWidgetObject.hh"

#endif
