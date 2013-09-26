//
// UI.cpp for /home/phalip_z/tmp/bomberman/src/Client/Interface/UI.cpp in /home/phalip_z//tmp/bomberman
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Sun Jun  9 13:53:52 2013 phalip_z
// Last update Sun Jun  9 14:27:14 2013 phalip_z
//

#include	"Tools/utils.hh"
#include	"Client/Interface/Ui.hh"
#include	"Client/Interface/Interface.hh"
#include	"Client/Interface/LogicTree.hh"
#include	"Daemon/Core/Component/Characteristic.hh"
#include	"Daemon/Core/Component/ThrowBomb.hh"
#include	"Daemon/Core/Component/Life.hh"

namespace Client
{
  Ui::Ui(const std::string &texture, bool on_left)
    : IWidgetObject(Interface::UI), _gui(texture)
  {
    this->_on_left = on_left;
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
    this->_data.push_back(Text("0"));
  }

  Ui::~Ui()
  {
  }

  void	Ui::initialize()
  {

  }

  void	Ui::update(Event*)
  {
    LogicTree	*tree = dynamic_cast<LogicTree *>(this->getParent()->getWidgetObject(Interface::LOGIC_TREE));
    Daemon::GameObject		*player = tree->getPlayer();
    Daemon::Characteristic	*characts =
      dynamic_cast<Daemon::Characteristic *>(player->getComponent(Daemon::Characteristic::NAME));
    Daemon::ThrowBomb		*recover =
      dynamic_cast<Daemon::ThrowBomb *>(player->getComponent(Daemon::ThrowBomb::NAME));
    Daemon::Life		*life =
      dynamic_cast<Daemon::Life *>(player->getComponent(Daemon::Life::NAME));

    if (characts != 0)
      {
	this->_data[0] = Text(int_to_str(characts->getResi()));
	this->_data[1] = Text(int_to_str(characts->getDamage()));
	this->_data[2] = Text(int_to_str(characts->getStrength()));
	this->_data[3] = Text("0");
	this->_data[4] = Text("0");
	this->_data[5] = Text(double_to_str(characts->getSpeed()));
	this->_data[6] = Text(double_to_str(characts->getASPD()));
	this->_data[7] = Text(int_to_str(life->getLife()));
	this->_data[8] = Text(double_to_str(recover->getRecover()));
	this->_data[9] = Text(int_to_str(characts->getRange()));
      }
  }
  void	Ui::draw()
  {
    if (!this->isHidden())
      this->_gui.draw();
  }

  void	Ui::unload() 
  {
  
  }
}
