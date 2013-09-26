//
// Render.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Mon May 27 11:54:31 2013 alexis leprovost
// Last update Sun Jun  9 04:14:23 2013 alexis leprovost
//

#ifndef _RENDER_H_
#define _RENDER_H_

#include <string>

#include "Timer.hh"
#include "Model.hpp"
#include "Image.hpp"
#include "AComponent.hh"

namespace Daemon
{
  class Render : public AComponent
  {
  protected:
    std::string	_modelName;
    float	_size;
    bool	_init;
    std::string	_anim;
    float	_speed;
    bool	_update;
    gdl::Model*	_model;
    gdl::Image  _texture;
  public:
    Render(GameObject* owner, std::string const& name = "", float size = 1.0f);
    virtual ~Render();

    std::string const&	getModelName() const;
    void		setModelName(std::string const& name);

    void		setSize(float size);
    float		getSize() const;

    bool		isInit() const;

    virtual std::string	serialize();
    virtual AComponent*	unserialize(std::stringstream &s, GameObject *owner = 0);
    virtual void	initialize();
    virtual void	update();
    virtual void	draw();

    virtual Render*	clone(Daemon::GameObject* owner = 0) const;

    static std::string const	NAME;
  };
}

#endif /* _RENDER_H_ */
