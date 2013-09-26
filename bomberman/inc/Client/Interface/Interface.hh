//
// Interface.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Tue May 14 10:49:41 2013 alexis leprovost
// Last update Mon Jun 10 22:24:29 2013 alexis leprovost
//

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>

#include "GameClock.hpp"
#include "Client/Event/Event.hh"
#include "Client/Interface/Stage.hh"
#include "Client/Interface/Widget.hh"

namespace Client
{
  class Interface
  {
  private:
    Stage*	_stage;
    bool	_soundPlay;

    void	_welcome();
    void	_newProfile();
    void	_loadProfile();
    void	_score();
    void	_credits();
    void	_menu();
    void	_settings();
    void	_play();
    void	_editor();
    void	_quickGame();
    void	_joinGame();
    void	_customGame();
    void	_createGame();
    void	_selection();
    void	_loadGame();
    void	_game();
    void	_end();
  public:
    Interface();
    ~Interface();

    void	initialize();
    void	update(Event* event);
    void	draw();
    void	unload();

    // Widget Object
    static std::string const	NUM_BOX;
    static std::string const	GAME_MANAGER;
    static std::string const	LOGIC_TREE;
    static std::string const	PROFILE_BOX;
    static std::string const	KEY_BOX;
    static std::string const	TEXT_BOX;
    static std::string const	UI;
    static std::string const	TEXT;
    static std::string const	IMAGE;
    static std::string const	BUTTON;
    static std::string const	BUTTON_MANAGER;
    static std::string const	CAMERA;
    static std::string const	SCORE_BOX;
    static std::string const	CHARACTER_BOX;
    static std::string const	SCREENER;

    // Widget
    static std::string const	WELCOME;
    static std::string const	NEW_PROFILE;
    static std::string const	LOAD_PROFILE;
    static std::string const	SCORE;
    static std::string const	CREDITS;
    static std::string const	MENU;
    static std::string const	SETTINGS;
    static std::string const	PLAY;
    static std::string const	EDITOR;
    static std::string const	QUICK_GAME;
    static std::string const	JOIN_GAME;
    static std::string const	CUSTOM_GAME;
    static std::string const	CREATE_GAME;
    static std::string const	SELECTION;
    static std::string const	LOAD_GAME;
    static std::string const	GAME;
    static std::string const	END;
  };
}

#endif /* _INTERFACE_H_ */
