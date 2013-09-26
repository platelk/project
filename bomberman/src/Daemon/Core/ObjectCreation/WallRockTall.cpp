//
// WallRockTall.cpp for WallRockTall in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sat Jun  8 02:15:19 2013 ronan guiho
// Last update Sun Jun  9 15:37:10 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "WallRockTall.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"

const std::string	WallRockTall::NAME = "rock_big";

WallRockTall::WallRockTall(Listener *parent, const int life, const int x,
		 const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 400);

  // this->setType(WallRockTall::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + WallRockTall::NAME + "/" + WallRockTall::NAME + ".fbx", 50.0f));
  this->addComponent(ptr);
  this->removeComponent(Daemon::Life::NAME);
}

WallRockTall::~WallRockTall()
{
}
