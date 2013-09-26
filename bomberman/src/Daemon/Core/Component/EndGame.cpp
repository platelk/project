//
// EndGame.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/EndGame.cpp in /home/vink/projet/cpp/bomberman/test
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon May 27 00:02:33 2013 kevin platel
// Last update Tue Jun 11 11:45:19 2013 alexis leprovost
//

#include <string>

#include "EventTree.hh"
#include "EndGame.hh"
#include "Network.hh"
#include "Player.hh"
#include "utils.hh"

const std::string	Daemon::EndGame::NAME = "end_game";

Daemon::EndGame::EndGame(Daemon::GameObject *owner, double over)
  : AComponent(EndGame::NAME, "", owner), _over(over)
{
  if (this->_owner)
    {
      this->_owner->addEvent("force_end", new Action<EndGame>(*this, &Daemon::EndGame::eventEnd));
      this->_isInit = true;
    }
}

Daemon::EndGame::~EndGame()
{
  if (this->_owner)
    {
      this->_owner->removeEvent("force_end");
    }
}

void	Daemon::EndGame::init()
{
  if (this->_owner)
    {
      this->_owner->addEvent("force_end", new Action<EndGame>(*this, &Daemon::EndGame::eventEnd));
      this->_isInit = true;
    }
  this->t.start();
}

void	Daemon::EndGame::update()
{
  bool	end = false;
  int	count = 0;

  for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); i++)
    {
      if (Daemon::EventTree::core->_entity[i]->getType() == Player::NAME)
	{
	  count++;
	}
      i++;
    }
  if (this->t.isTimeOut(this->_over))
    {
      end = true;
    }
  if (end)
    {
      Daemon::Trame trame(-1, "game_stop", "", "", "", "");
      Daemon::EventTree::core->stop();
      Daemon::DaemonServer::sendq->push("0", trame.toString());
    }
}

void	Daemon::EndGame::eventEnd(Trame &)
{
      Daemon::Trame trame(-1, "game_stop", "", "", "", "");
      Daemon::EventTree::core->stop();
      Daemon::DaemonServer::sendq->push("0", trame.toString());
}

std::string	Daemon::EndGame::serialize()
{
  return this->createPackage("");
}

Daemon::EndGame	*Daemon::EndGame::unserialize(std::stringstream &s, Daemon::GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new EndGame(owner);
}

Daemon::EndGame	*Daemon::EndGame::clone(Daemon::GameObject *owner) const
{
  return new EndGame(owner);
}
