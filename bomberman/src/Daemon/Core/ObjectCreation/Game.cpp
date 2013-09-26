//
// Game.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/Game.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue May 21 17:14:37 2013 kevin platel
// Last update Sun Jun  9 17:13:10 2013 kevin platel
//

#include "Game.hh"
#include "NewPlayer.hh"
#include "Network.hh"
#include "EndGame.hh"
#include "CreateGameObject.hh"
#include "SelectPlayer.hh"
#include "Update.hh"

const std::string NAME = "game";

Game::Game(Listener *parent)
  : GameObject("game", parent)
{
  Daemon::Networks *n = new Daemon::Networks(this, "0");

  n->sync(true);
  this->addComponent(new Daemon::NewPlayer(this));
  this->addComponent(n);
  this->addComponent(new Daemon::EndGame(this, 90));
  this->addComponent(new Daemon::CreateGameObject(this));
  this->addComponent(new Daemon::SelectPlayer(this));
  this->addComponent(new Daemon::Update(this));
}

Game::~Game()
{
}

Game	*Game::clone(Daemon::Listener *parent) const
{
  return new Game(parent);
}
