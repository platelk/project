//
// EventTree.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Event/EventTree.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Thu May  9 18:51:55 2013 vink
// Last update Sun Jun  9 21:42:55 2013 kevin platel
//

#include <iostream>
#include "EventTree.hh"
#include "Life.hh"
#include "Player.hh"

Mutex					Daemon::EventTree::_mutex;
ThreadPool<Daemon::Trame *, int>	Daemon::EventTree::_event(10, 10, Daemon::EventTree::spread);;
Daemon::Listener			*Daemon::EventTree::root;
Daemon::ExecuteQueue<std::string>	*Daemon::EventTree::reseau = 0;
Daemon::Core				*Daemon::EventTree::core = 0;

Daemon::EventTree::EventTree()
{
}

Daemon::EventTree::~EventTree()
{
}

void	Daemon::EventTree::pushEvent(Daemon::Trame *trame)
{
  static Daemon::Trame *t = 0;
  if (t != trame)
    {
      _event.sendRessource(trame);
    }
  t = trame;
}

void	Daemon::EventTree::resolve()
{

}

int	Daemon::EventTree::spread(Daemon::Trame *trame)
{
  if (trame->exec)
    {
      root->disperse(*trame, true);
      trame->exec = false;
      return 0;
    }
  return 1;
}
