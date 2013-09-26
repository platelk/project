//
// GameObject.cpp for bomber in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Fri May 31 17:28:26 2013 alexis leprovost
// Last update Sun Jun  9 21:22:13 2013 kevin platel
//

#include "GameObject.hh"
#include "EventTree.hh"
#include "Factory.hh"
#include <cstring>

const std::string &Daemon::GameObject::NAME = "game_object";

Daemon::GameObject::GameObject(const std::string &type, Listener *parent)
  : AEntity(type, parent)
{
  if (Daemon::EventTree::core)
    Daemon::EventTree::core->newEntity(this);
  this->hasBeenModify = false;
}

Daemon::GameObject::~GameObject()
{
  std::map<std::string, AComponent *>::iterator it = this->_component.begin();

  for (; it != this->_component.end(); ++it)
    {
      if (it->second->getFamily() != "render")
	delete it->second;
    }
  if (Daemon::EventTree::core)
    Daemon::EventTree::core->removeEntity(this);
}

void	Daemon::GameObject::update()
{
  std::map<std::string, AComponent *>::iterator it = this->_component.begin();

  if (this->_component.size() > 0)
    {
      for (; it != this->_component.end(); ++it)
	{
	  if (it->second)
	    {
	      (it->second)->update();
	    }
	}
    }
  if (this->hasBeenModify)
    {
      this->hasBeenModify = false;
      Trame trame(this->getId(), "tile", this->getType(), "", int_to_str(this->getId()), this->serialize());
      if (this->getType() == "player")
	trame.setEvent("player");
      Daemon::DaemonServer::sendq->push("0", trame.toString());
    }
}

bool	Daemon::GameObject::haveComponent(const std::string &component) const
{
  if (this->_component.size() == 0)
    return false;
  return (this->_component.find(component) != this->_component.end());
}

bool	Daemon::GameObject::haveComponentFamily(const std::string &name) const
{
  std::map<std::string, AComponent *>::const_iterator it = this->_component.begin();

  for (; it != this->_component.end(); ++it)
    {
      if ((it->second)->getFamily() == name)
	return true;
    }
  return false;
}

void	Daemon::GameObject::addComponent(AComponent *comp)
{
  this->_component[comp->getName()] = comp;
};

void	Daemon::GameObject::removeComponent(const std::string &name)
{
  if (this->haveComponent(name))
    {
      std::map<std::string, AComponent *>::iterator it = this->_component.find(name);

      delete it->second;
      it->second = 0;
      this->_component.erase(it);
    }
}

void	Daemon::GameObject::unrefComponent(const std::string &name)
{
  if (this->haveComponent(name))
    {
      std::map<std::string, AComponent *>::iterator it = this->_component.find(name);
      it->second = 0;
      this->_component.erase(it);
    }
}

Daemon::AComponent*	Daemon::GameObject::getComponent(const std::string &name)
{
  if (this->haveComponent(name))
    return this->_component[name];
  return (0);
}

Daemon::AComponent*	Daemon::GameObject::getComponentFamily(const std::string &name)
{
  std::map<std::string, AComponent *>::iterator it = this->_component.begin();

  while (it != this->_component.end())
    {
      if ((it->second)->getFamily() == name)
	return it->second;
      it++;
    }
  return (0);
}

void		Daemon::GameObject::init()
{
  std::map<std::string, AComponent *>::iterator it = this->_component.begin();

  while (it != this->_component.end())
    {
      if (it->second)
	{
	  (it->second)->init();
	}
      it++;
    }
}

void		Daemon::GameObject::transfertIn(GameObject &g)
{
  std::map<std::string, AComponent *>::iterator it = this->_component.begin();

  while (it != this->_component.end())
    {
      if (it->second)
	{
	  g.removeComponent(it->first);
	  g.addComponent((it->second)->clone(&g));
	  delete it->second;
	  this->_component.erase(it);
	  it = this->_component.begin();
	}
      else
	it++;
    }
  this->_component.clear();
}

std::string			Daemon::GameObject::serializeComponent()
{
  std::string	s = "";

  if (!this->_component.empty())
    {
      for (std::map<std::string, AComponent *>::iterator i = this->_component.begin(); i != this->_component.end(); ++i)
	{
	  if (i->second)
	    {
	      s += ((i)->second)->serialize();
	      s += ";";
	    }
	}
    }
  return s;
}

std::string			Daemon::GameObject::serialize()
{
  std::stringstream ss;
  std::string cp = this->serializeComponent();

  ss << "GO:" << (this->getType()).size() << ":" << (this->getType()) << ":" << int_to_str(this->getId()).size() << ":" << this->getId() << ":" << (cp.size() + 2 - 1) << ":{" << cp.substr(0, cp.size()-1) << "}";
  return ss.str();
}

Daemon::GameObject			Daemon::GameObject::operator=(GameObject const &obj)
{
  return GameObject(obj.getType(), obj.getParent());
}

Daemon::GameObject			*Daemon::GameObject::clone(Listener *owner) const
{
  GameObject *obj = new GameObject(this->getType(), owner);
  std::map<std::string, AComponent *>::const_iterator it = this->_component.begin();

  while (it != this->_component.end())
    {
      obj->addComponent((it->second)->clone(obj));
      it++;
    }

  return obj;
}

bool 			Daemon::GameObject::operator==(GameObject const &obj)
{
  return (this->getType() == obj.getType());
}

void			Daemon::GameObject::unserializeComponent(std::stringstream &ss)
{
  size_t size;
  AComponent	*c;
  AComponent	*a;

  ss >> size;
  if (ss.get() == ':' && ss.get() == '{')
    {
      while (ss)
	{
	  char	buff[4];
	  ss.read(buff, 3);
	  buff[3] = 0;
	  if (std::string(buff) == "CP:")
	    {
	      size_t to_read;

	      ss >> to_read;
	      ss.get();
	      char	buffer[to_read+1];
	      bzero(buffer, to_read+1);
	      ss.read(buffer, to_read+1);
	      buffer[to_read] = 0;
	      c = ComponentFactory::factory.create(buffer);
	      if (c)
		{
		  a = c->unserialize(ss, this);
		  a->setOwner(this);
		  this->addComponent(a);
		  c = 0;
		}
	    }
	  if (ss.get() != ';')
	    break;
	}
    }
}

Daemon::GameObject			*Daemon::GameObject::unserialize(const std::string &s)
{
  std::stringstream	ss;
  char	buff[] = "    ";

  ss << s;
  if (ss)
    ss.read(buff, 3);
  buff[3] = 0;
  if (std::string(buff) != "GO:")
    return 0;
  int size;
  if (ss)
    ss >> size;
  if (ss)
    ss.get();
  if (size < 0)
    return 0;
  char	buffer[size+1];
  ss.read(buffer, size);
  buffer[size] = 0;
  /*
  ** TO DO : appeler la factory a la place
  */
  GameObject *n = new GameObject(std::string(buffer));
  if (ss)
    ss.get();
  if (ss)
    ss >> size;
  if (ss)
    ss.get();
  if (ss)
    ss.read(buffer, size);
  buffer[size] = 0;
  n->setId(str_to_int(buffer));
  if (ss)
    ss.get();
  n->unserializeComponent(ss);
  return n;
}
