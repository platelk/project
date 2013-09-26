//
// LogicTree.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Fri May 31 20:21:06 2013 alexis leprovost
//

#include "Trame.hh"
#include "CreateGameObject.hh"
#include "GameObject.hh"
#include "Client/Core.hh"
#include "Client/Event/TrameEvent.hh"
#include "Client/Interface/LogicTree.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/Stage.hh"
#include "Client/Interface/Interface.hh"
#include "Position.hh"

LogicTree::LogicTree()
  : Client::IWidgetObject(Client::Interface::LOGIC_TREE)
{
  if (Daemon::EventTree::core == 0)
    {
      Daemon::GameObject *p = new Daemon::GameObject("logic", 0);
      p->addComponent(new Daemon::CreateGameObject(p));
      Daemon::EventTree::core = new Daemon::Core;
      Daemon::EventTree::core->newEntity(p);
    }
}

LogicTree::~LogicTree()
{

}

bool	LogicTree::isInFieldOfVision(Daemon::GameObject *ref, Daemon::GameObject *toAff, size_t vision)
{
  if (ref->haveComponent(Daemon::Position::NAME) && toAff->haveComponent(Daemon::Position::NAME))
    {
      Daemon::Position *posRef = dynamic_cast<Daemon::Position *>(ref->getComponent(Daemon::Position::NAME));
      Daemon::Position *posAff = dynamic_cast<Daemon::Position *>(toAff->getComponent(Daemon::Position::NAME));

      double vx = posRef->getX() - posAff->getX();
      double vy = posRef->getY() - posAff->getY();
      double dist = vx*vx + vy*vy;

      if (dist >= (vision * vision))
	return false;
      return true;
    }
  return false;
}

void	LogicTree::unLoad()
{
  if (Daemon::EventTree::core)
    {
      Daemon::EventTree::core->reset();
    }
  this->_player_id.clear();
  this->_player.clear();
}

Daemon::GameObject 	*LogicTree::getPlayer(int i) const
{
  if (_player.empty() || static_cast<size_t>(i) >= (_player.size()))
    return 0;
  return this->_player[i];
}

int	LogicTree::getIdPlayer(int i) const
{
  if (_player_id.empty() || static_cast<size_t>(i) >= (_player_id.size()))
    return -1;
  return this->_player_id[i];
}

std::deque<Daemon::GameObject *>&	LogicTree::getGameObject()
{
  return Daemon::EventTree::core->_entity;
}

void	LogicTree::initialize()
{

}

std::string	LogicTree::getMap()
{
  std::string map = "";

  for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); ++i)
    {
      if (Daemon::EventTree::core->_entity[i]->getType() != "player")
	map += Daemon::EventTree::core->_entity[i]->serialize() + "|";
    }
  return map;
}

void	LogicTree::clear()
{
  if (Daemon::EventTree::core)
    {
      Daemon::EventTree::core->reset();
    }
  this->_player_id.clear();
  this->_player.clear();
}

void	LogicTree::update(Client::Event *event)
{
  Client::TrameEvent *ptr = dynamic_cast<Client::TrameEvent*>(event);

  if (ptr)
    {
      Daemon::Trame &trame = ptr->getTrame();
      if (trame.getEvent() == "game_stop")
	{
	  delete Client::Core::network;
	  Client::Core::network = new ClientNetwork;
	  Client::Widget *w = Client::Stage::getInstance()->getState();
	  if (w)
	    {
	      Client::Event e(Client::Event::END, Client::Event::END);
	      w->dispatchEvent(&e);
	    }
	}
      if (trame.getEvent() == "id_player")
	{
	  this->_player_id.push_back(str_to_int(trame.getArgument()));
	}
      for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); ++i)
	{
	  Daemon::EventTree::core->_entity[i]->disperse(trame, false);
	}
      if (trame.getEvent() == "all_player")
	{
	  Client::Widget *w = Client::Stage::getInstance()->getState();
	  if (w)
	    {
	      Client::Event e(Client::Event::SYNCHRONISATION, Client::Event::SYNCHRONISATION);
	      w->dispatchEvent(&e);
	    }
	}
      else if (trame.getEvent() == "start")
	{
	  for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); i++)
	    {
	      if (Daemon::EventTree::core->_entity[i]->getId() == this->getIdPlayer())
		{
		  this->_player.push_back(Daemon::EventTree::core->_entity[i]);
		}
	    }
	  Client::Widget *w = Client::Stage::getInstance()->getState();
	  if (w)
	    {
	      Client::Event e(Client::Event::START, Client::Event::START);
	      w->dispatchEvent(&e);
	    }
	}
    }
  for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); ++i)
    {
      if (Daemon::EventTree::core->_entity[i])
	Daemon::EventTree::core->_entity[i]->update();
    }
}

void	LogicTree::draw()
{

}

void	LogicTree::unload()
{

}
