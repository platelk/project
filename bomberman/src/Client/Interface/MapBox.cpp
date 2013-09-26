//
// MapBox.cpp for MapBox in /home/guiho_r/depot/bomberman/src/Client/Interface
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jun  9 19:02:33 2013 ronan guiho
// Last update Sun Jun  9 20:00:36 2013 ronan guiho
//

#include <iostream>

#include "utils.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/MapBox.hh"
#include "Client/Core.hh"

namespace Client
{
  MapBox::MapBox(std::string const& normal, std::string const& select,
		      std::string const& left, std::string const& right,
		      bool isSelect)
    : Button(normal, select, isSelect),
      _index(0),
      _left(left),
      _right(right),
      _shift(MapBox::NONE)
  {

  }

  MapBox::~MapBox()
  {

  }

  void	MapBox::_shiftMap()
  {
    /*if (this->_index < Core::confXML.getMaps().size())
      {
	Map* map = Core::confXML.getMaps()[this->_index];
	}*/
  }

  void	MapBox::initialize()
  {
    this->_index = 0;
    this->_shiftMap();
    this->_normal.initialize();
    this->_select.initialize();
    this->_left.initialize();
    this->_right.initialize();
    this->_shiftClock.reset();


    std::vector<Map *> _lmap = Core::confXML.getMaps();
    for (unsigned int i = 0; i < _lmap.size(); ++i)
      {
	this->_list_img.push_back(Image(_lmap[i]->getScreen()));
	this->_list_img.back().initialize();
	this->_list_img.back().setX(255);
	this->_list_img.back().setY(255);
      }
  }

  void	MapBox::update(Event* event)
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
	      this->_index = Core::confXML.getMaps().size() - 1;
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = MapBox::LEFT;
	    this->_shiftMap();
	  }
	if (keyboardEvent->getKeyCode() == Input::Keys::Right)
	  {
	    ++this->_index;
	    if (!Core::confXML.getMaps().empty())
	      this->_index %= Core::confXML.getMaps().size();
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = MapBox::RIGHT;
	    this->_shiftMap();
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
	      this->_index = Core::confXML.getMaps().size() - 1;
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = MapBox::LEFT;
	    this->_shiftMap();
	  }
	if (position.x > 0)
	  {
	    ++this->_index;
	    if (!Core::confXML.getMaps().empty())
	      this->_index %= Core::confXML.getMaps().size();
	    this->_shiftClock.reset();
	    this->_shiftClock.start();
	    this->_shift = MapBox::RIGHT;
	    this->_shiftMap();
	  }
      }
 }

  void  MapBox::draw()
  {
    if (this->_isSelect)
      {
	if (!this->_shiftClock.isRunning() ||
	    this->_shiftClock.isTimeOut(0.15f) ||
	    !this->_shift)
	  this->_select.draw();
	else
	  {
	    if (this->_shift == MapBox::LEFT)
	      this->_left.draw();
	    else
	      this->_right.draw();
	  }
      }
    else
      this->_normal.draw();
    this->_list_img[this->_index].draw();
  }

  void	MapBox::unload()
  {
    this->_normal.unload();
    this->_select.unload();
    this->_left.unload();
    this->_right.unload();
  }

  void	MapBox::setX(int x)
  {
    Button::setX(x);
    this->_left.setX(x);
    this->_right.setX(x);
  }

  void	MapBox::setY(int y)
  {
    Button::setY(y);
    this->_left.setY(y);
    this->_right.setY(y);
  }

  void	MapBox::setZ(int z)
  {
    Button::setZ(z);
    this->_left.setZ(z);
    this->_right.setZ(z);
  }

  void	MapBox::setPosition(int x, int y, int z)
  {
    Button::setPosition(x, y, z);
    this->_left.setPosition(x, y, z);
    this->_right.setPosition(x, y, z);

  }

  void	MapBox::setWidth(size_t width)
  {
    Button::setWidth(width);
    this->_left.setWidth(width);
    this->_right.setWidth(width);
  }

  void	MapBox::setHeight(size_t height)
  {
    Button::setHeight(height);
    this->_left.setHeight(height);
    this->_right.setHeight(height);
  }

  /*Profile*	MapBox::getProfile() const
  {
    if (this->_index < Core::confXML.getProfiles().size())
      return (Core::confXML.getProfiles()[this->_index]);
    return (0);
    }*/
}
