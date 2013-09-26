//
// CreateGameObject.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/CreateGameObject.cpp in /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon May 27 12:35:39 2013 kevin platel
// Last update Mon Jun 10 15:41:59 2013 kevin platel
//

#include <string>

#include "Factory.hh"
#include "EventTree.hh"
#include "CreateGameObject.hh"
#include "Network.hh"
#include "Player.hh"
#include "utils.hh"

const std::string	Daemon::CreateGameObject::NAME = "create_game_object";

Daemon::CreateGameObject::CreateGameObject(Daemon::GameObject *owner)
  : AComponent(CreateGameObject::NAME, "", owner)
{
  if (owner)
    {
      owner->addEvent("map", new Action<CreateGameObject>(*this, &Daemon::CreateGameObject::eventMap));
      owner->addEvent("all_player", new Action<CreateGameObject>(*this, &Daemon::CreateGameObject::eventPlayer));
      this->_isInit = true;
    }
}

Daemon::CreateGameObject::~CreateGameObject()
{
if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("map");
      this->_owner->removeEvent("all_player");
    }
}

void	Daemon::CreateGameObject::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("map", new Action<CreateGameObject>(*this, &Daemon::CreateGameObject::eventMap));
      this->_owner->addEvent("all_player", new Action<CreateGameObject>(*this, &Daemon::CreateGameObject::eventPlayer));
      this->_isInit = true;
    }
}

void	Daemon::CreateGameObject::createMap(const std::string &map)
{
  if (!map.empty())
    {
      std::vector<std::string> v = split_string(map, '|');
      Daemon::GameObject *ptr = 0;
      while (!v.empty())
	{
	  ptr = GameObjectFactory::factory.create("game_object", v.back(), this->_owner);
	  if (ptr)
	    {
	      this->_owner->addChild(ptr);
	    }
	  v.pop_back();
	}
    }
}

void	Daemon::CreateGameObject::createPlayer(const std::string &map)
{
  if (!map.empty())
    {
      std::vector<std::string> v = split_string(map, '|');
      Daemon::GameObject *ptr = 0;
      while (!v.empty())
	{
	  ptr = GameObjectFactory::factory.create("player", v.back(), this->_owner);
	  if (ptr)
	    {
	      this->_owner->addChild(ptr);
	    }
	  v.pop_back();
	}
    }
}

void	Daemon::CreateGameObject::eventMap(Daemon::Trame &trame)
{
  this->createMap(trame.getArgument());
}

void	Daemon::CreateGameObject::eventPlayer(Daemon::Trame &trame)
{
  this->createPlayer(trame.getArgument());
}

void	Daemon::CreateGameObject::update()
{
}

std::string	Daemon::CreateGameObject::serialize()
{
  return this->createPackage("");
}

Daemon::CreateGameObject	*Daemon::CreateGameObject::unserialize(std::stringstream &s, Daemon::GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new CreateGameObject(owner);
}

Daemon::CreateGameObject	*Daemon::CreateGameObject::clone(Daemon::GameObject *owner) const
{
  return new CreateGameObject(owner);
}
