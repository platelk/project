//
// Factory.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Fri May 31 17:12:38 2013 alexis leprovost
// Last update Fri May 31 17:19:03 2013 alexis leprovost
//

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "Listener.hh"
#include "AComponent.hh"
#include "GameObject.hh"
#include "Factory.hpp"

class ComponentFactory : public Factory<Daemon::AComponent *>
{
public:
  ComponentFactory();
  ~ComponentFactory();

  Daemon::AComponent *create(const std::string &key, Daemon::GameObject *owner = 0) const;
  static ComponentFactory	factory;
};

class GameObjectFactory : public Factory<Daemon::GameObject *>
{
public:
  GameObjectFactory();
  ~GameObjectFactory();

  Daemon::GameObject	*create(const std::string &key, Daemon::Listener *parent = 0) const;
  Daemon::GameObject	*create(const std::string &key, const std::string &data, Daemon::Listener *parent = 0) const;
  void			update(const std::string &key, Daemon::AComponent *comp);

  static GameObjectFactory	factory;
};

#endif
