//
// SandGround.cpp for SandGround in /home/guiho_r/depot/bomberman/src/Daemon/Core/Component
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 21:36:01 2013 ronan guiho
// Last update Sun Jun  9 11:06:08 2013 ronan guiho
//


#include "SandGround.hh"
#include "Position.hh"

const std::string &SandGround::NAME = "sand";

SandGround::SandGround(Listener *owner, const std::string &id, int x, int y, int z, const float width, const float heigth)
  : Ground(owner, id, x, y, z)
{
  this->addComponent(new Daemon::GroundRender(this, "assets/clips/world/generic_grass1_col.jpg", width, heigth));
}

SandGround::~SandGround()
{
}
