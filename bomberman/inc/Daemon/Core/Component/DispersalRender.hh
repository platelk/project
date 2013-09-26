//
// Dispersal.hh for Dispersal in /home/guiho_r/depot/bomberman/src/Daemon/Core/Component
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sat Jun  8 15:38:04 2013 ronan guiho
// Last update Sun Jun  9 11:56:02 2013 ronan guiho
//

#ifndef __DISPERSAL_HH__
#define __DISPERSAL_HH__

#include <list>

#include "Render.hh"
#include "Timer.hh"
#include "Trame.hh"
#include "Vector.hh"
#include "Particle.hh"
#include "Image.hpp"

namespace Daemon
{
  class DispersalRender : public Render
  {
  private:
    float _size;
    int _count;
    Vector _color;
    std::string _path;
    std::list<Particle> _list;
  public:
    DispersalRender(GameObject *owned, const std::string &name,
		    double size, int count, const std::string &path);
    DispersalRender(GameObject *owned, const std::string &name,
		    double size, int count, const Vector &color);
    virtual ~DispersalRender();

    virtual void initialize();
    virtual void update();
    virtual void draw();

    DispersalRender *clone(Daemon::GameObject *owner = 0) const;
    DispersalRender *unserialize(std::stringstream &s, GameObject *owner = 0);
    std::string		 serialize();

    static std::string const NAME;
    static gdl::Image TEXTURE;
  private:
    Particle createParticle();
  };
}

#endif
