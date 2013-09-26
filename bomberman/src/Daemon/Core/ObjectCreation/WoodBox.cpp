//
// WoodBox.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/ObjectCreation/WoodBox.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Jun  4 18:04:52 2013 kevin platel
//

#include "ObjectCreation.hh"
#include "Life.hh"
#include "WoodBox.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"
#include "BonusSpawn.hh"

const std::string	WoodBox::NAME = "box_wood";

WoodBox::WoodBox(Listener *parent, const int life, const int x,
		 const int y, const int z)
  : Decor(parent, life, x, y, z)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 330);

  // this->setType(WoodBox::NAME);

  this->addComponent(new Daemon::Render(this, "assets/models/decors/" + WoodBox::NAME + "/" + WoodBox::NAME + ".fbx", 60));
  this->addComponent(ptr);
  this->addComponent(new Daemon::BonusSpawn(this));
}

WoodBox::~WoodBox()
{

}
