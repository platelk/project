//
// BarrelWood.cpp for BarrelWood in /home/guiho_r/depot/bomberman/src/Tools
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 15:55:12 2013 ronan guiho
// Last update Sun Jun  9 03:16:04 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "BarrelWood.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	BarrelWood::NAME = "barrel_wood";

BarrelWood::BarrelWood(Listener *parent, const int life, const int x,
		 const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 200);

  // this->setType(BarrelWood::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + BarrelWood::NAME + "/" + BarrelWood::NAME + ".fbx", 60));
  this->addComponent(ptr);
}

BarrelWood::~BarrelWood()
{

}
