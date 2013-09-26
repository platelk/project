//
// Stage.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:57:46 2013 alexis leprovost
// Last update Wed May 29 13:47:44 2013 alexis leprovost
//

#include "Client/Interface/Stage.hh"

namespace Client
{
  std::string const	Stage::ADDED_TO_STAGE = "addedToStage";
  std::string const	Stage::REMOVED_TO_STAGE = "removeToStage";
  std::string const	Stage::ENTER_FRAME = "enterFrame";

  Stage*		Stage::_instance = 0;

  Stage::Stage()
    : Widget(""), _frame(60), _state(0)
  {
    this->setPosition(0, 0);
    this->setWidth(-1);
    this->setHeight(-1);
  }

  Stage::~Stage()
  {

  }

  void		Stage::setFrame(size_t frame)
  {
    this->_frame = frame;
  }

  size_t	Stage::getFrame() const
  {
    return (this->_frame);
  }

  void		Stage::setState(Widget* state)
  {
    this->_state = state;
  }

  Widget*	Stage::getState() const
  {
    return (this->_state);
  }

  Stage*	Stage::getInstance()
  {
    if (!Stage::_instance)
      Stage::_instance = new Stage();
    return (Stage::_instance);
  }
}
