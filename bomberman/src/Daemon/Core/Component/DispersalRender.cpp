//
// DispersalRender.cpp for DispersalRender in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Component
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sat Jun  8 15:49:17 2013 ronan guiho
// Last update Sun Jun  9 12:38:55 2013 ronan guiho
//

#include <list>
#include <stdlib.h>
#include <iostream>

#include "Image.hpp"
#include "Position.hh"
#include "Particle.hh"
#include "DispersalRender.hh"

namespace Daemon
{
  std::string const	DispersalRender::NAME = "dispersalRender";
  gdl::Image	DispersalRender::TEXTURE = gdl::Image::load("assets/clips/world/fire.jpg");

  DispersalRender::DispersalRender(GameObject *owner, const std::string &name, double size,
				   int count, const std::string &path)
    : Render(owner, name, size), _size(size), _count(count), _path(path)
  {
    this->setName(DispersalRender::NAME);
  }

  DispersalRender::DispersalRender(GameObject *owner, const std::string &name, double size,
				   int count, const Vector &color)
    : Render(owner, name, size), _size(size), _count(count), _color(255, color.y, color.z), _path("")
  {
    this->setName(DispersalRender::NAME);
  }

  DispersalRender::~DispersalRender()
  {

  }

  void DispersalRender::initialize()
  {
    /*if (this->_path != "")
      this->_texture = gdl::Image::load(this->_path);*/
    for (int i = 0; i < this->_count; ++i)
      {
	this->_list.push_back(this->createParticle());
	this->_list.back().initialize();
      }
    this->_init = true;
  }

  void DispersalRender::update()
  {
    std::list<Particle>::iterator tmp;

    for (std::list<Particle>::iterator it = this->_list.begin();
	 it != this->_list.end(); ++it)
      {
	tmp = it;
	(*it).update();
	if (!(*it).isAlive())
	  {
	    ++it;
	    this->_list.erase(tmp);
	  }
      }
  }

  void DispersalRender::draw()
  {
    for (std::list<Particle>::iterator it = this->_list.begin(); it != this->_list.end(); ++it)
      {
	(*it).draw();
      }
  }

  std::string DispersalRender::serialize()
  {
    return this->createPackage(this->createData(this->_size) + this->createData(this->_count));
  }

  DispersalRender *DispersalRender::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;
    ss << this->unPack(s);

    return new DispersalRender(owner, "", str_to_double(this->getData(ss)), str_to_int(this->getData(ss)), this->getData(ss));
  }

  DispersalRender *DispersalRender::clone(Daemon::GameObject *owner) const
  {
    return new DispersalRender(owner, this->getName(), this->_size, this->_count, this->_path);
  }

  Particle DispersalRender::createParticle()
  {
    Vector pos(0, 0, 0);
    Vector gra(0, -0.8f, 0);
    Vector spe(0.05f, 0.05f, 0.05f);
    Vector rot(0, 0, 0);
    Vector rcolor(255, 255, 255);
    Vector dir((float)((rand() % 50) - 26.0f) * 10.0f,
	       (float)((rand() % 50) - 25.0f) * 10.0f,
	       (float)((rand() % 50) - 25.0f) * 10.0f);
    float fade = (float)(rand() % 100) / 1000.0f + 0.003f;

    if (this->_owner)
      {
	Daemon::Position *p = dynamic_cast<Daemon::Position*>(this->_owner->getComponent("position"));

	if (p)
	  {
	    Vector p_obj(p->getX(), p->getY(), p->getZ());

	    if (this->_path != "")
	      {
		Particle part(p_obj, dir, rot, gra, spe, 1.0f,
			      fade, this->_size, ANY, this->_texture);
		return (part);
	      }
	    else
	      {
		Particle part(p_obj, dir, rot, gra, spe, 1.0f,
			      fade, this->_size, ANY, this->_color);
		return (part);
	      }
	  }
      }
    Particle part(pos, dir, rot, gra, spe, 1.0f,
		  fade, this->_size, ANY, this->_color);
    return (part);
  }
}
