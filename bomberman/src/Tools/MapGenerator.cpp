//
// MapGenerator.cpp for /home/vink/projet/cpp/bomberman/src/Tools/MapGenerator.cpp in /home/vink/projet/cpp/bomberman/src/Tools
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sun Jun  2 09:53:17 2013 kevin platel
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "Client/Core.hh"
#include "utils.hh"
#include "Factory.hh"
#include "Life.hh"
#include "Player.hh"
#include "Decor.hh"
#include "Bomb.hh"
#include "Explose.hh"
#include "Position.hh"
#include "Move.hh"
#include "ThrowBomb.hh"
#include "Colider.hh"
#include "Core.hh"
#include "NewPlayer.hh"
#include "Network.hh"
#include "Render.hh"
#include "Game.hh"
#include "GameObject.hh"
#include "Colider.hh"
#include "Tools/MapGenerator.hh"

#include "Palm.hh"
#include "WoodBox.hh"
#include "BlastBox.hh"
#include "BarrelWood.hh"
#include "SandGround.hh"
#include "WallRockTall.hh"
#include "BonusBox.hh"

#include "DispersalEffect.hh"

MapGenerator::MapGenerator(size_t width, size_t height,
			   float pOccupation,
			   size_t minDist, size_t maxDist,
			   size_t maxIter)
  : _width(width), _height(height),
    _pOccupation(pOccupation),
    _minDist(minDist), _maxDist(maxDist),
    _maxIter(maxIter), _perlin(100.0), _pos(0)
{
  Daemon::GameObject	*obj_box = new WoodBox(0);
  Daemon::GameObject	*obj_palm = new Palm(0);
  Daemon::GameObject	*obj_blast = new BlastBox(0);
  Daemon::GameObject	*obj_barrel_wood = new BarrelWood(0);
  Daemon::GameObject	*obj_wall_rock_tall = new WallRockTall(0);

  if (Daemon::EventTree::core)
    Daemon::EventTree::core->removeEntity(obj_box);
  if (Daemon::EventTree::core)
    Daemon::EventTree::core->removeEntity(obj_palm);
  if (Daemon::EventTree::core)
    Daemon::EventTree::core->removeEntity(obj_blast);
  if (Daemon::EventTree::core)
    Daemon::EventTree::core->removeEntity(obj_barrel_wood);
  if (Daemon::EventTree::core)
    Daemon::EventTree::core->removeEntity(obj_wall_rock_tall);

  this->_fact.learn(WoodBox::NAME, obj_box);
  this->_fact_indestruct.learn(Palm::NAME, obj_palm);
  this->_fact.learn(BlastBox::NAME, obj_blast);
  this->_fact.learn(BarrelWood::NAME, obj_barrel_wood);
  this->_fact_indestruct.learn(WallRockTall::NAME, obj_wall_rock_tall);

  this->_name.push_back(WoodBox::NAME);
  this->_name.push_back(BlastBox::NAME);
  this->_name.push_back(BarrelWood::NAME);

  this->_name_indestruct.push_back(Palm::NAME);
  this->_name_indestruct.push_back(WallRockTall::NAME);
}

MapGenerator::~MapGenerator()
{
}

std::deque<Daemon::GameObject *>	MapGenerator::genMap(size_t width, size_t height,
					       float pOccupation,
							     size_t minDist, size_t maxDist,
							     size_t maxIter, Daemon::GameObject *owner)

{
  this->setWidth(width);
  this->setHeight(height);
  this->setPOccupation(pOccupation);
  this->setMinDist(minDist);
  this->setMaxDist(maxDist);
  this->setMaxIter(maxIter);

  return this->genMap(owner);
}

float	MapGenerator::getNewDirVect() const
{
  return static_cast<float>(((rand() % 2000)) - 1000.0) / 1000.0;
}

void	MapGenerator::genNewDirection()
{
  this->_pos.setDx(this->getNewDirVect());
  this->_pos.setDy(this->getNewDirVect());
  this->_pos.setDz(0);
}

void	MapGenerator::genNewPosition()
{
  this->genNewDirection();
  this->_pos.setX(this->_pos.getX() + (this->_minDist + (rand() % (this->_maxDist - this->_minDist))) * this->_pos.getDx());
  this->_pos.setY(this->_pos.getY() + (this->_minDist + (rand() % (this->_maxDist - this->_minDist))) * this->_pos.getDy());
  this->_pos.setZ(0);
}

