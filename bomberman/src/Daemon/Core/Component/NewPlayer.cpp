//
// NewPlayer.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/NewPlayer.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon May 20 18:43:12 2013 kevin platel
// Last update Fri Jun  7 11:43:44 2013 phalip_z
//

#include <string>

#include "EventTree.hh"
#include "NewPlayer.hh"
#include "Network.hh"
#include "Player.hh"
#include "utils.hh"

const	std::string	Daemon::NewPlayer::NAME = "new_player";

Daemon::NewPlayer::NewPlayer(Daemon::GameObject *owner)
  : AComponent(NewPlayer::NAME, "", owner)
{
  if (owner)
    {
      owner->addEvent("new_player", new Action<NewPlayer>(*this, &Daemon::NewPlayer::eventAddPlayer));
      this->_isInit = true;
    }
}

Daemon::NewPlayer::~NewPlayer()
{
  if (this->_owner && this->_isInit)
    {
      this->_owner->removeEvent("new_player");
    }
}

void	Daemon::NewPlayer::init()
{
  if (this->_owner && !this->_isInit)
    {
      this->_owner->addEvent("new_player", new Action<NewPlayer>(*this, &Daemon::NewPlayer::eventAddPlayer));
      this->_isInit = true;
    }
}

void	Daemon::NewPlayer::addPlayer(const std::string &id)
{
  Player	*ptr = new Player(this->_owner, id, 80);
  this->_owner->addChild(ptr);
  Daemon::Networks *net = dynamic_cast<Daemon::Networks *>(ptr->getComponent("network"));
  Trame *trame = new Trame(-1, "id_player", "", "", "", int_to_str(ptr->getId()));
  net->sendTo(trame->toString());
}

void	Daemon::NewPlayer::eventAddPlayer(Trame &trame)
{
  this->addPlayer(trame.getArgument());
}

void	Daemon::NewPlayer::update()
{
}

std::string	Daemon::NewPlayer::serialize()
{
  return this->createPackage("");
}

Daemon::NewPlayer	*Daemon::NewPlayer::unserialize(std::stringstream &s, Daemon::GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new NewPlayer(owner);
}

Daemon::NewPlayer	*Daemon::NewPlayer::clone(Daemon::GameObject *owner) const
{
  return new NewPlayer(owner);
}
