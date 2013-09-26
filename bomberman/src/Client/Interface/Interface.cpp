//
// Interface.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Tue May 14 10:49:23 2013 alexis leprovost

#include <iostream>


#include "Client/Interface/GameManager.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/ButtonManager.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/TextBox.hh"
#include "Client/Interface/ProfileBox.hh"
#include "Client/Interface/SoundBox.hh"
#include "Client/Interface/Ui.hh"
#include "Client/Interface/KeyBox.hh"
#include "Client/Interface/ScoreBox.hh"
#include "Client/Interface/Camera.hh"
#include "Client/Interface/CharacterBox.hh"
#include "Client/Interface/NumBox.hh"
#include "Client/Interface/Text.hh"
#include "Client/Interface/Screener.hh"
#include "Client/Interface/LogicTree.hh"
#include "Client/Interface/Screener.hh"
#include "Client/Event/Event.hh"
#include "Client/Event/CameraEvent.hh"
#include "Client/Event/UpdateEvent.hh"
#include "Client/Trigger/Trigger.hh"
#include "Client/Core.hh"

namespace Client
{
  std::string const	Interface::SCORE_BOX = "ScoreBox";
  std::string const	Interface::NUM_BOX = "numBox";
  std::string const	Interface::GAME_MANAGER = "gameManager";
  std::string const	Interface::LOGIC_TREE = "logicTree";
  std::string const	Interface::PROFILE_BOX = "profileBox";
  std::string const	Interface::KEY_BOX = "keyBox";
  std::string const	Interface::TEXT_BOX = "textBox";
  std::string const	Interface::UI = "UI";
  std::string const	Interface::TEXT = "text";
  std::string const	Interface::IMAGE = "image";
  std::string const	Interface::BUTTON = "Button";
  std::string const	Interface::BUTTON_MANAGER = "ButtonManager";
  std::string const	Interface::CAMERA = "Camera";
  std::string const	Interface::CHARACTER_BOX = "CharacterBox";
  std::string const	Interface::SCREENER = "Screener";

  std::string const	Interface::WELCOME = "Welcome";
  std::string const	Interface::NEW_PROFILE = "NewProfile";
  std::string const	Interface::LOAD_PROFILE = "LoadProfile";
  std::string const	Interface::SCORE = "Score";
  std::string const	Interface::CREDITS = "Credit";
  std::string const	Interface::MENU = "Menu";
  std::string const	Interface::SETTINGS = "Settings";
  std::string const	Interface::PLAY = "Play";
  std::string const	Interface::EDITOR = "Editor";
  std::string const	Interface::QUICK_GAME = "quickGame";
  std::string const	Interface::JOIN_GAME = "JoinGame";
  std::string const	Interface::CUSTOM_GAME = "customGame";
  std::string const	Interface::CREATE_GAME = "createGame";
  std::string const	Interface::SELECTION = "Selection";
  std::string const	Interface::LOAD_GAME = "loadGame";
  std::string const	Interface::GAME = "game";
  std::string const	Interface::END = "end";

  Interface::Interface()
    : _stage(Stage::getInstance()), _soundPlay(false)
  {

  }

  Interface::~Interface()
  {

  }

  void	Interface::initialize()
  {
    Event	eventState(Event::STATE, Interface::WELCOME);
    Camera*	camera = new Camera;

    this->_welcome();
    this->_newProfile();
    this->_loadProfile();
    this->_score();
    this->_credits();
    this->_menu();
    this->_settings();
    this->_play();
    this->_editor();
    this->_quickGame();
    this->_joinGame();
    this->_customGame();
    this->_createGame();
    this->_selection();
    this->_loadGame();
    this->_game();
    this->_end();
    this->_stage->addEventListener(Event::INITIALIZE, Trigger::initialize);
    this->_stage->addEventListener(Event::STATE, Trigger::state);
    this->_stage->addEventListener(Event::UPDATE, Trigger::update);
    this->_stage->addEventListener(Event::DRAW, Trigger::draw);
    this->_stage->dispatchEvent(&eventState);
    this->_stage->setFrame(60);
    this->_stage->addWidgetObject(camera);
    camera->initialize();
    camera->setEye(0.0f, 0.0f, 500.0f);
    camera->setCenter(0.0f, 0.0f, 0.0f);
    camera->setFov(100);
  }

  void	Interface::update(Event* event)
  {
    UpdateEvent		updateEvent(UpdateEvent::OBJECT, event);
    Widget*		state = this->_stage->getState();
    Sound		*tmp = Core::sounds.getSound("Welcome");
    Sound		*tmp2 = Core::sounds.getSound("game");

    if (state)
      {
	if (_soundPlay == false)
	  {
	    tmp->play();
	    _soundPlay = true;
	  }
	else
	  {
	    if (tmp->isPlaying() == false)
	      tmp->repeat();
	    if (tmp2->isPlaying() == false && state->getName() == Interface::GAME)
	      tmp2->repeat();
	  }
	state->dispatchEvent(&updateEvent, true);
      }
    this->_stage->dispatchEvent(&updateEvent);
  }

  void	Interface::draw()
  {
    Widget*	state = this->_stage->getState();

    this->_stage->dispatchEvent(Event::DRAW);
    if (state)
      state->dispatchEvent(Event::DRAW, true);
  }

  void	Interface::unload()
  {
    this->_stage->removeAllChild();
    this->_stage->removeAllWidgetObject();
  }