void MapGenerator::genBorder(Daemon::GameObject *owner, std::deque<Daemon::GameObject *> &deq)
{
  float x = 0;
  while (x < this->_width)
    {
      Daemon::GameObject *obj =	\
	this->_fact_indestruct.create(this->_name_indestruct[rand() % this->_name_indestruct.size()], owner);
      Daemon::Position *p = dynamic_cast<Daemon::Position*>(obj->getComponent("position"));
      if (p)
	{
	  int rang = rand() % 500 + 100;
	  float y = rand() % rang;
	  char sign = rand() % 2;
	  p->setPos(x, (sign == 1) ? -y : y, 0, 0, 0, 0);
	}
      Daemon::Colider *col = dynamic_cast<Daemon::Colider *>(obj->getComponent(Daemon::Colider::NAME));
      x += col->getSize(0);
      deq.push_back(obj);
    }
  float y = 0;
  while (y < this->_height)
    {
      Daemon::GameObject *obj =	\
	this->_fact_indestruct.create(this->_name_indestruct[rand() % this->_name_indestruct.size()], owner);
      Daemon::Position *p = dynamic_cast<Daemon::Position*>(obj->getComponent("position"));
      if (p)
	{
	  int rang = rand() % 500 + 100;
	  float x = rand() % rang;
	  char sign = rand() % 2;
	  p->setPos(((sign == 1) ? -x : x), y, 0, 0, 0, 0);
	}
      deq.push_back(obj);
      obj = this->_fact_indestruct.create(this->_name_indestruct[rand() % this->_name_indestruct.size()], owner);
      p = dynamic_cast<Daemon::Position*>(obj->getComponent("position"));
      if (p)
	{
	  int rang = rand() % 500 + 100;
	  float x = rand() % rang;
	  char sign = rand() % 2;
	  p->setPos(this->_width + ((sign == 1) ? -x : x), y, 0, 0, 0, 0);
	}
      deq.push_back(obj);
      Daemon::Colider *col = dynamic_cast<Daemon::Colider *>(obj->getComponent(Daemon::Colider::NAME));
      y += col->getSize(0);
    }
  x = 0;
  while (x < this->_width)
    {
      Daemon::GameObject *obj =	\
	this->_fact_indestruct.create(this->_name_indestruct[rand() % this->_name_indestruct.size()], owner);
      Daemon::Position *p = dynamic_cast<Daemon::Position*>(obj->getComponent("position"));
      if (p)
	{
	  int rang = rand() % 500 + 100;
	  float y = rand() % rang;
	  char sign = rand() % 2;
	  p->setPos(x, this->_height + ((sign == 1) ? -y : y), 0, 0, 0, 0);
	}
      Daemon::Colider *col = dynamic_cast<Daemon::Colider *>(obj->getComponent(Daemon::Colider::NAME));
      x += col->getSize(0);
      deq.push_back(obj);
    }
}

std::deque<Daemon::GameObject *>	MapGenerator::genMap(Daemon::GameObject *owner)
{
  std::deque<Daemon::GameObject *>	deq;
  size_t				iter = this->_maxIter;

  this->_pos.setX(this->_width / 2);
  this->_pos.setY(this->_height / 2);
  this->_pos.setZ(0);

  this->putObject(deq, new SandGround(0, "", -2000, -2000, 0, this->_width + 4000, this->_height + 4000));
  this->genBorder(owner, deq);
  while (iter)
    {
      this->genNewPosition();
      if (this->_pos.getX() < 0 || this->_pos.getX() > static_cast<long>(this->_width) ||
	  this->_pos.getY() < 0 || this->_pos.getY() > static_cast<long>(this->_height))
	{
	  this->_pos.setX(this->_width / 2);
	  this->_pos.setY(this->_height / 2);
	  this->_pos.setZ(0);
	}
      this->putObject(deq, owner);
      iter--;
    }
  return deq;
}

