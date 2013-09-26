#ifndef __LEVEL_HH__
#define __LEVEL_HH__

#include <string>

class Level
{
public:
  Level(const std::string &, long int, const std::string &);
  ~Level();

  std::string	getName() const;
  long int	getXp() const;
  std::string	getSprite() const;

private:
  std::string	_name;
  long int	_xp;
  std::string	_sprite;
};

#endif