  void	Interface::_welcome()
  {
    Widget*		main = new Widget(Interface::WELCOME, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_home.png");
    Button*		new_profile = new Button("assets/clips/menu/new.png",
    						"assets/clips/menu/new_hover.png");
    Button*		load_profile = new Button("assets/clips/menu/load.png",
						 "assets/clips/menu/load_hover.png");
    Button*		score = new Button("assets/clips/menu/score.png",
					   "assets/clips/menu/score_hover.png");
    Button*		credits = new Button("assets/clips/menu/credits.png",
					    "assets/clips/menu/credits_hover.png");
    Button*		quit = new Button("assets/clips/menu/quit.png",
					  "assets/clips/menu/quit_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::INITIALIZE, Trigger::dynamic);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(new_profile);
    main->addWidgetObject(load_profile);
    main->addWidgetObject(score);
    main->addWidgetObject(credits);
    main->addWidgetObject(quit);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    new_profile->addEventListener(Event::STATE, Trigger::target);
    new_profile->setWidth(Core::WIDTH / 4.5);
    new_profile->setHeight(Core::HEIGHT / 12);
    new_profile->setX(-(new_profile->getWidth() / 1.98));
    new_profile->setY(Core::HEIGHT / 4 - (Core::HEIGHT / 15));
    new_profile->setLink(ButtonManager::Top, 4);
    new_profile->setLink(ButtonManager::Bottom, 1);
    new_profile->setTarget(Interface::NEW_PROFILE);

    load_profile->addEventListener(Event::STATE, Trigger::target);
    load_profile->setWidth(Core::WIDTH / 4.5);
    load_profile->setHeight(Core::HEIGHT / 12);
    load_profile->setX(-(load_profile->getWidth() / 1.98));
    load_profile->setY((Core::HEIGHT / 4) - (Core::HEIGHT / 8) - (Core::HEIGHT / 15));
    load_profile->setTarget(Interface::LOAD_PROFILE);
    load_profile->setLink(ButtonManager::Top, 0);
    load_profile->setLink(ButtonManager::Bottom, 2);

    score->addEventListener(Event::STATE, Trigger::target);
    score->setWidth(Core::WIDTH / 4.5);
    score->setHeight(Core::HEIGHT / 12);
    score->setX(-(score->getWidth() / 1.98));
    score->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 2) - (Core::HEIGHT / 15));
    score->setTarget(Interface::SCORE);
    score->setLink(ButtonManager::Top, 1);
    score->setLink(ButtonManager::Bottom, 3);

    credits->addEventListener(Event::STATE, Trigger::target);
    credits->setWidth(Core::WIDTH / 4.5);
    credits->setHeight(Core::HEIGHT / 12);
    credits->setX(-(credits->getWidth() / 1.98));
    credits->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 3) - (Core::HEIGHT / 15));
    credits->setTarget(Interface::CREDITS);
    credits->setLink(ButtonManager::Top, 2);
    credits->setLink(ButtonManager::Bottom, 4);

    quit->addEventListener(Event::STATE, Trigger::quit);
    quit->setWidth(Core::WIDTH / 4.5);
    quit->setHeight(Core::HEIGHT / 12);
    quit->setX(-(quit->getWidth() / 1.98));
    quit->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 4) - (Core::HEIGHT / 15));
    quit->setLink(ButtonManager::Top, 3);
    quit->setLink(ButtonManager::Bottom, 0);

    manager->addButton(new_profile);
    manager->addButton(load_profile);
    manager->addButton(score);
    manager->addButton(credits);
    manager->addButton(quit);
  }

  void	Interface::_newProfile()
  {
    Widget*		main = new Widget(Interface::NEW_PROFILE, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_new_profile.png");
    Button*		ok = new Button("assets/clips/menu/valide_ok.png",
					"assets/clips/menu/valide_ok_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    TextBox*		name = new TextBox("assets/clips/menu/input_name.png",
					   "assets/clips/menu/input_name_hover.png");

    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dynamic);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(name);
    main->addWidgetObject(ok);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    name->setWidth(Core::WIDTH / 1.8);
    name->setHeight(Core::HEIGHT / 4);
    name->setSizeText(22);
    name->setPositionText(-58, 44, 1);
    name->setColorText(0.0f, 0.0f, 0.0f);
    name->setSizeMax(((name->getWidth() / 2) / 25) - 1);
    name->setX(-(name->getWidth() / 2) + 15);
    name->setLink(ButtonManager::Bottom, 1);

    ok->addEventListener(Event::STATE, Trigger::save);
    ok->addEventListener(Event::STATE, Trigger::target);
    ok->setWidth(Core::WIDTH / 10);
    ok->setHeight(Core::HEIGHT / 25);
    ok->setX(-(ok->getWidth() * 1.5));
    ok->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    ok->setTarget(Interface::MENU);
    ok->setLink(ButtonManager::Top, 0);
    ok->setLink(ButtonManager::Right, 2);
    ok->setParent(main);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(back->getWidth() / 2);
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    back->setTarget(Interface::WELCOME);
    back->setLink(ButtonManager::Left, 1);
    back->setLink(ButtonManager::Top, 0);

    manager->addButton(name);
    manager->addButton(ok);
    manager->addButton(back);
  }

  void	Interface::_loadProfile()
  {
    Widget*	        main = new Widget(Interface::LOAD_PROFILE, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_load_profile.png");
    ProfileBox*		liste = new ProfileBox("assets/clips/menu/modal.png",
					       "assets/clips/menu/modal_hover.png",
					       "assets/clips/menu/modal_hover_left.png",
					       "assets/clips/menu/modal_hover_right.png");
    Button*		ok = new Button("assets/clips/menu/valide_ok.png",
					"assets/clips/menu/valide_ok_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(liste);
    main->addWidgetObject(ok);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    liste->setWidth(Core::WIDTH / 2.5);
    liste->setHeight(Core::HEIGHT / 1.1);
    liste->setX(-(liste->getWidth() / 2));
    liste->setY(-(Core::HEIGHT / 2.25));
    liste->setLink(ButtonManager::Bottom, 1);

    ok->addEventListener(Event::STATE, Trigger::save);
    ok->addEventListener(Event::STATE, Trigger::target);
    ok->setWidth(Core::WIDTH / 10);
    ok->setHeight(Core::HEIGHT / 25);
    ok->setX(-(ok->getWidth() * 1.5));
    ok->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    ok->setTarget(Interface::MENU);
    ok->setLink(ButtonManager::Top, 0);
    ok->setLink(ButtonManager::Right, 2);
    ok->setParent(main);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(back->getWidth() / 2);
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    back->setTarget(Interface::WELCOME);
    back->setLink(ButtonManager::Left, 1);
    back->setLink(ButtonManager::Top, 0);

    manager->addButton(liste);
    manager->addButton(ok);
    manager->addButton(back);
  }

  void	Interface::_score()
  {
    Widget*	        main = new Widget(Interface::SCORE, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_score.png");
    ScoreBox*		score = new ScoreBox(Interface::SCORE_BOX,
					     "assets/clips/menu/score_table.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(score);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    score->setWidth(Core::WIDTH / 1.7);
    score->setHeight(Core::HEIGHT / 1.7);
    score->setX(-(Core::WIDTH / 3.2));
    score->setY(-(Core::HEIGHT/ 4));
    score->setZ(1);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(-(back->getWidth() / 2));
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    back->setTarget(Interface::WELCOME);

    manager->addButton(back);
  }

  void	Interface::_credits()
  {
    Widget*	        main = new Widget(Interface::CREDITS, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_credits.png");
    Image*		tmp = new Image("assets/clips/menu/credits_content.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(back);
    main->addWidgetObject(tmp);
    main->addWidgetObject(manager);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    tmp->setWidth(Core::WIDTH / 2.0);
    tmp->setHeight(Core::HEIGHT / 2.0);
    tmp->setX(-(tmp->getWidth() / 2));
    tmp->setY(-(tmp->getHeight() / 2));

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(-(back->getWidth() / 2));
    back->setY(-(Core::HEIGHT / 1.9));
    back->setTarget(Interface::WELCOME);

    manager->addButton(back);
  }

  void	Interface::_menu()
  {
    Widget*		main = new Widget(Interface::MENU, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_menu.png");
    Button*		play = new Button("assets/clips/menu/play.png",
						"assets/clips/menu/play_hover.png");
    Button*		editor = new Button("assets/clips/menu/editor.png",
						 "assets/clips/menu/editor_hover.png");
    Button*		settings = new Button("assets/clips/menu/settings.png",
					   "assets/clips/menu/settings_hover.png");
    Button*		back = new Button("assets/clips/menu/back.png",
					  "assets/clips/menu/back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(play);
    main->addWidgetObject(editor);
    main->addWidgetObject(settings);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    play->addEventListener(Event::STATE, Trigger::target);
    play->setWidth(Core::WIDTH / 4.5);
    play->setHeight(Core::HEIGHT / 12);
    play->setX(-(play->getWidth() / 1.98));
    play->setY((Core::HEIGHT / 4) - (Core::HEIGHT / 15));
    play->setTarget(Interface::PLAY);
    play->setLink(ButtonManager::Top, 3);
    play->setLink(ButtonManager::Bottom, 2);

    editor->addEventListener(Event::STATE, Trigger::target);
    editor->setWidth(Core::WIDTH / 4.5);
    editor->setHeight(Core::HEIGHT / 12);
    editor->setX(-(editor->getWidth() / 1.98));
    editor->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 1) - (Core::HEIGHT / 15));
    editor->setTarget(Interface::EDITOR);
    editor->setLink(ButtonManager::Top, 0);
    editor->setLink(ButtonManager::Bottom, 2);
    editor->hide();

    settings->addEventListener(Event::STATE, Trigger::target);
    settings->setWidth(Core::WIDTH / 4.5);
    settings->setHeight(Core::HEIGHT / 12);
    settings->setX(-(settings->getWidth() / 1.98));
    settings->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 2) - (Core::HEIGHT / 15));
    settings->setTarget(Interface::SETTINGS);
    settings->setLink(ButtonManager::Top, 0);
    settings->setLink(ButtonManager::Bottom, 3);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 4.5);
    back->setHeight(Core::HEIGHT / 12);
    back->setX(-(back->getWidth() / 1.98));
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 3) - (Core::HEIGHT / 15));
    back->setTarget(Interface::WELCOME);
    back->setLink(ButtonManager::Top, 2);
    back->setLink(ButtonManager::Bottom, 0);

    manager->addButton(play);
    manager->addButton(editor);
    manager->addButton(settings);
    manager->addButton(back);
  }

  void	Interface::_settings()
  {
    Widget*		main = new Widget(Interface::SETTINGS, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_settings.png");
    Image*		keys = new Image("assets/clips/menu/border_multi.png");
    Button*		ok = new Button("assets/clips/menu/valide_ok.png",
					"assets/clips/menu/valide_ok_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    KeyBox*		up_l = new KeyBox("assets/clips/menu/key_up.png",
					  "assets/clips/menu/key_up_hover.png");
    KeyBox*		down_l = new KeyBox("assets/clips/menu/key_down.png",
					  "assets/clips/menu/key_down_hover.png");
    KeyBox*		left_l = new KeyBox("assets/clips/menu/key_left.png",
					  "assets/clips/menu/key_left_hover.png");
    KeyBox*		right_l = new KeyBox("assets/clips/menu/key_right.png",
					  "assets/clips/menu/key_right_hover.png");
    KeyBox*		throw_l = new KeyBox("assets/clips/menu/key_throw.png",
					  "assets/clips/menu/key_throw_hover.png");
    KeyBox*		spell_l = new KeyBox("assets/clips/menu/key_spell.png",
					  "assets/clips/menu/key_spell_hover.png");
    KeyBox*		up_r = new KeyBox("assets/clips/menu/key_up.png",
					  "assets/clips/menu/key_up_hover.png");
    KeyBox*		down_r = new KeyBox("assets/clips/menu/key_down.png",
					  "assets/clips/menu/key_down_hover.png");
    KeyBox*		left_r = new KeyBox("assets/clips/menu/key_left.png",
					  "assets/clips/menu/key_left_hover.png");
    KeyBox*		right_r = new KeyBox("assets/clips/menu/key_right.png",
					  "assets/clips/menu/key_right_hover.png");
    KeyBox*		throw_r = new KeyBox("assets/clips/menu/key_throw.png",
					  "assets/clips/menu/key_throw_hover.png");
    KeyBox*		spell_r = new KeyBox("assets/clips/menu/key_spell.png",
					  "assets/clips/menu/key_spell_hover.png");
    SoundBox*		effects = new SoundBox("assets/clips/menu/effects.png",
					       "assets/clips/menu/effects_hover.png");
    SoundBox*		ambiance = new SoundBox("assets/clips/menu/ambiance.png",
					  "assets/clips/menu/ambiance_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::INITIALIZE, Trigger::settings);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->setPosition(0, 0);
    main->setWidth(-1);
    main->setHeight(-1);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(keys);
    main->addWidgetObject(up_l);
    main->addWidgetObject(down_l);
    main->addWidgetObject(left_l);
    main->addWidgetObject(right_l);
    main->addWidgetObject(throw_l);
    main->addWidgetObject(spell_l);
    main->addWidgetObject(up_r);
    main->addWidgetObject(down_r);
    main->addWidgetObject(left_r);
    main->addWidgetObject(right_r);
    main->addWidgetObject(throw_r);
    main->addWidgetObject(spell_r);
    main->addWidgetObject(effects);
    main->addWidgetObject(ambiance);
    main->addWidgetObject(ok);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-2);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(-1);

    keys->setWidth(Core::WIDTH / 1.9);
    keys->setHeight(Core::HEIGHT / 1.2);
    keys->setX(-(background->getWidth() / 2.55));
    keys->setY(-(background->getHeight() / 3.25));
    keys->setZ(0);

    up_l->setWidth(Core::WIDTH / 5);
    up_l->setHeight(Core::HEIGHT / 20);
    up_l->setX(-(Core::WIDTH / 4.45));
    up_l->setY(Core::HEIGHT / 3.75);
    up_l->setSizeText(22);
    up_l->setPositionText(-(Core::WIDTH / 16),
			  Core::HEIGHT / 3.58,
			  1);
    up_l->setSizeMax(1);
    up_l->setLink(ButtonManager::Right, 6);
    up_l->setLink(ButtonManager::Bottom, 1);

    down_l->setWidth(Core::WIDTH / 5);
    down_l->setHeight(Core::HEIGHT / 20);
    down_l->setX(-(Core::WIDTH / 4.45));
    down_l->setY((Core::HEIGHT / 3.75) - (down_l->getHeight() * 1.2));
    down_l->setSizeText(22);
    down_l->setPositionText(-(Core::WIDTH / 16),
			    (Core::HEIGHT / 3.58) - (down_l->getHeight() * 1.2),
			    1);
    down_l->setSizeMax(1);
    down_l->setLink(ButtonManager::Top, 0);
    down_l->setLink(ButtonManager::Right, 7);
    down_l->setLink(ButtonManager::Bottom, 2);

    left_l->setWidth(Core::WIDTH / 5);
    left_l->setHeight(Core::HEIGHT / 20);
    left_l->setX(-(Core::WIDTH / 4.45));
    left_l->setY((Core::HEIGHT / 3.75) - (left_l->getHeight() * 2.5));
    left_l->setSizeText(22);
    left_l->setPositionText(-(Core::WIDTH / 16),
			    (Core::HEIGHT / 3.58) - (left_l->getHeight() * 2.5),
			    1);
    left_l->setSizeMax(1);
    left_l->setLink(ButtonManager::Top, 1);
    left_l->setLink(ButtonManager::Right, 8);
    left_l->setLink(ButtonManager::Bottom, 3);

    right_l->setWidth(Core::WIDTH / 5);
    right_l->setHeight(Core::HEIGHT / 20);
    right_l->setX(-(Core::WIDTH / 4.45));
    right_l->setY((Core::HEIGHT / 3.75) - (right_l->getHeight() * 3.7));
    right_l->setSizeText(22);
    right_l->setPositionText(-(Core::WIDTH / 16),
			    (Core::HEIGHT / 3.58) - (right_l->getHeight() * 3.7),
			    1);
    right_l->setSizeMax(1);
    right_l->setLink(ButtonManager::Top, 2);
    right_l->setLink(ButtonManager::Right, 9);
    right_l->setLink(ButtonManager::Bottom, 4);

    throw_l->setWidth(Core::WIDTH / 5);
    throw_l->setHeight(Core::HEIGHT / 20);
    throw_l->setX(-(Core::WIDTH / 4.45));
    throw_l->setY((Core::HEIGHT / 3.75) - (throw_l->getHeight() * 4.9));
    throw_l->setSizeText(22);
    throw_l->setPositionText(-(Core::WIDTH / 16),
			    (Core::HEIGHT / 3.58) - (throw_l->getHeight() * 4.9),
			    1);
    throw_l->setSizeMax(1);
    throw_l->setLink(ButtonManager::Top, 3);
    throw_l->setLink(ButtonManager::Right, 10);
    throw_l->setLink(ButtonManager::Bottom, 5);

    spell_l->setWidth(Core::WIDTH / 5);
    spell_l->setHeight(Core::HEIGHT / 20);
    spell_l->setX(-(Core::WIDTH / 4.45));
    spell_l->setY((Core::HEIGHT / 3.75) - (spell_l->getHeight() * 6.1));
    spell_l->setSizeText(22);
    spell_l->setPositionText(-(Core::WIDTH / 16),
			     (Core::HEIGHT / 3.58) - (spell_l->getHeight() * 6.1),
			     1);
    spell_l->setSizeMax(1);
    spell_l->setLink(ButtonManager::Top, 4);
    spell_l->setLink(ButtonManager::Right, 11);
    spell_l->setLink(ButtonManager::Bottom, 12);

    up_r->setWidth(Core::WIDTH / 5);
    up_r->setHeight(Core::HEIGHT / 20);
    up_r->setX((Core::WIDTH / 27.5));
    up_r->setY(Core::HEIGHT / 3.75);
    up_r->setSizeText(22);
    up_r->setPositionText(Core::WIDTH / 5.06,
			  Core::HEIGHT / 3.58,
			  1);
    up_r->setSizeMax(1);
    up_r->setLink(ButtonManager::Left, 0);
    up_r->setLink(ButtonManager::Bottom, 7);

    down_r->setWidth(Core::WIDTH / 5);
    down_r->setHeight(Core::HEIGHT / 20);
    down_r->setX(Core::WIDTH / 27.5);
    down_r->setY((Core::HEIGHT / 3.75) - (down_r->getHeight() * 1.2));
    down_r->setSizeText(22);
    down_r->setPositionText(Core::WIDTH / 5.06,
			    (Core::HEIGHT / 3.58) - (down_r->getHeight() * 1.2),
			    1);
    down_r->setSizeMax(1);
    down_r->setLink(ButtonManager::Top, 6);
    down_r->setLink(ButtonManager::Left, 1);
    down_r->setLink(ButtonManager::Bottom, 8);

    left_r->setWidth(Core::WIDTH / 5);
    left_r->setHeight(Core::HEIGHT / 20);
    left_r->setX(Core::WIDTH / 27.5);
    left_r->setY((Core::HEIGHT / 3.75) - (left_r->getHeight() * 2.5));
    left_r->setSizeText(22);
    left_r->setPositionText(Core::WIDTH / 5.06,
			    (Core::HEIGHT / 3.58) - (left_r->getHeight() * 2.5),
			    1);
    left_r->setSizeMax(1);
    left_r->setLink(ButtonManager::Top, 7);
    left_r->setLink(ButtonManager::Left, 2);
    left_r->setLink(ButtonManager::Bottom, 9);

    right_r->setWidth(Core::WIDTH / 5);
    right_r->setHeight(Core::HEIGHT / 20);
    right_r->setX(Core::WIDTH / 27.5);
    right_r->setY((Core::HEIGHT / 3.75) - (right_r->getHeight() * 3.7));
    right_r->setSizeText(22);
    right_r->setPositionText(Core::WIDTH / 5.06,
			    (Core::HEIGHT / 3.58) - (right_r->getHeight() * 3.7),
			    1);
    right_r->setSizeMax(1);
    right_r->setLink(ButtonManager::Top, 7);
    right_r->setLink(ButtonManager::Left, 3);
    right_r->setLink(ButtonManager::Bottom, 10);

    throw_r->setWidth(Core::WIDTH / 5);
    throw_r->setHeight(Core::HEIGHT / 20);
    throw_r->setX(Core::WIDTH / 27.5);
    throw_r->setY((Core::HEIGHT / 3.75) - (throw_r->getHeight() * 4.9));
    throw_r->setSizeText(22);
    throw_r->setPositionText(Core::WIDTH / 5.06,
			    (Core::HEIGHT / 3.58) - (throw_r->getHeight() * 4.9),
			    1);
    throw_r->setSizeMax(1);
    throw_r->setLink(ButtonManager::Top, 9);
    throw_r->setLink(ButtonManager::Left, 4);
    throw_r->setLink(ButtonManager::Bottom, 11);

    spell_r->setWidth(Core::WIDTH / 5);
    spell_r->setHeight(Core::HEIGHT / 20);
    spell_r->setX(Core::WIDTH / 27.5);
    spell_r->setY((Core::HEIGHT / 3.75) - (spell_r->getHeight() * 6.1));
    spell_r->setSizeText(22);
    spell_r->setPositionText(Core::WIDTH / 5.06,
			     (Core::HEIGHT / 3.58) - (spell_r->getHeight() * 6.1),
			     1);
    spell_r->setSizeMax(1);
    spell_r->setLink(ButtonManager::Top, 10);
    spell_r->setLink(ButtonManager::Left, 5);
    spell_r->setLink(ButtonManager::Bottom, 12);

    effects->setWidth(Core::WIDTH / 2.5);
    effects->setHeight(Core::HEIGHT / 20);
    effects->setX(-(effects->getWidth() / 2));
    effects->setY((Core::HEIGHT / 6) - ((Core::HEIGHT / 16.5) * 7));
    effects->setLink(ButtonManager::Top, 5);
    effects->setLink(ButtonManager::Bottom, 13);
    effects->setWidthBar(effects->getWidth() / 1.65);
    effects->setHeightBar(effects->getHeight() / 2.2);
    effects->setColorBar(0.472f, 0.732f, 0.02f);
    effects->setPositionBar(effects->getX() + (effects->getWidth() / 2.655),
			    effects->getY() + (effects->getHeight() / 5.7),
			    0.0f);

    ambiance->setWidth(Core::WIDTH / 2.5);
    ambiance->setHeight(Core::HEIGHT / 20);
    ambiance->setX(-(ambiance->getWidth() / 2));
    ambiance->setY((Core::HEIGHT / 6) - ((Core::HEIGHT / 16) * 8));
    ambiance->setLink(ButtonManager::Top, 12);
    ambiance->setLink(ButtonManager::Bottom, 14);
    ambiance->setWidthBar(ambiance->getWidth() / 1.65);
    ambiance->setHeightBar(ambiance->getHeight() / 2.2);
    ambiance->setColorBar(0.472f, 0.732f, 0.02f);
    ambiance->setPositionBar(ambiance->getX() + (ambiance->getWidth() / 2.655),
			     ambiance->getY() + (ambiance->getHeight() / 5.7),
			     0.0f);

    ok->addEventListener(Event::STATE, Trigger::settings);
    ok->addEventListener(Event::STATE, Trigger::target);
    ok->setWidth(Core::WIDTH / 10);
    ok->setHeight(Core::HEIGHT / 25);
    ok->setX(-(ok->getWidth() * 1.5));
    ok->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    ok->setTarget(Interface::MENU);
    ok->setLink(ButtonManager::Top, 13);
    ok->setLink(ButtonManager::Right, 15);
    ok->setParent(main);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(back->getWidth() / 2);
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    back->setTarget(Interface::MENU);
    back->setLink(ButtonManager::Left, 14);
    back->setLink(ButtonManager::Top, 13);

    manager->addButton(up_l);
    manager->addButton(down_l);
    manager->addButton(left_l);
    manager->addButton(right_l);
    manager->addButton(throw_l);
    manager->addButton(spell_l);
    manager->addButton(up_r);
    manager->addButton(down_r);
    manager->addButton(left_r);
    manager->addButton(right_r);
    manager->addButton(throw_r);
    manager->addButton(spell_r);
    manager->addButton(effects);
    manager->addButton(ambiance);
    manager->addButton(ok);
    manager->addButton(back);
  }

  void	Interface::_play()
  {
    Widget*		main = new Widget(Interface::PLAY, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_play.png");
    Image*		local = new Image("assets/clips/menu/border_local.png");
    Image*		online = new Image("assets/clips/menu/border_online.png");
    Button*		quick_game = new Button("assets/clips/menu/quick_game.png",
					"assets/clips/menu/quick_game_hover.png");
    Button*		custom_game = new Button("assets/clips/menu/custom_game.png",
					"assets/clips/menu/custom_game_hover.png");
    Button*		load_game = new Button("assets/clips/menu/load_game.png",
					"assets/clips/menu/load_game_hover.png");
    Button*		create_game = new Button("assets/clips/menu/create_game.png",
					"assets/clips/menu/create_game_hover.png");
    Button*		join_game = new Button("assets/clips/menu/join_game.png",
					"assets/clips/menu/join_game_hover.png");
    Button*		back = new Button("assets/clips/menu/back.png",
					  "assets/clips/menu/back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(local);
    main->addWidgetObject(online);
    main->addWidgetObject(quick_game);
    main->addWidgetObject(custom_game);
    main->addWidgetObject(load_game);
    main->addWidgetObject(create_game);
    main->addWidgetObject(join_game);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(-1);

    online->setWidth(Core::WIDTH / 2);
    online->setHeight(Core::HEIGHT / 3);
    online->setX(-(background->getWidth() / 2.7));
    online->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 5));
    online->setZ(0);

    local->setWidth(Core::WIDTH / 2);
    local->setHeight(Core::HEIGHT / 2 - (Core::HEIGHT / 25));
    local->setX(-(background->getWidth() / 2.7));
    local->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 2));
    local->setZ(0);

    quick_game->addEventListener(Event::STATE, Trigger::target);
    quick_game->setWidth(Core::WIDTH / 4.5);
    quick_game->setHeight(Core::HEIGHT / 12);
    quick_game->setX(-(quick_game->getWidth() / 2));
    quick_game->setY(Core::HEIGHT / 3 - 25);
    quick_game->setLink(ButtonManager::Top, 5);
    quick_game->setLink(ButtonManager::Bottom, 3);
    quick_game->setTarget(Interface::QUICK_GAME);

    custom_game->addEventListener(Event::STATE, Trigger::target);
    custom_game->setWidth(Core::WIDTH / 4.5);
    custom_game->setHeight(Core::HEIGHT / 12);
    custom_game->setX(-(custom_game->getWidth() / 2));
    custom_game->setY((Core::HEIGHT / 3.8) - custom_game->getHeight());
    custom_game->setLink(ButtonManager::Top, 0);
    custom_game->setLink(ButtonManager::Bottom, 2);
    custom_game->hide();

    load_game->addEventListener(Event::STATE, Trigger::target);
    load_game->setWidth(Core::WIDTH / 4.5);
    load_game->setHeight(Core::HEIGHT / 12);
    load_game->setX(-(load_game->getWidth() / 2));
    load_game->setY((Core::HEIGHT / 4.2) - (load_game->getHeight() * 2.2));
    load_game->setLink(ButtonManager::Top, 1);
    load_game->setLink(ButtonManager::Bottom, 3);
    load_game->hide();

    create_game->addEventListener(Event::STATE, Trigger::target);
    create_game->setWidth(Core::WIDTH / 4.5);
    create_game->setHeight(Core::HEIGHT / 12);
    create_game->setX(-(create_game->getWidth() / 2));
    create_game->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 3.5));
    create_game->setTarget(Interface::CREATE_GAME);
    create_game->setLink(ButtonManager::Top, 0);
    create_game->setLink(ButtonManager::Bottom, 5);

    join_game->addEventListener(Event::STATE, Trigger::target);
    join_game->setWidth(Core::WIDTH / 4.5);
    join_game->setHeight(Core::HEIGHT / 12);
    join_game->setX(-(join_game->getWidth() / 2));
    join_game->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 4.5));
    join_game->setLink(ButtonManager::Top, 3);
    join_game->setLink(ButtonManager::Bottom, 5);
    join_game->hide();

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 4.5);
    back->setHeight(Core::HEIGHT / 12);
    back->setX(-(back->getWidth() / 2));
    back->setY(-(Core::HEIGHT / 2));
    back->setTarget(Interface::MENU);
    back->setLink(ButtonManager::Top, 3);
    back->setLink(ButtonManager::Bottom, 0);

    manager->addButton(quick_game);
    manager->addButton(custom_game);
    manager->addButton(load_game);
    manager->addButton(create_game);
    manager->addButton(join_game);
    manager->addButton(back);
  }

  void	Interface::_editor()
  {
    Widget*		main = new Widget(Interface::EDITOR, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_editor.png");
    Button*		new_map = new Button("assets/clips/menu/new_map.png",
					"assets/clips/menu/new_map_hover.png");
    Button*		edit_map = new Button("assets/clips/menu/edit_map.png",
					"assets/clips/menu/edit_map_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					"assets/clips/menu/valide_back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(new_map);
    main->addWidgetObject(edit_map);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    new_map->addEventListener(Event::STATE, Trigger::target);
    new_map->setWidth(Core::WIDTH / 4);
    new_map->setHeight(Core::HEIGHT / 8);
    new_map->setX((-Core::WIDTH / 8));
    new_map->setY((Core::HEIGHT / 4) - (Core::HEIGHT / 8));
    new_map->setTarget(Interface::EDITOR);
    new_map->setLink(ButtonManager::Top, 2);
    new_map->setLink(ButtonManager::Bottom, 1);

    edit_map->addEventListener(Event::STATE, Trigger::target);
    edit_map->setWidth(Core::WIDTH / 4);
    edit_map->setHeight(Core::HEIGHT / 8);
    edit_map->setX((-Core::WIDTH / 8));
    edit_map->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 2));
    edit_map->setTarget(Interface::EDITOR);
    edit_map->setLink(ButtonManager::Top, 0);
    edit_map->setLink(ButtonManager::Bottom, 2);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 4);
    back->setHeight(Core::HEIGHT / 8);
    back->setX((-Core::WIDTH / 8));
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8) * 3));
    back->setTarget(Interface::MENU);
    back->setLink(ButtonManager::Top, 1);
    back->setLink(ButtonManager::Bottom, 0);

    manager->addButton(new_map);
    manager->addButton(edit_map);
    manager->addButton(back);
  }

  void	Interface::_quickGame()
  {
    Widget*	        main = new Widget(Interface::QUICK_GAME, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Text*		text = new Text("DOWNLOAD", 100);

    main->addEventListener(Event::NETWORK, Trigger::route);
    main->addEventListener(Event::UPDATE, Trigger::random);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(text);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    text->setX(-400.0f);
    text->setColor(1.0f, 1.0f, 1.0f);
  }

  void	Interface::_customGame()
  {
    Widget*	        main = new Widget(Interface::CUSTOM_GAME, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Button*		ok = new Button("assets/clips/menu/valide_ok.png",
					"assets/clips/menu/valide_ok_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    NumBox*		num_easy = new NumBox("assets/clips/menu/key_spell.png",
					  "assets/clips/menu/key_spell_hover.png");
    ButtonManager*	manager = new ButtonManager;


    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(num_easy);
    main->addWidgetObject(ok);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    num_easy->setWidth(Core::WIDTH / 5);
    num_easy->setHeight(Core::HEIGHT / 20);
    num_easy->setX(-(Core::WIDTH / 4.45));
    num_easy->setY((Core::HEIGHT / 3.75) - (num_easy->getHeight() * 3.7));
    num_easy->setSizeText(22);
    num_easy->setPositionText(-(Core::WIDTH / 16),
			    (Core::HEIGHT / 3.58) - (num_easy->getHeight() * 3.7),
			    1);
    num_easy->setSizeMax(1);
    num_easy->setLink(ButtonManager::Bottom, 1);

    ok->addEventListener(Event::STATE, Trigger::target);
    ok->setWidth(Core::WIDTH / 4);
    ok->setHeight(Core::HEIGHT / 8);
    ok->setX(-(Core::WIDTH / 5) - (Core::WIDTH / 8));
    ok->setY(-(Core::HEIGHT / 3));
    ok->setTarget(Interface::MENU);
    ok->setLink(ButtonManager::Top, 0);
    ok->setLink(ButtonManager::Right, 2);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 4);
    back->setHeight(Core::HEIGHT / 8);
    back->setX((Core::WIDTH / 7) - (Core::WIDTH / 8));
    back->setY(-(Core::HEIGHT / 3));
    back->setTarget(Interface::PLAY);
    back->setLink(ButtonManager::Left, 1);

    manager->addButton(num_easy);
    manager->addButton(ok);
    manager->addButton(back);
  }

  void	Interface::_createGame()
  {
    Widget*	        main = new Widget(Interface::CREATE_GAME, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Text*		text = new Text("DOWNLOAD", 100);

    main->addEventListener(Event::NETWORK, Trigger::route);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::connect);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(text);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    text->setX(-400.0f);
    text->setColor(1.0f, 1.0f, 1.0f);
  }

  void	Interface::_joinGame()
  {
    Widget*	        main = new Widget(Interface::JOIN_GAME, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_play.png");
    Button*		ok = new Button("assets/clips/menu/valide_ok.png",
					"assets/clips/menu/valide_ok_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    TextBox*		port = new TextBox("assets/clips/menu/port.png",
					   "assets/clips/menu/port_hover.png");
    TextBox*		ip = new TextBox("assets/clips/menu/host.png",
					 "assets/clips/menu/host_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(port);
    main->addWidgetObject(ip);
    main->addWidgetObject(ok);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    port->addEventListener(Event::STATE, Trigger::target);
    port->setWidth(Core::WIDTH / 3);
    port->setHeight(Core::HEIGHT / 20);
    port->setX(-(Core::WIDTH / 6) - (Core::WIDTH / 8));
    port->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8)  * 2));
    port->setSizeText(22);
    port->setPositionText(port->getX() + 225,
			  port->getY()+ 10,
			    1);
    port->setSizeMax(5);
    port->setLink(ButtonManager::Right, 1);
    port->setLink(ButtonManager::Bottom, 2);

    ip->addEventListener(Event::STATE, Trigger::target);
    ip->setWidth(Core::WIDTH / 3);
    ip->setHeight(Core::HEIGHT / 20);
    ip->setX((Core::WIDTH / 9.3) - (Core::WIDTH / 8));
    ip->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 8)  * 2));
    ip->setSizeText(22);
    ip->setPositionText(ip->getX() + 100,
			  ip->getY(),
			    1);
    ip->setSizeMax(12);
    ip->setLink(ButtonManager::Left, 0);
    ip->setLink(ButtonManager::Bottom, 2);


    ok->addEventListener(Event::STATE, Trigger::save);
    ok->addEventListener(Event::STATE, Trigger::target);
    ok->setWidth(Core::WIDTH / 10);
    ok->setHeight(Core::HEIGHT / 25);
    ok->setX(-(ok->getWidth() * 1.5));
    ok->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    ok->setTarget(Interface::GAME);
    ok->setLink(ButtonManager::Top, 0);
    ok->setLink(ButtonManager::Right, 3);
    ok->setParent(main);

    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(back->getWidth() / 2);
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    back->setTarget(Interface::PLAY);
    back->setLink(ButtonManager::Top, 0);
    back->setLink(ButtonManager::Left, 2);

    manager->addButton(port);
    manager->addButton(ip);
    manager->addButton(ok);
    manager->addButton(back);
  }

  void	Interface::_selection()
  {
    Widget*	        main = new Widget(Interface::SELECTION, this->_stage);
    Image*		background = new Image("assets/clips/menu/background_selection.png");
    Image*		fond = new Image("assets/clips/menu/font.png");
    Button*		ok = new Button("assets/clips/menu/valide_ok.png",
					"assets/clips/menu/valide_ok_hover.png");
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    CharacterBox*	character = new CharacterBox;
    Image*	        modal = new Image("assets/clips/characters/modal_select_perso.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::NETWORK, Trigger::route);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(background);
    main->addWidgetObject(fond);
    main->addWidgetObject(modal);
    main->addWidgetObject(ok);
    main->addWidgetObject(character);
    main->addWidgetObject(back);
    main->addWidgetObject(manager);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    modal->setWidth(Core::WIDTH / 2.5);
    modal->setHeight(Core::HEIGHT / 1.1);
    modal->setX(-(modal->getWidth() / 2));
    modal->setY(-(Core::HEIGHT / 2.25));

    character->setWidth(Core::WIDTH / 3.30);
    character->setHeight(Core::HEIGHT / 1.475);
    character->setX(-(character->getWidth() / 1.95));
    character->setY(Core::HEIGHT / 2.8);
    character->setParent(manager);
    character->setLink(ButtonManager::Bottom, 1);

    ok->addEventListener(Event::STATE, Trigger::select);
    ok->addEventListener(Event::STATE, Trigger::target);
    ok->setWidth(Core::WIDTH / 10);
    ok->setHeight(Core::HEIGHT / 25);
    ok->setX(-(ok->getWidth() * 1.5));
    ok->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    ok->setTarget(Interface::LOAD_GAME);
    ok->setLink(ButtonManager::Right, 2);
    ok->setParent(main);

    back->addEventListener(Event::STATE, Trigger::disconnect);
    back->addEventListener(Event::STATE, Trigger::target);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(back->getWidth() / 2);
    back->setY((Core::HEIGHT / 4) - ((Core::HEIGHT / 6.5) * 5));
    back->setTarget(Interface::PLAY);
    back->setLink(ButtonManager::Left, 1);

    manager->addButton(character);
    manager->addButton(ok);
    manager->addButton(back);
  }

  void	Interface::_loadGame()
  {
    Widget*	        main = new Widget(Interface::LOAD_GAME, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Text*		text = new Text("DOWNLOAD", 100);

    main->addEventListener(Event::NETWORK, Trigger::route);
    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::SYNCHRONISATION, Trigger::synchronisation);
    main->addEventListener(Event::START, Trigger::start);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(text);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    text->setX(-400.0f);
    text->setColor(1.0f, 1.0f, 1.0f);
  }

  void	Interface::_game()
  {
    Widget*	        main = new Widget(Interface::GAME, this->_stage);
    LogicTree*		logic_tree = new LogicTree;
    Screener*		screener = new Screener;
    GameManager*	manager = new GameManager;

    main->addEventListener(Event::INITIALIZE, Trigger::soundGame);
    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::game);
    main->addEventListener(Event::END, Trigger::end);
    main->addWidgetObject(logic_tree);
    main->addWidgetObject(screener);
    main->addWidgetObject(manager);
  }

  void	Interface::_end()
  {
    Widget*	        main = new Widget(Interface::END, this->_stage);
    Image*		fond = new Image("assets/clips/menu/font.png");
    Image*		background = new Image("assets/clips/menu/background_end.png");
    Text*		text = new Text("Game Over", 85);
    Button*		back = new Button("assets/clips/menu/valide_back.png",
					  "assets/clips/menu/valide_back_hover.png");
    ButtonManager*	manager = new ButtonManager;

    main->addEventListener(Event::INITIALIZE, Trigger::initialize);
    main->addEventListener(Event::DRAW, Trigger::draw);
    main->addEventListener(Event::UPDATE, Trigger::dispatch);
    main->addEventListener(Event::UPDATE, Trigger::update);
    main->addEventListener(Event::CAMERA, Trigger::menu);
    main->addWidgetObject(fond);
    main->addWidgetObject(background);
    main->addWidgetObject(back);
    main->addWidgetObject(text);
    main->addWidgetObject(manager);

    background->setWidth((Core::WIDTH / 2) + (Core::WIDTH / 6));
    background->setHeight((Core::HEIGHT / 2) * 2 + (Core::HEIGHT / 4));
    background->setX(-(background->getWidth() / 2));
    background->setY(-(background->getHeight() / 2));
    background->setZ(0);

    fond->setWidth(Core::WIDTH * 1.5);
    fond->setHeight(Core::HEIGHT * 1.5);
    fond->setX(-Core::WIDTH + 400);
    fond->setY(-Core::HEIGHT + 200);
    fond->setZ(-1);

    back->addEventListener(Event::STATE, Trigger::quit);
    back->setWidth(Core::WIDTH / 10);
    back->setHeight(Core::HEIGHT / 25);
    back->setX(-(back->getWidth() / 2));
    back->setY(-(Core::HEIGHT / 1.9));
    back->setTarget(Interface::MENU);

    text->setX(-400.0f);
    text->setColor(1.0f, 1.0f, 1.0f);

    manager->addButton(back);
  }
}