void			MapGenerator::positionObject(Daemon::GameObject *obj)
{
  std::deque<Daemon::GameObject *>	deq;
  size_t				iter = this->_maxIter;

  this->_pos.setX(this->_width / 2);
  this->_pos.setY(this->_height / 2);
  this->_pos.setZ(0);

  while (iter)
    {
      this->genNewPosition();
      if (this->_pos.getX() < 0 || this->_pos.getX() > static_cast<long>(this->_width) ||
	  this->_pos.getY() < 0 || this->_pos.getY() > static_cast<long>(this->_height))
	{
	  this->_pos.setX(this->_width / 2);
	  this->_pos.setY(this->_height / 2);
	  this->_pos.setZ(0);
	}
      if (this->tryPutObject(obj))
	return ;
      iter--;
    }
}

bool			MapGenerator::colide(Daemon::GameObject *obj)
{
  Daemon::Position *ptr = dynamic_cast<Daemon::Position *>(obj->getComponent("position"));
  Daemon::Colider *col = dynamic_cast<Daemon::Colider *>(obj->getComponent("colider"));

  if (ptr)
    {
      for (size_t i = 0; col && i < Daemon::EventTree::core->_entity.size(); ++i)
	{
	  if (Daemon::EventTree::core->_entity[i]->haveComponent("colider"))
	    {
	      Daemon::Colider *c = dynamic_cast<Daemon::Colider *>(Daemon::EventTree::core->_entity[i]->getComponent("colider"));
	      if (col->colide(*c) && col != c)
		return false;
	    }
	}
      return true;
    }
  return false;
}

void			MapGenerator::putObject(std::deque<Daemon::GameObject *> &deq, Daemon::GameObject *owner)
{
  Daemon::GameObject	*obj;
  float	val = (this->_perlin.getValue(this->_pos.getX(), this->_pos.getY())+1)*0.5;
  Daemon::Position	*p = 0;

  if (val < this->_pOccupation)
    {
      if ((rand() % 100) > 65)
	obj = this->_fact_indestruct.create(this->_name_indestruct[rand() % this->_name_indestruct.size()], owner);
      else
	obj = this->_fact.create(this->_name[rand() % this->_name.size()], owner);
      p = dynamic_cast<Daemon::Position*>(obj->getComponent("position"));
      if (p)
	{
	  p->setPos(this->_pos.getX(), this->_pos.getY(), this->_pos.getZ(), this->_pos.getDx(), this->_pos.getDy(), this->_pos.getDz());
	}
      if (this->colide(obj))
	deq.push_back(obj);
      else
	{
	  if (Daemon::EventTree::core)
	    Daemon::EventTree::core->removeEntity(obj);
	}
    }
}

bool			MapGenerator::tryPutObject(Daemon::GameObject *owner)
{
  Daemon::GameObject	*obj = owner;
  Daemon::Position	*p = 0;

  p = dynamic_cast<Daemon::Position*>(owner->getComponent("position"));
  if (p)
    {
      p->setPos(this->_pos.getX(), this->_pos.getY(), this->_pos.getZ(), this->_pos.getDx(), this->_pos.getDy(), this->_pos.getDz());
    }
  if (this->colide(obj))
    return true;
  else
    {
      return false;
    }
  return false;
}

Daemon::GameObject*	MapGenerator::getObject()
{
  return 0;
}

size_t	MapGenerator::getWidth() const
{
  return this->_width;
}

size_t	MapGenerator::getHeight() const
{
  return this->_height;
}

float	MapGenerator::getPOccupation() const
{
  return this->_pOccupation;
}

size_t	MapGenerator::getMinDist() const
{
  return this->_minDist;
}

size_t	MapGenerator::getMaxDist() const
{
  return this->_maxDist;
}

size_t	MapGenerator::getMaxIter() const
{
  return this->_maxDist;
}

void	MapGenerator::setWidth(size_t width)
{
  this->_width = width;
}

void	MapGenerator::setHeight(size_t height)
{
  this->_height = height;
}

void	MapGenerator::setPOccupation(float pOccupation)
{
  this->_pOccupation = pOccupation;
}

void	MapGenerator::setMinDist(size_t minDist)
{
  this->_minDist = minDist;
}

void	MapGenerator::setMaxDist(size_t maxDist)
{
  this->_maxDist = maxDist;
}


void	MapGenerator::setMaxIter(size_t maxIter)
{
  this->_maxIter = maxIter;
}
