//
// CharacterBox.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Fri Jun  7 12:21:03 2013 alexis leprovost
// Last update Mon Jun 10 21:56:07 2013 alexis leprovost
//

#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>

#include "Mario.hh"
#include "Pit.hh"
#include "Sonic.hh"
#include "Shrek.hh"
#include "SacBoy.hh"
#include "Gohan.hh"
#include "Darunia.hh"
#include "Peach.hh"
#include "Link.hh"
#include "Falco.hh"
#include "Kratos.hh"
#include "Naruto.hh"
#include "Lucario.hh"
#include "Superman.hh"
#include "Megaman.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/UpdateEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/CharacterBox.hh"
#include "Client/Controller/Input.hh"
#include "Client/Core.hh"
#include "Client/Interface/Interface.hh"

namespace Client
{
  CharacterBox::Character::Character(std::string const& name)
    : name(name),
      model(0, "assets/models/characters/" + name + "/" + name + ".fbx"),
      image({Image("assets/clips/characters/" + name + "_green.png"),
	    Image("assets/clips/characters/" + name + "_blue.png"),
	    Image("assets/clips/characters/" + name + ".png"),
	    Image("assets/clips/characters/" + name + "_red.png")}),
      state(State::NORMAL)
  {

  }

  CharacterBox::Character::~Character()
  {

  }

  void	CharacterBox::Character::initialize()
  {
    this->image[State::NORMAL].initialize();
    this->image[State::SELECT1].initialize();
    this->image[State::SELECT2].initialize();
    this->image[State::LOCK].initialize();
  }

  void	CharacterBox::Character::draw()
  {
    if (this->state == State::DISABLE)
      {
	this->image[State::NORMAL].setColor(0.7f, 0.7f, 0.7f);
	this->image[State::NORMAL].draw();
	this->image[State::NORMAL].setColor(1.0f, 1.0f, 1.0f);
      }
    else
      this->image[this->state].draw();
  }

  CharacterBox::CharacterBox()
    : Button("", "")
  {
    this->setName(Interface::CHARACTER_BOX);
    this->_manual.push_back(CharacterBox::Character("random"));
    this->_manual.push_back(CharacterBox::Character("mario"));
    this->_manual.push_back(CharacterBox::Character("sonic"));
    this->_manual.push_back(CharacterBox::Character("darunia"));
    this->_manual.push_back(CharacterBox::Character("sacboy"));
    this->_manual.push_back(CharacterBox::Character("gohan"));
    this->_manual.push_back(CharacterBox::Character("shrek"));
    this->_manual.push_back(CharacterBox::Character("pit"));
    this->_manual.push_back(CharacterBox::Character("peach"));
    this->_manual.push_back(CharacterBox::Character("link"));
    this->_manual.push_back(CharacterBox::Character("superman"));
    this->_manual.push_back(CharacterBox::Character("megaman"));
    this->_manual.push_back(CharacterBox::Character("naruto"));
    this->_manual.push_back(CharacterBox::Character("lucario"));
    this->_manual.push_back(CharacterBox::Character("kratos"));
    this->_manual.push_back(CharacterBox::Character("falco"));
    this->_index[0] = -1;
    this->_index[1] = -1;
    this->_lock[0] = false;
    this->_lock[1] = false;
    this->_angle = 0;
  }

  CharacterBox::~CharacterBox()
  {

  }

  void	CharacterBox::initialize()
  {
    size_t width = this->getWidth() / 4;
    size_t height = this->getHeight() / 4;
    int y = this->getY();
    int z = this->getZ();
    int	x;
    int	k;
    size_t i, l;

    for (i = 0, l = this->_manual.size(); i < l; ++i)
      this->_manual[i].initialize();
    this->_index[0] = 0;
    this->_index[1] = -1;
    this->_lock[0] = false;
    this->_lock[1] = false;
    this->_angle = 0;
    this->_clock.reset();
    this->_clock.start();
    for (i = 0, l = this->_manual.size(); i < l; ++i)
      {
	if (!(i % 4))
	  {
	    x = this->getX();
	    y -= height;
	  }
	for (k = 0; k < State::COUNT; ++k)
	  {
	    this->_manual[i].image[k].setPosition(x, y, z);
	    this->_manual[i].image[k].setWidth(width);
	    this->_manual[i].image[k].setHeight(height);
	  }
	if (Core::profile->isAvailable(this->_manual[i].name))
	  this->_manual[i].state = State::NORMAL;
	else
	  this->_manual[i].state = State::DISABLE;
	x += width;
      }
    this->_manual[0].state = State::SELECT1;
  }

