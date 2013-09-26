//
// Player.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Player.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Sun May 12 15:03:04 2013 vink
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "Player.hh"
#include "ThrowBomb.hh"
#include "Position.hh"
#include "Move.hh"
#include "Colider.hh"
#include "Network.hh"
#include "Render.hh"
#include "PlayerRender.hh"
#include "Characteristic.hh"
#include "Update.hh"
#include "Store.hh"
#include "LevelUp.hh"

const std::string	Player::NAME = "player";

Player::Player(Listener *parent, const std::string &id, int life, int x, int y, int z)
  : GameObject(Player::NAME, parent)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 200);
  Daemon::Store *st = new Daemon::Store(this);
  st->newStock("bomb", 5, 3);

  this->addComponent(ptr);
  this->addComponent(new Daemon::Life(this, life, life));
  this->addComponent(new Daemon::Position(this, x, y, z));
  this->addComponent(new Daemon::Move(this));
  this->addComponent(new Daemon::ThrowBomb(this, 3));
  this->addComponent(new Daemon::Networks(this, id));
  this->addComponent(new Daemon::Update(this));
  this->addComponent(new Daemon::Characteristic(this));
}

Player::~Player()
{

}

Player	*Player::clone(Listener *parent) const
{
  Player	*obj = new Player(parent);

  obj->removeComponent(Daemon::Networks::NAME);
  obj->removeComponent(Daemon::PlayerRender::NAME);
  std::map<std::string, Daemon::AComponent *>::const_iterator it = this->_component.begin();

  if (this->_component.size())
    {
      while (it != this->_component.end())
  	{
	  if (it->first != Daemon::Networks::NAME)
	    obj->addComponent((it->second)->clone(obj));
	  it++;
  	}
    }

  return obj;
}

void	Player::setNetId(const std::string &id)
{
  Daemon::Networks *ptr = dynamic_cast<Daemon::Networks *>(this->getComponent("network"));
  ptr->setId(id);
}

std::string	Player::getNetId()
{
  Daemon::Networks *ptr = dynamic_cast<Daemon::Networks *>(this->getComponent("network"));
  return ptr->getId();
}
