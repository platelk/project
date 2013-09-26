//
// Listener.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Event/Listener.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Fri May 10 19:52:33 2013 vink
// Last update Mon Jun 10 00:24:41 2013 kevin platel
//

#include <iostream>
#include <algorithm>

#include "utils.hh"
#include "Listener.hh"

size_t Daemon::Listener::_id = 1;

Daemon::Listener::Listener(const std::string & type, Daemon::Listener *parent)
  : _my_id(Daemon::Listener::_id), _type(type), _parent(parent)
{
  Daemon::Listener::_id++;
  if (parent)
    parent->addChild(this);
}

Daemon::Listener::~Listener()
{
}

void	Daemon::Listener::addEvent(const std::string &event, Daemon::IAction *action)
{
  this->_listen[event] = action;
}

void	Daemon::Listener::addEvent(Daemon::Trame &trame, Daemon::IAction *action)
{
  this->addEvent(trame.getEvent(), action);
}

bool	Daemon::Listener::execEvent(Daemon::Trame &trame)
{
  bool	id = true;
  bool	type = true;
  std::vector<std::string> v_type = trame.getTargetType();
  std::vector<std::string> v_id = trame.getTargetId();

  for (size_t i = 0; i < v_id.size(); i++)
    {
      id = false;
      if (this->getId() == str_to_int(v_id[i]))
	{
	  id = true;
	  break;
	}
    }
  for (size_t i = 0; i < v_type.size(); i++)
    {
      type = false;
      if (this->getType() == v_type[i])
	{
	  type = true;
	  break;
	}
    }
  if (id && type && this->isListen(trame))
    {
      (*(this->_listen[trame.getEvent()]))(trame);
      return true;
    }
  return false;
}

void	Daemon::Listener::sendEvent(Daemon::Trame &trame, bool spread)
{
  LockScope a(this->_mutex);

  for (size_t i = 0; i < this->_child.size(); i++)
    {
      (this->_child[i])->disperse(trame, spread);
    }
}

void	Daemon::Listener::disperse(Daemon::Trame &trame, bool spread)
{
  LockScope a(this->_mutex);

  if (this->execEvent(trame) || spread)
    this->sendEvent(trame, spread);
  this->clear();
}

void	Daemon::Listener::removeEvent(const std::string &event)
{
  LockScope a(this->_mutex);
  std::map<std::string, Daemon::IAction * >::iterator it;

  if ((it = this->_listen.find(event)) != this->_listen.end())
    {
      this->_listen.erase(it);
    }
}

void	Daemon::Listener::clearEvent()
{
  LockScope a(this->_mutex);

  this->_listen.clear();
}

void	Daemon::Listener::removeEvent(Daemon::Trame &trame)
{
  LockScope a(this->_mutex);
  this->removeEvent(trame.getEvent());
}

bool	Daemon::Listener::isListen(const std::string &event)
{
  return (this->_listen.find(event) != this->_listen.end());
}

bool	Daemon::Listener::isListen(Daemon::Trame &trame)
{
  return this->isListen(trame.getEvent());
}

void	Daemon::Listener::addChild(Daemon::Listener *child)
{
  LockScope a(this->_mutex);
  for (size_t i = 0; i < this->_child.size(); i++)
    {
      if (this->_child[i]->getId() == child->getId())
	return ;
    }

  this->_child.push_back(child);
}

void	Daemon::Listener::removeChild(Daemon::Listener *child)
{
  std::deque<Listener *>::iterator it;
  if ((it = find(this->_child.begin(), this->_child.end(), child)) != this->_child.end())
    {
      this->_child.erase(it);
    }
}

bool	Daemon::Listener::findParent(Daemon::Listener *child, const std::string &parent_type)
{
  if (!child)
    return false;
  if (parent_type == this->getType())
    {
      child->setParent(this);
      this->addChild(child);
      return true;
    }
  else
    {
      for (std::deque<Listener *>::iterator i = this->_child.begin(); i != this->_child.end(); ++i)
	{
	  if ((*i)->findParent(child, parent_type))
	    return true;
	}
    }
  return false;
}

void		Daemon::Listener::toDelete(Listener *child)
{
  if (child)
    this->_to_delete.push(child);
}

void		Daemon::Listener::clear()
{
  while (!this->_to_delete.empty())
    {
      this->removeChild(this->_to_delete.top());
      this->_to_delete.pop();
    }
}

std::string	Daemon::Listener::getType() const
{
  return this->_type;
}

int			Daemon::Listener::getId() const
{
  return this->_my_id;
}

Daemon::Listener*		Daemon::Listener::getParent() const
{
  return this->_parent;
}

void			Daemon::Listener::setType(const std::string &type)
{
  this->_type = type;
}

void			Daemon::Listener::setParent(Daemon::Listener *parent)
{
  this->_parent = parent;
}

void			Daemon::Listener::setId(size_t id)
{
  this->_my_id = id;
}
