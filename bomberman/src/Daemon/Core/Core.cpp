//
// Core.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Core.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu May 30 17:22:03 2013 kevin platel
//

#include "Core.hh"
#include "Timer.hh"
#include "EventTree.hh"
#include "Network.hh"
#include "Player.hh"
#include "MapGenerator.hh"
#include <stdlib.h>
#include <unistd.h>

Daemon::Core::Core()
{
}

Daemon::Core::~Core()
{
}

void	Daemon::Core::newGame()
{
}

void	Daemon::Core::endGame()
{
}

bool	Daemon::Core::wait()
{
  Timer	t;
  Trame *trame = 0;
  while (true)
  {
    if (Daemon::EventTree::reseau && !Daemon::EventTree::reseau->isEmpty())
      trame = new Trame(Daemon::EventTree::reseau->pop());
    if (trame && trame->getEvent() == "game_start")
      {
	if (trame->getArgument() != "")
	  {
	    this->reset();
	    trame->setEvent("map");
	    EventTree::pushEvent(trame);
	  }
	return true;
      }
    else if (trame)
      EventTree::pushEvent(trame);
   usleep(10);
   trame = 0;
  }
 return true;
}

bool	Daemon::Core::connection()
{
  Timer	t;
  Trame *trame = 0;

  t.start();
  while (true)
  {
    if (Daemon::EventTree::reseau && !Daemon::EventTree::reseau->isEmpty())
      trame = new Trame(Daemon::EventTree::reseau->pop());
    if (trame && trame->getEvent() == "game_run")
      break;
    else if (trame)
      EventTree::pushEvent(trame);
    trame = 0;
    usleep(200);
  }
 if (t.isTimeOut(60))
   return false;
 return true;
}

bool	Daemon::Core::sync()
{
  Timer	t;
  bool	sync_ok = false;
  Daemon::Networks *n = 0;

 this->init();
 t.start();
 while (!sync_ok && !t.isTimeOut(30))
   {
     sync_ok = true;
     this->getEvent();
      for (size_t i = 0; i < this->_entity.size(); ++i)
	{
	  if (this->_entity[i]->haveComponent("network"))
	    {
	      n = dynamic_cast<Daemon::Networks *>(this->_entity[i]->getComponent("network"));
	      if (n && n->isSync() == false)
		sync_ok = false;
	    }
	}
      usleep(10);
   }
 if (t.isTimeOut(30))
   return false;
 Trame trame(-1, "start", "", "", "", "");
 Daemon::DaemonServer::sendq->push("0", trame.toString());
 return true;
}

void	Daemon::Core::getEvent()
{
  Timer t;
  std::string s = "";
  t.start();
  while (Daemon::EventTree::reseau && !Daemon::EventTree::reseau->isEmpty() && !t.isTimeOut(0.1))
    {
      s = Daemon::EventTree::reseau->pop();
      EventTree::pushEvent(new Daemon::Trame(s));
    }
 t.reset();
}

void  Daemon::Core::loop()
{
  this->getEvent();
  for (size_t i = 0; i < this->_entity.size(); ++i)
    {
      this->_entity[i]->update();
    }
}

void	Daemon::Core::run()
{
  Timer t;

  sleep(1);
  this->initEntity();
  this->_is_running = true;
  while (this->_is_running)
    {
      this->loop();
      t.start();
      usleep(40);
      t.reset();
   }
 }

void  Daemon::Core::reset()
{
  while (!this->_entity.empty())
  {
    GameObject *ptr = this->_entity.front();
    this->_entity.pop_front();
    delete ptr;
  }
}

void	Daemon::Core::stop()
{
  this->_is_running = false;
}

std::string	Daemon::Core::getMap()
{
  std::string map = "";

  for (size_t i = 0; i < this->_entity.size(); ++i)
    {
      if (this->_entity[i]->getType() != "player")
	map += this->_entity[i]->serialize() + "|";
    }
  return map;
}

std::string	Daemon::Core::getPlayer()
{
  std::string player = "";
  MapGenerator gen(6000, 6000, 0.80, 1100, 1400, 100);

  for (size_t i = 0; i < this->_entity.size(); ++i)
    {
      if (this->_entity[i]->getType() == Player::NAME)
	{
	  gen.positionObject(this->_entity[i]);
	  player += this->_entity[i]->serialize() + "|";
	}
    }
  return player;
}

void	Daemon::Core::init()
{
  Trame *trame = new Trame(-1, "map", "", "", "", this->getMap());

  Daemon::DaemonServer::sendq->push("0", trame->toString());
  delete trame;
  sleep(1);
  trame = new Trame(-1, "all_player", "", "", "", this->getPlayer());
  Daemon::DaemonServer::sendq->push("0", trame->toString());
  delete trame;
}

void	Daemon::Core::initEntity()
{
  for (size_t i = 0; i < this->_entity.size(); ++i)
    {
      this->_entity[i]->init();
    }
}

void	Daemon::Core::newEntity(Daemon::GameObject *n)
{
  if (n)
    {
      LockScope a(this->_mutex);
      this->_entity.push_back(n);
    }
}

void	Daemon::Core::removeEntity(GameObject *n)
{
  for (std::deque<Daemon::GameObject *>::iterator i = this->_entity.begin(); i != this->_entity.end(); ++i)
    {
      if (*i == n)
	{
	  LockScope a(this->_mutex);
	  this->_entity.erase(i);
	  break;
	}
    }
}
