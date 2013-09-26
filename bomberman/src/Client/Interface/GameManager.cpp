//
// GameManager.cpp for exam in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Sat Jun  1 11:15:48 2013 alexis leprovost
//

#include <deque>
#include <cmath>
#include <iostream>

#include "Ground.hh"
#include "Trame.hh"
#include "GameObject.hh"
#include "Render.hh"
#include "PlayerRender.hh"
#include "Characteristic.hh"
#include "Position.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/GameManager.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/LogicTree.hh"
#include "Client/Interface/Widget.hh"
#include "Client/Interface/Stage.hh"
#include "Client/Network/ClientNetwork.hh"
#include "Client/Controller/Input.hh"
#include "Client/Core.hh"

namespace Client
{
  GameManager::GameManager(size_t frame)
    : IWidgetObject(Interface::GAME_MANAGER),
      _frame(frame)
  {

  }

  GameManager::~GameManager()
  {

  }

  void	GameManager::setFrame(size_t frame)
  {
    this->_frame = frame;
  }

  size_t	GameManager::getFrame() const
  {
    return (this->_frame);
  }

  Vector	GameManager::_getMove(Profile::Player id)
  {
    float x = 0.0f;
    float y = 0.0f;
    size_t l = this->_move[id].size();

    while (!this->_move[id].empty())
      {
	x += cos((this->_move[id].front() * 3.14f) / 180.0f);
	y += sin((this->_move[id].front() * 3.14f) / 180.0f);
	this->_move[id].pop();
      }
    if (!l)
      return (Vector(0.0f, 0.0f, 0.0f));
    return (Vector((x / l), -(y / l), 0.0f));
  }

  void	GameManager::_setMove(Profile::Player id)
  {
    Widget*	widget = Stage::getInstance()->getChild(Interface::GAME);

    if (widget)
      {
	LogicTree*	logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	Vector		dir = this->_getMove(id);
	Daemon::Trame	trame(logicTree->getIdPlayer(), "move", "player", "",
			      int_to_str(logicTree->getIdPlayer()),
			      double_to_str(dir.x) +			\
			      "|" + double_to_str(dir.y) + "|" +	\
			      double_to_str(dir.z));
	ClientNetwork::sendq->push(trame.toString());
      }
  }

  void	GameManager::_setThrow(Profile::Player id)
  {
    Widget*	widget = Stage::getInstance()->getChild(Interface::GAME);

    if (widget)
      {
	LogicTree*	logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	Daemon::GameObject*	player = logicTree->getPlayer();
	Daemon::Characteristic*	characteristic = dynamic_cast<Daemon::Characteristic*>(player->getComponent(Daemon::Characteristic::NAME));
	Daemon::Position*	position = dynamic_cast<Daemon::Position*>(player->getComponent(Daemon::Position::NAME));
	float strength = this->_strength[id];
	if (characteristic->getStrength() < strength)
	  strength = characteristic->getStrength();
	Daemon::Trame	trame(logicTree->getIdPlayer(), "throw_bomb", "player", "",
			      int_to_str(logicTree->getIdPlayer()),
			      double_to_str(position->getDx()) + "|" +	\
			      double_to_str(position->getDy()) + "|" +	\
			      double_to_str(position->getDz()) + "|" +
			      double_to_str(strength));
	ClientNetwork::sendq->push(trame.toString());
      }
  }

  void	GameManager::_setSpell(Profile::Player)
  {
    Widget*	widget = Stage::getInstance()->getChild(Interface::GAME);

    if (widget)
      {
	LogicTree*		logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	Daemon::Trame	trame(logicTree->getIdPlayer(), "spell", "player", "",
			      int_to_str(logicTree->getIdPlayer()),
			      "");
	ClientNetwork::sendq->push(trame.toString());
      }
  }

  int  	GameManager::_getAngle(const Point &position)
  {
    if (!Core::profile)
      return (0);
    if (position.y < 0 && position.x < 0)
      return (135);
    if (position.y > 0 && position.x < 0)
      return (225);
    if (position.y < 0 && position.x > 0)
      return (45);
    if (position.y > 0 && position.x > 0)
      return (315);
    if (position.y < 0)
      return (90);
    if (position.y > 0)
      return (270);
    if (position.x < 0)
      return (180);
    if (position.x > 0)
      return (0);
    return (0);

  }

  bool	GameManager::_isKeyMove(const Point &position) const
  {
    if (!Core::profile)
      return (false);
    return (position.x > 0 || position.x < 0 || position.y > 0 || position.y < 0);
  }

