//
// Core.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Tue May 14 09:55:09 2013 alexis leprovost
// Last update Mon Jun 10 22:30:32 2013 kevin platel
//

#ifndef _CORE_H_
#define _CORE_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <sys/types.h>

#include "Fork.hpp"
#include "Score.hh"
#include "GameClock.hpp"
#include "Game.hpp"
#include "Timer.hh"
#include "Profile.hh"
#include "ConfXML.hh"
#include "SourceManager.hpp"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/TextManager.hh"
#include "Client/Controller/Input.hh"
#include "Client/Controller/Controller.hh"
#include "Client/Network/ClientNetwork.hh"
#include "Client/Sound/SoundManager.hh"

namespace Client
{
  class Core : public gdl::Game
  {
  private:
    Interface		_interface;
    Timer		_clock;
    Input		_input;
    Controller		_controller;
    bool		_action;
    short		_port;
    std::string		_ip;
    size_t		_fps;
  public:
    Core();
    virtual ~Core();

    virtual void	initialize();
    virtual void	update();
    virtual void	draw();
    virtual void	unload();

    static std::string const	NAME;
    static size_t const		WIDTH;
    static size_t const		HEIGHT;

    static bool			on;
    static gdl::GameClock*	gameClock;
    static ClientNetwork	*network;
    static std::string		ip;
    static short		port;
    static Profile*		profile;
    static ConfXML		confXML;
    static ImageManager		imageManager;
    static ModelManager		modelManager;
    static SoundManager		sounds;
    static Score::Game		type;
    static std::deque<Thread<const char *, int>* >	bot;
  };
}

#endif /* _CORE_H_ */
