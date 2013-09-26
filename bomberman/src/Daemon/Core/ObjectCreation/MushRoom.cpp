//
// MushRoom.cpp for MushRoom in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 02:25:04 2013 ronan guiho
// Last update Fri Jun  7 02:34:27 2013 ronan guiho
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "MushRoom.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	MushRoom::NAME = "mushroom";

MushRoom::MushRoom(Listener *parent, const int life, const int x,
		   const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 300);

  this->setType(MushRoom::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + MushRoom::NAME + "/" + MushRoom::NAME + ".fbx", 300));
  this->addComponent(ptr);
}

MushRoom::~MushRoom()
{

}
