//
// Screener.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/bomberman
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun Jun  9 17:45:50 2013 alexis leprovost
// Last update Sun Jun  9 18:16:51 2013 alexis leprovost

#include "Client/Interface/Screener.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Screenshot/Screenshot.hh"
#include "Client/Interface/LogicTree.hh"
#include "Client/Core.hh"

namespace Client
{
  Screener::Screener()
    : IWidgetObject(Interface::SCREENER), _screen(false)
  {

  }

  Screener::~Screener()
  {

  }

  void	Screener::initialize()
  {
    this->_screen = false;
    this->_clock.reset();
    this->_clock.start();
  }

  void	Screener::update(Event*)
  {
    if (!this->_screen && !this->isHidden() && this->_clock.isTimeOut(10))
      {
	Widget* widget = Stage::getInstance()->getChild(Interface::GAME);
	Screenshot	screen(Screenshot::PNG);
	LogicTree*	logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	size_t a = rand() % 9999;
	size_t b = rand() % 9999;
	std::string name = "screen_" + int_to_str(a) + "_" + int_to_str(b);
	std::string dir = "./conf/screens/";
	screen.captureScreen(name, dir,  Core::WIDTH, Core::HEIGHT, 0, 0);
	Core::confXML.addMap(new Map(int_to_str(rand() % 9999) + "-" + int_to_str(rand() % 9999), rand(), logicTree->getMap(), dir + name + ".png"));
	this->_screen = true;
	this->_clock.reset();
      }
  }

  void	Screener::draw()
  {

  }

  void	Screener::unload()
  {

  }
}
