//
// BlastBox.cpp for BlastBox in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 03:23:35 2013 ronan guiho
// Last update Sun Jun  9 03:16:09 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "BarrelElect.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	BarrelElect::NAME = "barrel_elec";

BarrelElect::BarrelElect(Listener *parent, const int life, const int x,
	       const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 300);

  // this->setType(BarrelElect::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + BarrelElect::NAME + "/" + BarrelElect::NAME + ".fbx", 60));
  this->addComponent(ptr);
}

BarrelElect::~BarrelElect()
{

}
