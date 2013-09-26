//
// Widget.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 13 13:29:39 2013 alexis leprovost
// Last update Sat Jun  8 08:44:33 2013 phalip_z
//

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
#include <iomanip>

#include "Client/Interface/Widget.hh"
#include "Client/Interface/Stage.hh"

namespace Client
{
  Widget::Compare::Compare(std::string const& name)
    : _name(name)
  {

  }

  Widget::Compare::~Compare()
  {

  }

  bool	Widget::Compare::operator()(Widget* widget) const
  {
    return (widget->getName() == this->_name);
  }

  Widget::Function::Function(Event* event, bool peddle)
    : _event(event), _type(""), _peddle(peddle), _executed(0)
  {

  }

  Widget::Function::Function(std::string const& type, bool peddle)
    : _event(0), _type(type), _peddle(peddle), _executed(0)
  {

  }

  Widget::Function::~Function()
  {

  }

  size_t	Widget::Function::getNbExecuted() const
  {
    return (this->_executed);
  }

  void	Widget::Function::operator()(Widget* widget)
  {
    if (this->_event)
      this->_executed += widget->dispatchEvent(this->_event, this->_peddle);
    else
      this->_executed += widget->dispatchEvent(this->_type, this->_peddle);
  }

  Widget::Widget(std::string const& name , Widget* parent)
    : _name(name),
      _width(0),
      _height(0),
      _localPosition(Vector(0, 0, 0)),
      _globalPosition(Vector(0, 0, 0)),
      _flag(0),
      _parent(parent)
  {
    if (this->_parent)
      this->_parent->addChild(this);
  }

  Widget::~Widget()
  {
    this->removeAllChild();
    this->removeAllWidgetObject();
  }

  Widget*	Widget::getParent() const
  {
    return (this->_parent);
  }

  size_t	Widget::getWidth() const
  {
    return (this->_width);
  }

  size_t	Widget::getHeight() const
  {
    return (this->_height);
  }

  int		Widget::getLocalX() const
  {
    return (this->_localPosition.x);
  }

  int		Widget::getLocalY() const
  {
    return (this->_localPosition.y);
  }

  int		Widget::getLocalZ() const
  {
    return (this->_localPosition.z);
  }

  int		Widget::getX() const
  {
    return (this->_globalPosition.x);
  }

  int		Widget::getY() const
  {
    return (this->_globalPosition.y);
  }

  int		Widget::getZ() const
  {
    return (this->_globalPosition.z);
  }

  std::string const&	Widget::getName() const
  {
    return (this->_name);
  }

  void	Widget::setWidth(size_t width)
  {
    this->_width = width;
  }

  void	Widget::setHeight(size_t height)
  {
    this->_height = height;
  }

  void	Widget::setLocalX(int x)
  {
    this->_flag |= 6;
    this->_globalPosition.x = (this->_parent ? this->_parent->getX() + x : x);
    this->_localPosition.x = x;
  }

  void	Widget::setLocalY(int y)
  {
    this->_flag |= 6;
    this->_globalPosition.y = (this->_parent ? this->_parent->getY() + y : y);
    this->_localPosition.y = y;
  }


  void	Widget::setLocalZ(int z)
  {
    this->_flag |= 6;
    this->_globalPosition.z = (this->_parent ? this->_parent->getZ() + z : z);
    this->_localPosition.z = z;
  }

  void	Widget::setLocalPosition(int x, int y, int z)
  {
    this->_flag |= 6;
    this->_globalPosition.x = (this->_parent ? this->_parent->getX() + x : x);
    this->_globalPosition.y = (this->_parent ? this->_parent->getY() + y : y);
    this->_globalPosition.z = (this->_parent ? this->_parent->getZ() + z : z);
    this->_localPosition.x = x;
    this->_localPosition.y = y;
    this->_localPosition.z = z;
  }

  void	Widget::setX(int x)
  {
    this->_flag |= 6;
    this->_localPosition.x = (this->_parent ? x - this->_parent->getX() : x);
    this->_globalPosition.x = x;
  }

  void	Widget::setY(int y)
  {
    this->_flag |= 6;
    this->_localPosition.y = (this->_parent ? y - this->_parent->getY() : y);
    this->_globalPosition.y = y;
  }

  void	Widget::setZ(int z)
  {
    this->_flag |= 6;
    this->_localPosition.z = (this->_parent ? z - this->_parent->getZ() : z);
    this->_globalPosition.z = z;
  }

  void	Widget::setPosition(int x, int y, int z)
  {
    this->_flag |= 6;
    this->_localPosition.x = (this->_parent ? x - this->_parent->getX() : x);
    this->_localPosition.y = (this->_parent ? y - this->_parent->getY() : y);
    this->_localPosition.z = (this->_parent ? z - this->_parent->getZ() : z);
    this->_globalPosition.x = x;
    this->_globalPosition.y = y;
    this->_globalPosition.z = z;
  }

  void	Widget::setName(std::string const& name)
  {
    this->_name = name;
  }

  void	Widget::setParent(Widget* parent)
  {
    this->_parent = parent;
  }

  bool	Widget::isDefinedPosition() const
  {
    return (((this->_flag >> 1) & 1) || ((this->_flag >> 2) & 1) ? true : false);
  }

  bool	Widget::isHidden() const
  {
    return ((this->_flag & 1) ? true : false);
  }

  void	Widget::hide()
  {
    this->_flag |= 1;
  }

  void	Widget::show()
  {
    this->_flag = ((this->_flag >> 1) << 1);
  }

