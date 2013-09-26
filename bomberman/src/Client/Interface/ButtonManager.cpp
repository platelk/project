 //
// ButtonManager.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Fri May 17 15:55:21 2013 alexis leprovost
// Last update Sat Jun  8 20:56:27 2013 phalip_z
//

#include <functional>
#include <iostream>

#include "Client/Event/KeyboardEvent.hh"
#include "Client/Controller/Input.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/ButtonManager.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/Button.hh"

namespace Client
{
  ButtonManager::ButtonManager()
    : IWidgetObject(Interface::BUTTON_MANAGER), _index(-1)
  {

  }

  ButtonManager::~ButtonManager()
  {

  }

  void	ButtonManager::addButton(Button* button)
  {
    this->_buttons.push_back(button);
  }

  void	ButtonManager::delButton(Button* button)
  {
    this->_buttons.remove(button);
  }

  void	ButtonManager::shift(ButtonManager::Sens sens)
  {
    if (this->_buttons.empty())
      this->_index = -1;
    else
      {
	if (this->_clock.isTimeOut(0.10f))
	  {
	    std::list<Button*>::iterator	it = this->_buttons.begin();
	    std::advance(it, this->_index);
	    if ((*it)->getLink(sens) < this->_buttons.size())
	      {
		(*it)->select(false);
		this->_index = (*it)->getLink(sens);
		it = this->_buttons.begin();
		std::advance(it, this->_index);
		(*it)->select(true);
	      }
	    this->_clock.reset();
	    this->_clock.start();
	  }
      }
  }

  void	ButtonManager::initialize()
  {
    if (!this->_buttons.empty())
      {
	this->_clock.reset();
	this->_clock.start();
	std::list<Button*>::iterator	it = this->_buttons.begin();
	(*it)->select(true);
	while (++it != this->_buttons.end())
	  (*it)->select(false);
	this->_index = 0;
      }
  }

  void	ButtonManager::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);
    JoystickEvent*	joystickEvent = dynamic_cast<JoystickEvent*>(event);

    if (keyboardEvent)
      {
	if (keyboardEvent->getKeyCode() == Input::Keys::Up)
	  this->shift(ButtonManager::Top);
	if (keyboardEvent->getKeyCode() == Input::Keys::Right)
	  this->shift(ButtonManager::Right);
	if (keyboardEvent->getKeyCode() == Input::Keys::Down)
	  this->shift(ButtonManager::Bottom);
	if (keyboardEvent->getKeyCode() == Input::Keys::Left)
	  this->shift(ButtonManager::Left);
      }
    if (joystickEvent && this)
      {
	Point position = joystickEvent->getAxisPosition();
	if (position.y < 0)
	  this->shift(ButtonManager::Top);
	if (position.y > 0)
	  this->shift(ButtonManager::Bottom);
	if (position.x > 0)
	  this->shift(ButtonManager::Right);
	if (position.x < 0)
	  this->shift(ButtonManager::Left);
      }
    if (this->_index < this->_buttons.size())
      {
	std::list<Button*>::iterator	it = this->_buttons.begin();
	std::advance(it, this->_index);
	(*it)->select(true);
      }
  }

  void	ButtonManager::draw()
  {

  }

  void	ButtonManager::unload()
  {

  }
}
