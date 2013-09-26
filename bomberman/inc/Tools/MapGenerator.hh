#ifndef __MAPGENERATOR_H__
# define __MAPGENERATOR_H__

#include <deque>

#include "Tools/Noise/Perlin.hh"
#include "Tools/Factory.hh"
#include "Position.hh"
#include "GameObject.hh"

class MapGenerator
{
protected:
  size_t		_width;
  size_t		_height;
  float			_pOccupation;
  size_t		_minDist;
  size_t		_maxDist;
  size_t		_maxIter;
  GameObjectFactory	_fact;
  GameObjectFactory	_fact_indestruct;
  Perlin2D		_perlin;
  Daemon::Position	_pos;

  std::vector<std::string>		_name;
  std::vector<std::string>		_name_indestruct;

protected:
  void			putObject(std::deque<Daemon::GameObject *> &deq, Daemon::GameObject *owner);
  bool			tryPutObject(Daemon::GameObject *owner);
  float			getNewDirVect() const;
  void			genNewDirection();
  void			genNewPosition();
  Daemon::GameObject	*getObject();
  bool			colide(Daemon::GameObject *obj);

public:
  MapGenerator(size_t width, size_t height,
	       float pOccupation,
	       size_t minDist, size_t maxDist,
	       size_t maxIter);
  virtual ~MapGenerator();

  std::deque<Daemon::GameObject *>	genMap(Daemon::GameObject *owner);
  std::deque<Daemon::GameObject *>	genMap(size_t width, size_t height,
					       float pOccupation,
					       size_t minDist, size_t maxDist,
					       size_t maxIter, Daemon::GameObject *owner);

  void		positionObject(Daemon::GameObject *obj);

  size_t	getWidth() const;
  size_t	getHeight() const;
  float		getPOccupation() const;
  size_t	getMinDist() const;
  size_t	getMaxDist() const;
  size_t	getMaxIter() const;

  void		setWidth(size_t width);
  void		setHeight(size_t height);
  void		setPOccupation(float pOccupation);
  void		setMinDist(size_t minDist);
  void		setMaxDist(size_t maxDist);
  void		setMaxIter(size_t maxIter);

private:
  void		genBorder(Daemon::GameObject *owner, std::deque<Daemon::GameObject *> &deq);
};

#endif /* !__MAPGENERATOR_H__ */