  void	Widget::addChild(Widget* widget, size_t n)
  {
    if (static_cast<int>(n) == -1 || n >= this->_children.size())
      this->_children.push_back(widget);
    else if (!n)
      this->_children.push_front(widget);
    else
      this->_children.insert(this->_children.begin(), n, widget);
  }

  void	Widget::removeChild(std::string const& name)
  {
    std::list<Widget*>::iterator it;

    it = std::find_if(this->_children.begin(), this->_children.end(), Widget::Compare(name));
    if (it != this->_children.end())
      delete *(this->_children.erase(it));
  }

  void	Widget::removeChildAt(size_t n)
  {
    std::list<Widget*>::iterator it = this->_children.begin();

    if (n < this->_children.size())
      {
	std::advance(it, n);
	delete *(this->_children.erase(it));
      }
  }

  void	Widget::removeAllChild()
  {
    while (!this->_children.empty())
      {
	delete this->_children.front();
	this->_children.pop_front();
      }
  }

  void	Widget::addWidgetObject(IWidgetObject* widgetObject, size_t n)
  {
    if (static_cast<int>(n) == -1 || n >= this->_contents.size())
      this->_contents.push_back(widgetObject);
    else if (!n)
      this->_contents.push_front(widgetObject);
    else
      this->_contents.insert(this->_contents.begin(), n, widgetObject);
  }

  void Widget::removeWidgetObject(const std::string &name)
  {
    std::list<IWidgetObject*>::iterator it;

    it = std::find_if(this->_contents.begin(), this->_contents.end(), Widget::Compare(name));
    if (it != this->_contents.end())
      delete *(this->_contents.erase(it));
  }

  void Widget::removeWidgetObjectAt(size_t n)
  {

    std::list<IWidgetObject*>::iterator it = this->_contents.begin();

    if (n < this->_contents.size())
      {
  	std::advance(it, n);
  	this->_contents.erase(it);
      }
  }

  void	Widget::removeAllWidgetObject()
  {
    while (!this->_contents.empty())
      {
	delete this->_contents.front();
	this->_contents.pop_front();
      }
  }

  size_t	Widget::getNbChild() const
  {
    return (this->_children.size());
  }

  Widget*	Widget::getChild(std::string const& name) const
  {
    std::list<Widget*>::const_iterator it;

    it = std::find_if(this->_children.begin(), this->_children.end(), Widget::Compare(name));
    return ((it != this->_children.end()) ? *it : 0);
  }

  Widget*	Widget::getChildAt(size_t n) const
  {
    std::list<Widget*>::const_iterator it = this->_children.begin();

    if (n >= this->_children.size())
      return (0);
    std::advance(it, n);
    return (*it);
  }

  size_t	Widget::getNbWidgetObject() const
  {
    return (this->_contents.size());
  }

  IWidgetObject *Widget::getWidgetObject(const std::string &name) const
  {
    std::list<IWidgetObject*>::const_iterator it;

    it = std::find_if(this->_contents.begin(), this->_contents.end(), Widget::Compare(name));
    return ((it != this->_contents.end()) ? *it : 0);
  }

  IWidgetObject *Widget::getWidgetObjectAt(size_t n) const
  {
    std::list<IWidgetObject *>::const_iterator it = this->_contents.begin();

    if (n >= this->_contents.size())
      return (0);
    std::advance(it, n);
    return (*it);
  }

  void	Widget::addEventListener(std::string const& type,
				 EventListener::func callback,
				 int priority)
  {
    this->_events.push_back(EventListener(type, callback, priority));
    this->_events.sort();
  }

  void	Widget::removeEventListener(std::string const& type)
  {
    std::list<EventListener>::iterator it;

    it = std::find_if(this->_events.begin(), this->_events.end(), EventListener::Compare(type));
    if (it != this->_events.end())
      this->_events.erase(it);
  }

  void	Widget::removeAllEventListener(const std::string &type)
  {
    this->_events.remove_if(EventListener::Compare(type));
  }

  size_t	Widget::dispatchEvent(Event *event, bool peddle) const
  {
    if (!event)
      return (0);
    EventListener::Function	eventFunctor(event->getType(),
					     const_cast<Widget*>(this),
					     event);
    Widget::Function		widgetFunctor(event, peddle);

    if (this->hasEventListener(event->getType()))
      std::for_each(this->_events.begin(), this->_events.end(), eventFunctor);
    if (peddle && this->getNbChild())
      std::for_each(this->_children.begin(), this->_children.end(), widgetFunctor);
    return (eventFunctor.getNbExecuted() + widgetFunctor.getNbExecuted());
  }

  size_t	Widget::dispatchEvent(std::string const& type, bool peddle) const
  {
    EventListener::Function	eventFunctor(type, const_cast<Widget*>(this), 0);
    Widget::Function		widgetFunctor(type, peddle);

    if (this->hasEventListener(type))
      std::for_each(this->_events.begin(), this->_events.end(), eventFunctor);
    if (peddle && this->getNbChild())
      std::for_each(this->_children.begin(), this->_children.end(), widgetFunctor);
    return (eventFunctor.getNbExecuted() + widgetFunctor.getNbExecuted());
  }

  bool	Widget::hasEventListener(const std::string &type) const
  {
    std::list<EventListener>::const_iterator it;

    it = std::find_if(this->_events.begin(), this->_events.end(), EventListener::Compare(type));
    return (it != this->_events.end() ? true : false);
  }
}
