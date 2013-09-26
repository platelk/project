//
// BonusBox.cpp for BonusBox in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sun Jun  9 00:55:42 2013 ronan guiho
// Last update Sun Jun  9 14:27:21 2013 ronan guiho
//

#include "BonusBox.hh"
#include "BonusRender.hh"
#include "Position.hh"
#include "Bonus.hh"
#include "Life.hh"
#include "BonusRender.hh"

const std::string &BonusBox::NAME = "bonusBox";

BonusBox::BonusBox(Listener *owner, const std::string &id, int x, int y, int z, const float size)
  : Box(owner, id, x, y, z, size)
{
  Daemon::Life *l = new Daemon::Life(this, 1, 1);

  l->damage(false);
  this->addComponent(new Daemon::BonusRender(this, "", size, "assets/clips/world/bonus.png"));
  this->addComponent(l);
}

BonusBox::~BonusBox()
{
}
