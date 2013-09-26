//
// Factory.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Tools
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Fri May 31 17:04:01 2013 alexis leprovost
// Last update Sat Jun  1 12:29:36 2013 kevin platel
//

#include "Factory.hh"

GameObjectFactory	GameObjectFactory::factory;
ComponentFactory	ComponentFactory::factory;

GameObjectFactory::GameObjectFactory()
{

}

GameObjectFactory::~GameObjectFactory()
{

}

Daemon::GameObject	*GameObjectFactory::create(const std::string &key, Daemon::Listener *owner) const
{
  std::map<std::string, Daemon::GameObject *>::const_iterator	it = this->_man.find(key);

  if (it != this->_man.end())
    return (((*it).second)->clone(owner));
  return (0);
}

Daemon::GameObject	*GameObjectFactory::create(const std::string &key, const std::string &data, Daemon::Listener *owner) const
{
  std::map<std::string, Daemon::GameObject *>::const_iterator	it = this->_man.find(key);

  if (it != this->_man.end())
    {
      Daemon::GameObject *ptr = (((*it).second)->unserialize(data));
      if (ptr)
	ptr->setParent(owner);
      return ptr;
    }
  return (0);
}

void                GameObjectFactory::update(const std::string &key, Daemon::AComponent *comp)
{
  std::map<std::string, Daemon::GameObject *>::const_iterator    it = this->_man.find(key);

  if (it != this->_man.end())
    {
      (it->second)->addComponent(comp);
    }
}

ComponentFactory::ComponentFactory()
{

}

ComponentFactory::~ComponentFactory()
{

}

Daemon::AComponent	*ComponentFactory::create(const std::string &key, Daemon::GameObject *owner) const
{
  std::map<std::string, Daemon::AComponent *>::const_iterator	it = this->_man.find(key);
  if (it != this->_man.end())
    return (((*it).second)->clone(owner));
  return (0);
}
