//
// Palm.cpp for Palm in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 14:23:48 2013 ronan guiho
// Last update Sat Jun  8 21:40:41 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "Palm.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	Palm::NAME = "palm";

Palm::Palm(Listener *parent, const int life, const int x,
		 const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 30);

  // this->setType(Palm::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + Palm::NAME + "/" + Palm::NAME + ".fbx", 12));
  this->addComponent(ptr);
}

Palm::~Palm()
{

}
