//
// PlayerRender.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Wed May 29 11:40:10 2013 alexis leprovost
// Last update Tue Jun 11 08:22:18 2013 alexis leprovost
//

#ifndef _PLAYERRENDER_H_
#define _PLAYERRENDER_H_

#include <map>
#include <utility>

#include "Client/Interface/Image.hh"
#include "Model.hpp"
#include "Render.hh"
#include "Timer.hh"
#include "Trame.hh"

namespace Daemon
{
  class PlayerRender : public Render
  {
  public:
    typedef std::map<std::string, std::pair<bool, float> >	Manual;
  private:
    Client::Image	_image1;
    Client::Image	_image2;
    gdl::Model	_model;
    Timer	_clock;
    Manual	_manual;
    Timer	_clock2;
    float	_getSpeed();
  public:
    PlayerRender(GameObject* owner, std::string const& name, float size = 1.0f);
    virtual ~PlayerRender();

    virtual void	initialize();
    virtual void	update();
    virtual void	draw();

    PlayerRender*	clone(Daemon::GameObject *owner = 0) const;
    PlayerRender*	unserialize(std::stringstream &s, GameObject *owner = 0);
    void		play(std::string const& anim);
    void		stop(std::string const& anim);

    void	        eventThrowBomb(Trame& event);
    void		eventMove(Trame& event);

    static std::string const	T_POSE;
    static std::string const	TEST;
    static std::string const	IDLE;
    static std::string const	RUN;
    static std::string const	THROW;
    static std::string const	PSY;
    static std::string const	NAME;
  };
}

#endif /* _PLAYERRENDER_H_ */
