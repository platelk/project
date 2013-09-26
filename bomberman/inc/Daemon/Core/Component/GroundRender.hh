//
// GroundRender.hh for GroundRender in /home/guiho_r/depot/bomberman/src/Daemon/Core/Component
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 20:43:49 2013 ronan guiho
// Last update Sun Jun  9 06:31:33 2013 ronan guiho
//

#ifndef __GROUND_RENDER_HH__
#define __GROUND_RENDER_HH__

#include "Render.hh"
#include "Timer.hh"
#include "Trame.hh"
#include "Vector.hh"

namespace Daemon
{
  class GroundRender : public Render
  {
  private:
    Vector _pos;
    float _heigth;
    float _width;
  public:
    GroundRender(GameObject *owned, const std::string &name = "", const float width = 0, const float heigth = 0);
    virtual ~GroundRender();

    virtual void initialize();
    virtual void update();
    virtual void draw();
    GroundRender *clone(Daemon::GameObject *owner = 0) const;
    GroundRender *unserialize(std::stringstream &s, GameObject *owner = 0);
    std::string serialize();

    static std::string const	NAME;
  };
}

#endif
