//
// ClientGame.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/ClientGame.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Sun May 12 15:03:04 2013 vink
// Last update Sat May 25 18:51:52 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "ClientGame.hh"
#include "ThrowBomb.hh"
#include "Position.hh"
#include "Move.hh"
#include "Colider.hh"
#include "Network.hh"
#include "CreateGameObject.hh"

ClientGame::ClientGame(Listener *parent)
: GameObject("client_game", parent)
{
  this->addComponent(new Daemon::Networks(this, "0"));
  this->addComponent(new Daemon::CreateGameObject(this));
}

ClientGame::~ClientGame()
{

}

ClientGame	*ClientGame::clone(Listener *parent) const
{
  return  new ClientGame(parent);
}

void	ClientGame::setNetId(const std::string &id)
{
  Daemon::Networks *ptr = dynamic_cast<Daemon::Networks *>(this->getComponent("network"));
  ptr->setId(id);
}

std::string	ClientGame::getNetId()
{
  Daemon::Networks *ptr = dynamic_cast<Daemon::Networks *>(this->getComponent("network"));
  return ptr->getId();
}