  void	CharacterBox::_up(int id)
  {
    if (this->_manual[this->_index[id]].state != State::DISABLE &&
	this->_manual[this->_index[id]].state != State::LOCK)
      this->_manual[this->_index[id]].state = State::NORMAL;
    this->_index[id] -= 4;
    if (this->_index[id] < 0)
      this->_index[id] = this->_manual.size() + this->_index[id];
    if (this->_manual[this->_index[id]].state == State::DISABLE ||
	this->_manual[this->_index[id]].state == State::LOCK)
      this->_up(id);
    this->_manual[this->_index[id]].state = static_cast<State::State>(id);
    this->_clock.reset();
    this->_clock.start();
  }

  void	CharacterBox::_down(int id)
  {
    if (this->_manual[this->_index[id]].state != State::DISABLE &&
	this->_manual[this->_index[id]].state != State::LOCK)
      this->_manual[this->_index[id]].state = State::NORMAL;
    this->_index[id] += 4;
    if (this->_index[id] >= static_cast<int>(this->_manual.size()))
      this->_index[id] = this->_index[id] - this->_manual.size();
    if (this->_manual[this->_index[id]].state == State::DISABLE ||
	this->_manual[this->_index[id]].state == State::LOCK)
      this->_down(id);
    this->_manual[this->_index[id]].state = static_cast<State::State>(id);
    this->_clock.reset();
    this->_clock.start();
  }

  void	CharacterBox::_left(int id)
  {
    if (this->_manual[this->_index[id]].state != State::DISABLE &&
	this->_manual[this->_index[id]].state != State::LOCK)
      this->_manual[this->_index[id]].state = State::NORMAL;
    if (!(this->_index[id] % 4))
      this->_index[id] += 3;
    else
      --this->_index[id];
    if (this->_manual[this->_index[id]].state == State::DISABLE ||
	this->_manual[this->_index[id]].state == State::LOCK)
      this->_left(id);
    this->_manual[this->_index[id]].state = static_cast<State::State>(id);
    this->_clock.reset();
    this->_clock.start();
  }

  void	CharacterBox::_right(int id)
  {
    if (this->_manual[this->_index[id]].state != State::DISABLE &&
	this->_manual[this->_index[id]].state != State::LOCK)
      this->_manual[this->_index[id]].state = State::NORMAL;
    if (!((this->_index[id] + 1) % 4) && this->_index[id])
      this->_index[id] -= 3;
    else
      ++this->_index[id];
    if (this->_manual[this->_index[id]].state == State::DISABLE ||
	this->_manual[this->_index[id]].state == State::LOCK)
      this->_right(id);
    this->_manual[this->_index[id]].state = static_cast<State::State>(id);
    this->_clock.reset();
    this->_clock.start();
  }

  void	CharacterBox::_choose(int id)
  {
    this->_lock[id] = true;
    this->_manual[this->_index[id]].state = State::LOCK;
    this->_clock.reset();
    this->_clock.start();
  }

