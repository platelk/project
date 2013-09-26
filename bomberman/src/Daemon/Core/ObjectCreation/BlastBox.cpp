//
// BlastBox.cpp for BlastBox in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 03:23:35 2013 ronan guiho
// Last update Tue Jun 11 11:40:52 2013 alexis leprovost
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "BlastBox.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"
#include "Explose.hh"

const std::string	BlastBox::NAME = "blastbox";

BlastBox::BlastBox(Listener *parent, const int life, const int x,
	       const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 350);

  // this->setType(BlastBox::NAME);
  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + BlastBox::NAME + "/" + BlastBox::NAME + ".fbx", 35));
  this->addComponent(ptr);
  this->addComponent(new Daemon::Explose(this, 30000000, 3000, 40));
}

BlastBox::~BlastBox()
{

}
