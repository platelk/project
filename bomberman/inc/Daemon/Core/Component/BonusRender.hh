//
// BonusRender.hh for BonusRender in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Component
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sun Jun  9 01:02:34 2013 ronan guiho
// Last update Sun Jun  9 13:16:18 2013 kevin platel
//

#ifndef __BONUS_RENDER_HH__
#define __BONUS_RENDER_HH__

#include "Render.hh"
#include "Timer.hh"
#include "Trame.hh"
#include "Vector.hh"

namespace Daemon
{
  class BonusRender : public Render
  {
  private:
    float _size;
    std::string _path_texture;
    Vector _pos;
    bool _model;
    Vector _rot;
    Vector _speed;
    float _swipe;
    float _depth;
  public:
    BonusRender(GameObject *owned, const std::string &name = "", const float size = 0,
		const std::string &texture = "", const bool model = false);
    virtual ~BonusRender();

    virtual void initialize();
    virtual void update();
    virtual void draw();
    std::string	serialize();
    BonusRender *clone(Daemon::GameObject *owner = 0) const;
    BonusRender *unserialize(std::stringstream &s, GameObject *owner = 0);

    static std::string const	NAME;
  };
}

#endif