  int	GameManager::_getAngle(int keycode, Profile::Player id)
  {
    if (!Core::profile)
      return (0);
    if (Core::profile->getKey(Profile::UP, id) == keycode)
      return (90);
    if (Core::profile->getKey(Profile::LEFT, id) == keycode)
      return (180);
    if (Core::profile->getKey(Profile::DOWN, id) == keycode)
      return (270);
    if (Core::profile->getKey(Profile::RIGHT, id) == keycode)
      return (0);
    return (0);
  }

  bool	GameManager::_isKeyMove(int keycode, Profile::Player id) const
  {
    if (!Core::profile)
      return (false);
    return (Core::profile->getKey(Profile::UP, id) == keycode ||
    	    Core::profile->getKey(Profile::DOWN, id) == keycode ||
    	    Core::profile->getKey(Profile::LEFT, id) == keycode ||
    	    Core::profile->getKey(Profile::RIGHT, id) == keycode);
  }

  bool	GameManager::_isKeyThrow(int keycode, Profile::Player id) const
  {
    if (!Core::profile)
      return (false);
    return (Core::profile->getKey(Profile::THROW, id) == keycode);
  }

  bool	GameManager::_isKeySpell(int keycode, Profile::Player id) const
  {
    if (!Core::profile)
      return (false);
    return (Core::profile->getKey(Profile::SPELL, id) == keycode);
  }

  void	GameManager::initialize()
  {
    this->_clock[Profile::ONE].reset();
    this->_clock[Profile::TWO].reset();
    this->_clock[Profile::ONE].start();
    this->_clock[Profile::TWO].start();
    this->_clock2[Profile::ONE].reset();
    this->_clock2[Profile::TWO].reset();
    this->_strength[Profile::ONE] = 1.0;
    this->_strength[Profile::TWO] = 1.0;
  }

  void	GameManager::draw()
  {
    Widget*		widget = Stage::getInstance()->getChild(Interface::GAME);
    Daemon::Render*	render;

    if (widget)
      {
	LogicTree*				logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	std::deque<Daemon::GameObject*>&	gameObject = logicTree->getGameObject();
	for (size_t i = 0, l = gameObject.size(); i < l; ++i)
	  {
	    if (LogicTree::isInFieldOfVision(logicTree->getPlayer(), gameObject[i], 4000) || gameObject[i]->getType() ==  Ground::NAME)
	      {
		render = dynamic_cast<Daemon::Render*>(gameObject[i]->getComponentFamily(Daemon::Render::NAME));
		if (render)
		  render->draw();
	      }
	  }
      }
  }

  void	GameManager::_action(Profile::Player id)
  {
    if (this->_strength[id] > 1.0f &&
	this->_clock2[id].isRunning() &&
	this->_clock2[id].isTimeOut(0.5f))
      {
	this->_setThrow(id);
	this->_clock2[id].reset();
	this->_strength[id] = 1.0f;
      }
    if (!this->_move[id].empty() && this->_clock[id].isTimeOut(1.0f / this->_frame))
      {
    	this->_setMove(id);
    	this->_clock[id].reset();
    	this->_clock[id].start();
      }
  }

  void	GameManager::update(KeyboardEvent* keyboardEvent, Profile::Player id)
  {
    if (keyboardEvent)
      {
	if (this->_isKeyMove(keyboardEvent->getKeyCode(), id))
	  this->_move[id].push(this->_getAngle(keyboardEvent->getKeyCode(), id));
	if (this->_isKeyThrow(keyboardEvent->getKeyCode(), id))
	  {
	    this->_strength[id] += 0.14;
	    this->_clock2[id].reset();
	    this->_clock2[id].start();
	  }
      }
    this->_action(id);
  }

  void	GameManager::update(JoystickEvent* joystickEvent, Profile::Player id)
  {
    if (joystickEvent)
      {
	Point position = joystickEvent->getAxisPosition();
	if (this->_isKeyMove(position) && joystickEvent->getId() == id)
	  this->_move[id].push(this->_getAngle(position));
	if (joystickEvent->getButton() == Input::JoystickButton::A && joystickEvent->getId() == id)
	  {
	    this->_strength[id] += 0.14;
	    this->_clock2[id].reset();
	    this->_clock2[id].start();
	  }
      }
    this->_action(id);
  }

  void	GameManager::update(Event* event)
  {
    this->update(dynamic_cast<KeyboardEvent*>(event), Profile::ONE);
    this->update(dynamic_cast<JoystickEvent*>(event), Profile::ONE);
    //    this->update(event, Profile::TWO);
  }

  void	GameManager::unload()
  {

  }
}
