//
// Core.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Tue May 14 09:55:20 2013 alexis leprovost
// Last update Mon Jun 10 21:40:09 2013 alexis leprovost
//

#include <iostream>

#include "Input.hpp"
#include "Trame.hh"
#include "Client/Interface/Stage.hh"
#include "Client/Event/MouseEvent.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/TrameEvent.hh"
#include "Client/Core.hh"

namespace Client
{
  std::string const	Core::NAME = "Bomber All-Stars Online";
  size_t const		Core::WIDTH = 1440;
  size_t const		Core::HEIGHT = 900;

  bool			Core::on = false;
  Profile*		Core::profile = 0;
  ConfXML		Core::confXML;
  gdl::GameClock*	Core::gameClock;
  ClientNetwork*		Core::network = new ClientNetwork;
  std::string		Core::ip;
  short			Core::port;
  ImageManager		Core::imageManager;
  ModelManager		Core::modelManager;
  SoundManager	       	Core::sounds;
  Score::Game		Core::type = Score::Game::ONLINE;
  std::deque<Thread<const char *, int>* > Core::bot;

  Core::Core()
  {

  }

  Core::~Core()
  {

  }

  void	Core::initialize()
  {
    this->window_.setTitle(Core::NAME);
    this->window_.setWidth(Core::WIDTH);
    this->window_.setHeight(Core::HEIGHT);
    this->window_.create();
    this->_interface.initialize();
    this->_action = true;
    this->_input.initialize();
    Core::sounds.addSound("Welcome", "assets/sound/ambiance/sound.mp3", Sound::AMBIANCE);
    Core::sounds.addSound("bomb", "assets/sound/effect/bomb2.wav", Sound::EFFECT);
    Core::sounds.addSound("game", "assets/sound/ambiance/journey.mp3", Sound::AMBIANCE);
    Core::on = true;
    Core::gameClock = &this->gameClock_;
    Core::modelManager.learn("assets/models/characters/darunia/darunia.fbx");
    Core::modelManager.learn("assets/models/characters/falco/falco.fbx");
    Core::modelManager.learn("assets/models/characters/gohan/gohan.fbx");
    Core::modelManager.learn("assets/models/characters/link/link.fbx");
    Core::modelManager.learn("assets/models/characters/lucario/lucario.fbx");
    Core::modelManager.learn("assets/models/characters/mario/mario.fbx");
    Core::modelManager.learn("assets/models/characters/megaman/megaman.fbx");
    Core::modelManager.learn("assets/models/characters/naruto/naruto.fbx");
    Core::modelManager.learn("assets/models/characters/peach/peach.fbx");
    Core::modelManager.learn("assets/models/characters/pit/pit.fbx");
    Core::modelManager.learn("assets/models/characters/sacboy/sacboy.fbx");
    Core::modelManager.learn("assets/models/characters/shrek/shrek.fbx");
    Core::modelManager.learn("assets/models/characters/sonic/sonic.fbx");
    Core::modelManager.learn("assets/models/characters/superman/superman.fbx");
    Core::modelManager.learn("assets/models/decors/bombe/bombe.fbx");
    Core::modelManager.learn("assets/models/decors/palm/palm.fbx");
    Core::modelManager.learn("assets/models/decors/box_wood/box_wood.fbx");
    Core::modelManager.learn("assets/models/decors/blastbox/blastbox.fbx");
    Core::modelManager.learn("assets/models/decors/barrel_wood/barrel_wood.fbx");
    Core::modelManager.learn("assets/models/decors/rock_big/rock_big.fbx");
  }

  void	Core::update()
  {
    if (Core::on == false)
      this->window_.close();
    else
      {
	if (!this->_clock.isRunning())
	  {
	    this->_clock.start();
	    this->_action = false;
	  }
	if (this->_clock.isTimeOut(1.0f / static_cast<float>(Stage::getInstance()->getFrame())))
	  {
	    Event*	event;
	    Event	eventCamera(Event::CAMERA, Event::CAMERA);
	    this->_input.update(&this->input_);
	    this->_controller.setInput(this->_input);
	    while (this->_controller.hasEvent())
	      {
		event = this->_controller.getEvent();
		this->_interface.update(event);
		delete event;
	      }
	    if (Core::network->isConnect())
	      {
		Timer		clock;
		TrameEvent	trameEvent(TrameEvent::TRAME);
		clock.reset();
		clock.start();
		while (!ClientNetwork::execq->isEmpty() && !clock.isTimeOut(0.01f))
		  {
		    trameEvent.setTrame(Daemon::Trame(ClientNetwork::execq->pop()));
		    this->_interface.update(&trameEvent);
		  }
	      }
	    this->_interface.update(&eventCamera);
	    this->_clock.reset();
	    this->_action = true;
	  }
      }
  }

  void	Core::draw()
  {
    if (this->_action)
      {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.90f, 0.90f, 0.90f, 1.0f);
	glClearDepth(1.0f);
	this->_interface.draw();
      }
    usleep(10);
  }

  void	Core::unload()
  {
    this->_interface.unload();
    if (Core::network->isConnect())
      Core::network->disconnect();
    Core::confXML.save();
    while (!Core::bot.empty())
      {
	delete Core::bot.front();
	Core::bot.pop_front();
      }
  }
}
