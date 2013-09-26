//
// CardBoard.cpp for CardBoard in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 02:09:48 2013 ronan guiho
// Last update Fri Jun  7 02:17:47 2013 ronan guiho
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "CardBoard.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	CardBoard::NAME = "cardboard";

CardBoard::CardBoard(Listener *parent, const int life, const int x, const int y,
		     const int z)
  : Decor(parent, life, x, y, z)
{
  this->setType(CardBoard::NAME);
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 1);

  this->addComponent(ptr);
  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + CardBoard::NAME + "/" + CardBoard::NAME + ".fbx", 60));
}

CardBoard::~CardBoard()
{

}