  void	CharacterBox::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);
    JoystickEvent*	joystickEvent = dynamic_cast<JoystickEvent*>(event);

    this->_angle = (this->_angle) % 360;
    if (keyboardEvent && this->_isSelect && this->_clock.isTimeOut(0.15f))
      {
	if (keyboardEvent->getKeyCode() == Input::Keys::Enter)
	  {
	    if (this->_index[0] != -1 && !this->_lock[0])
	      {
		this->_choose(0);
		if (this->_index[1] != -1)
		  this->_manual[this->_index[1]].state = State::SELECT2;
	      }
	    else if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_choose(1);
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Up)
	  {
	    if (!this->_lock[0])
	      this->_up(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_up(1);
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Down)
	  {
	    if (!this->_lock[0])
	      this->_down(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_down(1);
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Left)
	  {
	    if (!this->_lock[0])
	      this->_left(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_left(1);
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Right)
	  {
	    if (!this->_lock[0])
	      this->_right(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_right(1);
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Add)
	  {
	    if (this->_index[1] == -1)
	      {
		this->_index[1] = 0;
		this->_clock.reset();
		this->_clock.start();
	      }
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Subtract)
	  {
	    if (this->_index[1] != -1 && !this->_lock[0])
	      {
		this->_index[1] = -1;
		this->_clock.reset();
		this->_clock.start();
	      }
	  }
      }
    if (joystickEvent && this->_isSelect && this->_clock.isTimeOut(0.15f))
      {
	if (joystickEvent->getButton() == Input::JoystickButton::A)
	  {
	    if (this->_index[0] != -1 && !this->_lock[0])
	      {
		this->_choose(0);
		if (this->_index[1] != -1)
		  this->_manual[this->_index[1]].state = State::SELECT2;
	      }
	    else if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_choose(1);
	  }
	Point position = joystickEvent->getAxisPosition();
	if (position.y < 0)
	  {
	    if (!this->_lock[0])
	      this->_up(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_up(1);
	  }
	if (position.y > 0)
	  {
	    if (!this->_lock[0])
	      this->_down(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_down(1);
	  }
	if (position.x < 0)
	  {
	    if (!this->_lock[0])
	      this->_left(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_left(1);
	  }
	if (position.x > 0)
	  {
	    if (!this->_lock[0])
	      this->_right(0);
	    if (this->_index[1] != -1 && !this->_lock[1] && this->_lock[0])
	      this->_right(1);
	  }
      }
  }

  void	CharacterBox::draw()
  {
    for (size_t i = 0, l = this->_manual.size(); i < l; ++i)
      this->_manual[i].draw();
  }

  void	CharacterBox::unload()
  {

  }

  size_t	CharacterBox::getLink(ButtonManager::Sens sens) const
  {
    if (this->_lock[0] && ((!this->_lock[1] && this->_index[1] == -1) || this->_lock[1]))
      return (this->_link[sens]);
    return (-1);
  }

  std::string const	CharacterBox::getPlayerName(int id)
  {
    if (this->_lock[id] && !this->_index[id])
      return (CharacterBox::getRandName());
    std::pair<std::string, std::string>	reference[15] =
      {
	std::pair<std::string, std::string>("darunia", Darunia::NAME),
	std::pair<std::string, std::string>("falco", Falco::NAME),
	std::pair<std::string, std::string>("gohan", Gohan::NAME),
	std::pair<std::string, std::string>("kratos", Kratos::NAME),
	std::pair<std::string, std::string>("link", Link::NAME),
	std::pair<std::string, std::string>("lucario", Lucario::NAME),
	std::pair<std::string, std::string>("mario", Mario::NAME),
	std::pair<std::string, std::string>("megaman", Megaman::NAME),
	std::pair<std::string, std::string>("naruto", Naruto::NAME),
	std::pair<std::string, std::string>("peach", Peach::NAME),
	std::pair<std::string, std::string>("pit", Pit::NAME),
	std::pair<std::string, std::string>("sacboy", SacBoy::NAME),
	std::pair<std::string, std::string>("shrek", Shrek::NAME),
	std::pair<std::string, std::string>("sonic", Sonic::NAME),
	std::pair<std::string, std::string>("superman", Superman::NAME)
      };

    if (this->_lock[id])
      for (size_t i = 0; i < 15; ++i)
	{
	  if (reference[i].first == this->_manual[this->_index[id]].name)
	    return (reference[i].second);
	}
    return (Falco::NAME);
  }

  std::string const	CharacterBox::getRandName()
  {
    std::pair<std::string, std::string>	reference[15] =
    {
      std::pair<std::string, std::string>("darunia", Darunia::NAME),
      std::pair<std::string, std::string>("falco", Falco::NAME),
      std::pair<std::string, std::string>("gohan", Gohan::NAME),
      std::pair<std::string, std::string>("kratos", Kratos::NAME),
      std::pair<std::string, std::string>("link", Link::NAME),
      std::pair<std::string, std::string>("lucario", Lucario::NAME),
      std::pair<std::string, std::string>("mario", Mario::NAME),
      std::pair<std::string, std::string>("megaman", Megaman::NAME),
      std::pair<std::string, std::string>("naruto", Naruto::NAME),
      std::pair<std::string, std::string>("peach", Peach::NAME),
      std::pair<std::string, std::string>("pit", Pit::NAME),
      std::pair<std::string, std::string>("sacboy", SacBoy::NAME),
      std::pair<std::string, std::string>("shrek", Shrek::NAME),
      std::pair<std::string, std::string>("sonic", Sonic::NAME),
      std::pair<std::string, std::string>("superman", Superman::NAME)
    };
    std::vector<std::string>			random;

    for (size_t i = 0; i < 15; ++i)
      if (Core::profile->isAvailable(reference[i].first))
	random.push_back(reference[i].second);
    if (random.empty())
      return (Falco::NAME);
    return (random[(rand() % random.size())]);
  }
}
