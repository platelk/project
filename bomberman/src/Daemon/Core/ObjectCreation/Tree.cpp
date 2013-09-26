//
// Tree.cpp for Tree in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 14:35:42 2013 ronan guiho
// Last update Sat Jun  8 21:44:14 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "Tree.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	Tree::NAME = "tree";

Tree::Tree(Listener *parent, const int life, const int x,
	   const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 300);

  // this->setType(Tree::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + Tree::NAME + "/" + Tree::NAME + ".fbx", 7));
  this->addComponent(ptr);
}

Tree::~Tree()
{

}
