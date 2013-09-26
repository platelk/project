//
// ProfileBox.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed Jun  5 11:29:29 2013 alexis leprovost
// Last update Sun Jun  9 08:19:15 2013 alexis leprovost
//

#include <iostream>

#include "utils.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/ProfileBox.hh"
#include "Client/Core.hh"

#define PK		" players killed"
#define GP		" games played"
#define DAMAGES		" damages inflicted"
#define XP		" experiences earned"

namespace Client
{
  ProfileBox::ProfileBox(std::string const& normal, std::string const& select,
		      std::string const& left, std::string const& right,
		      bool isSelect)
    : Button(normal, select, isSelect),
      _index(0),
      _left(left),
      _right(right),
      _level(""),
      _shift(ProfileBox::NONE)
  {

  }

  ProfileBox::~ProfileBox()
  {

  }

  void	ProfileBox::_shiftProfile()
  {
    if (this->_index < Core::confXML.getProfiles().size())
      {
	Profile* profile = Core::confXML.getProfiles()[this->_index];
	this->_level.setFilename(profile->getImageLevel());
	this->_level.initialize();
	this->_name.setText(profile->getName());
	this->_playersKilled.setText(int_to_str(profile->getPlayersKilled()) + PK);
	this->_gamesPlayed.setText(int_to_str(profile->getGamesPlayed()) + GP);
	this->_damages.setText(int_to_str(profile->getDamages()) + DAMAGES);
	this->_xp.setText(int_to_str(profile->getXp()) + XP);
      }
  }

  void	ProfileBox::initialize()
  {
    this->_index = 0;
    this->_shiftProfile();
    this->_normal.initialize();
    this->_select.initialize();
    this->_left.initialize();
    this->_right.initialize();
    this->_name.initialize();
    this->_name.setColor(0.38f, 0.284f, 0.128f);
    this->_playersKilled.initialize();
    this->_playersKilled.setColor(1.0f, 1.0f, 1.0f);
    this->_gamesPlayed.initialize();
    this->_gamesPlayed.setColor(1.0f, 1.0f, 1.0f);
    this->_damages.initialize();
    this->_damages.setColor(1.0f, 1.0f, 1.0f);
    this->_xp.initialize();
    this->_xp.setColor(1.0f, 1.0f, 1.0f);
    this->_shiftClock.reset();
  }

  void	ProfileBox::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);
    JoystickEvent*	joystickEvent = dynamic_cast<JoystickEvent*>(event);

    this->_normal.update(event);
    this->_select.update(event);
    this->_left.update(event);
    this->_right.update(event);
    if ((!this->_shiftClock.isRunning() || this->_shiftClock.isTimeOut(0.15f)) &&
	keyboardEvent && this->_isSelect)
      {
	if (keyboardEvent->getKeyCode() == Input::Keys::Left)
	  {
	    --this->_index;
	    if (static_cast<int>(this->_index) < 0)
	      this->_index = Core::confXML.getProfiles().size() - 1;
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = ProfileBox::LEFT;
	    this->_shiftProfile();
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Right)
	  {
	    ++this->_index;
	    if (!Core::confXML.getProfiles().empty())
	      this->_index %= Core::confXML.getProfiles().size();
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = ProfileBox::RIGHT;
	    this->_shiftProfile();
	  }
      }
    if ((!this->_shiftClock.isRunning() || this->_shiftClock.isTimeOut(0.15f)) &&
        joystickEvent && this->_isSelect)
      {
	Point	position = joystickEvent->getAxisPosition();
	if (position.x < 0)
	  {
	    --this->_index;
	    if (static_cast<int>(this->_index) < 0)
	      this->_index = Core::confXML.getProfiles().size() - 1;
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = ProfileBox::LEFT;
	    this->_shiftProfile();
	  }
	if (position.x > 0)
	  {
	    ++this->_index;
	    if (!Core::confXML.getProfiles().empty())
	      this->_index %= Core::confXML.getProfiles().size();
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = ProfileBox::RIGHT;
	    this->_shiftProfile();
	  }
      }
 }

  void  ProfileBox::draw()
  {
    if (this->_isSelect)
      {
	if (!this->_shiftClock.isRunning() ||
	    this->_shiftClock.isTimeOut(0.15f) ||
	    !this->_shift)
	  this->_select.draw();
	else
	  {
	    if (this->_shift == ProfileBox::LEFT)
	      this->_left.draw();
	    else
	      this->_right.draw();
	  }
      }
    else
      this->_normal.draw();
    this->_level.draw();
    this->_name.draw();
    this->_playersKilled.draw();
    this->_gamesPlayed.draw();
    this->_damages.draw();
    this->_xp.draw();
  }

  void	ProfileBox::unload()
  {
    this->_normal.unload();
    this->_select.unload();
    this->_left.unload();
    this->_right.unload();
    this->_level.unload();
    this->_name.unload();
    this->_playersKilled.unload();
    this->_gamesPlayed.unload();
    this->_damages.unload();
    this->_xp.unload();
  }

  void	ProfileBox::setX(int x)
  {
    Button::setX(x);
    this->_left.setX(x);
    this->_right.setX(x);
    this->_name.setX(x + (this->getWidth() / 5));
    this->_playersKilled.setX(x + (this->getWidth() / 5));
    this->_gamesPlayed.setX(x + (this->getWidth() / 5));
    this->_damages.setX(x + (this->getWidth() / 5));
    this->_xp.setX(x + (this->getWidth() / 5));
    this->_level.setX(x + (this->getWidth() * 0.72));
  }

  void	ProfileBox::setY(int y)
  {
    Button::setY(y);
    this->_left.setY(y);
    this->_right.setY(y);
    this->_name.setY(y + (this->getHeight() * 0.8));
    this->_playersKilled.setY(y + (this->getHeight() * 0.72));
    this->_gamesPlayed.setY(y + (this->getHeight() * 0.68));
    this->_damages.setY(y + (this->getHeight() * 0.64));
    this->_xp.setY(y + (this->getHeight() * 0.60));
    this->_level.setY(y + (this->getHeight() * 0.8));
  }

  void	ProfileBox::setZ(int z)
  {
    Button::setZ(z);
    this->_left.setZ(z);
    this->_right.setZ(z);
    this->_name.setZ(z);
    this->_playersKilled.setZ(z);
    this->_gamesPlayed.setZ(z);
    this->_damages.setZ(z);
    this->_xp.setZ(z);
    this->_level.setZ(z);
  }

  void	ProfileBox::setPosition(int x, int y, int z)
  {
    Button::setPosition(x, y, z);
    this->_left.setPosition(x, y, z);
    this->_right.setPosition(x, y, z);

  }

  void	ProfileBox::setWidth(size_t width)
  {
    Button::setWidth(width);
    this->_left.setWidth(width);
    this->_right.setWidth(width);
    this->_name.setSize(width / 25);
    this->_playersKilled.setSize(width / 40);
    this->_gamesPlayed.setSize(width / 40);
    this->_damages.setSize(width / 40);
    this->_xp.setSize(width / 40);
    this->_level.setWidth(width / 20);
  }

  void	ProfileBox::setHeight(size_t height)
  {
    Button::setHeight(height);
    this->_left.setHeight(height);
    this->_right.setHeight(height);
    this->_level.setHeight(height / 25);
  }

  Profile*	ProfileBox::getProfile() const
  {
    if (this->_index < Core::confXML.getProfiles().size())
      return (Core::confXML.getProfiles()[this->_index]);
    return (0);
  }
}
