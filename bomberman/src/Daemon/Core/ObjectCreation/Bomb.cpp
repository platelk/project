
#include "ObjectCreation.hh"
#include "Life.hh"
#include "Bomb.hh"
#include "Explose.hh"
#include "Position.hh"
#include "Move.hh"
#include "Colider.hh"
#include "Render.hh"
#include "Update.hh"

const std::string	Bomb::NAME = "bomb";

Bomb::Bomb(Listener *parent)
: GameObject("bomb", parent)
{
  Daemon::Colider *ptr = new Daemon::Colider(this);
  ptr->addCircle(0, 0, 100);

  this->addComponent(ptr);

  this->addComponent(new Daemon::Life(this, 1, 1));
  this->addComponent(new Daemon::Explose(this, 2, 2000, 30));
  this->addComponent(new Daemon::Position(this));
  this->addComponent(new Daemon::Move(this));
  this->addComponent(new Daemon::Update(this));
  this->addComponent(new Daemon::Render(this, "assets/models/decors/bombe/bombe.fbx", 1200));
}

Bomb::~Bomb()
{
}

Bomb	*Bomb::clone(Listener *parent) const
{
	return  new Bomb(parent);
}
