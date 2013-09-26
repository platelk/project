//
// SelectPlayer.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/SelectPlayer.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Jun  3 13:34:09 2013 kevin platel
// Last update Sat Jun  8 07:48:11 2013 kevin platel
//

#include "SelectPlayer.hh"
#include "EventTree.hh"
#include "Player.hh"
#include "Factory.hh"

namespace Daemon
{
  const	std::string	SelectPlayer::NAME = "select_player";

  SelectPlayer::SelectPlayer(GameObject *owner)
    : AComponent(SelectPlayer::NAME, "", owner)
  {
    if (owner)
      {
	owner->addEvent("select_player", new Action<SelectPlayer>(*this, &SelectPlayer::eventSelectPlayer));
	this->_isInit = true;
      }
  }

  SelectPlayer::~SelectPlayer()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("select_player");
      }
  }

  void	SelectPlayer::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("select_player", new Action<SelectPlayer>(*this, &SelectPlayer::eventSelectPlayer));
	this->_isInit = true;
      }
  }

  void	SelectPlayer::eventSelectPlayer(Trame &trame)
  {
    long	id = -1;

    for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); i++)
      {
	if (Daemon::EventTree::core->_entity[i]->getId() == trame.getId())
	  {
	    id = i;
	    break;
	  }
      }
    if (id >= 0)
      this->selectPlayer(id, trame.getArgument());
  }

  void	SelectPlayer::selectPlayer(int id, const std::string &player)
  {
    GameObject	*ptr = 0;
    ptr = dynamic_cast<Player *>(Daemon::EventTree::core->_entity.at(id));
    if (ptr)
      {
	GameObject	*character = 0;
	character = GameObjectFactory::factory.create(Daemon::GameObject::NAME, player, 0);
	if (character)
	  {
	    character->transfertIn(*ptr);
	    Daemon::EventTree::core->removeEntity(character);
	    delete character;
	  }
      }
  }

  void	SelectPlayer::update()
  {
  }

  std::string	SelectPlayer::serialize()
  {
    return this->createPackage("");
  }

  SelectPlayer*	SelectPlayer::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new SelectPlayer(owner);
  }

  SelectPlayer*	SelectPlayer::clone(GameObject *owner) const
  {
    return new SelectPlayer(owner);
  }
}
