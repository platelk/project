#include	"Level.hh"

Level::Level(const std::string & name, long int xp, const std::string & sprite)
  : _name(name), _xp(xp), _sprite(sprite)
{}

Level::~Level()
{}

std::string	Level::getName() const
{
  return this->_name;
}

long int	Level::getXp() const
{
  return this->_xp;
}

std::string	Level::getSprite() const
{
  return this->_sprite;
}
