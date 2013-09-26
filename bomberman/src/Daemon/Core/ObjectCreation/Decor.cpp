
#include "ObjectCreation.hh"
#include "Life.hh"
#include "Decor.hh"
#include "Colider.hh"
#include "Life.hh"
#include "Position.hh"
#include "Render.hh"
#include "Update.hh"

const std::string	Decor::NAME = "decor";

Decor::Decor(Listener *parent, int, int x, int y, int z)
: GameObject("decor", parent)
{
  this->addComponent(new Daemon::Update(this));
  this->addComponent(new Daemon::Position(this, x, y, z));
  this->addComponent(new Daemon::Life(this, 1, 1));
}

Decor::~Decor()
{

}
