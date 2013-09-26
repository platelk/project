//
// Bobomb.cpp for Bobomb in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 02:59:03 2013 ronan guiho
// Last update Sun Jun  9 13:09:49 2013 ronan guiho
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "Bobomb.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	Bobomb::NAME = "bombe";

Bobomb::Bobomb(Listener *parent, const int life, const int x,
	       const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 300);

  this->setType(Bobomb::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + Bobomb::NAME + "/" + Bobomb::NAME + ".fbx", 60));
  this->addComponent(ptr);
}

Bobomb::~Bobomb()
{

}

