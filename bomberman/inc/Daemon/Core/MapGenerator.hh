#ifndef __MAPGENERATOR_H__
# define __MAPGENERATOR_H__

#include "Perlin.hh"

class MapGenerator
{
private:
  Perlin2D	_perlin;
public:
  MapGenerator();
  virtual ~MapGenerator();

  std::deque<Daemon::GameObject *>	*createMap(size_t height, size_t width, int nb_object, float res);
};

#endif /* !__MAPGENERATOR_H__ */
