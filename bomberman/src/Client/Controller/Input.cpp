//
// Input.cpp for /home/phalip_z/projet_tek2/Bomberman/controller/src/Input.cpp in /home/phalip_z//projet_tek2/Bomberman/controller/inc
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Fri May 17 15:45:35 2013 phalip_z
// Last update Tue Jun  4 16:25:10 2013 phalip_z
//

#include	<iostream>

#include	"Client/Controller/Input.hh"

namespace Client
{
  Input::Input(gdl::Input *input)
    : _input_key_mouse(input), _input_joystick(InputJoystick())
  {
    this->_mouse_x = this->_input_key_mouse->getMousePositionX();
    this->_mouse_y = this->_input_key_mouse->getMousePositionY();
    this->_initMaps();
  }

  Input::Input()
    : _input_key_mouse(0), _input_joystick(InputJoystick())
  {
    this->_mouse_x = -1;
    this->_mouse_y = -1;
    this->_initMaps();
  }

  void	Input::initialize()
  {
    this->_input_joystick.initJoystick();
  }

  Input::~Input(){}

  void Input::_initMaps(void)
  {
    int	i;

    for (i = 0; i <= Input::Keys::Count; ++i)
      this->_key[static_cast<Input::Keys::Key>(i)] = static_cast<gdl::Keys::Key>(i);
    for (i = 0; i <= Input::Mouse::Left; ++i)
      this->_gdl_button[static_cast<Input::Mouse::Button>(i)] = \
	static_cast<gdl::Mouse::Button>(i);
    for (i = 0; i <= Input::JoystickButton::START; ++i)
      this->_joystick_button[static_cast<Input::JoystickButton::Button>(i)] =
	static_cast<InputJoystick::Button>(i);
    for (i = 0; i <= Input::JoystickAxes::AZ; ++i)
      this->_joystick_axis[static_cast<Input::JoystickAxes::Axis>(i)] =
	static_cast<InputJoystick::Axis>(i);
    for (i =  Input::JoystickAxes::BZ; i <= Input::JoystickAxes::BY; ++i)
      this->_joystick_axis[static_cast<Input::JoystickAxes::Axis>(i)] =
	static_cast<InputJoystick::Axis>(i);
    this->_value_axis[Input::JoystickAxes::AX] = 0;
    this->_value_axis[Input::JoystickAxes::AY] = 0;
    this->_value_axis[Input::JoystickAxes::BX] = 0;
    this->_value_axis[Input::JoystickAxes::BY] = 0;
  }

  void       	Input::update(void)
  {
    this->_input_joystick.update();
    this->_input_joystick.active();
  }

  void		Input::update(gdl::Input *input)
  {
    this->_input_key_mouse = input;
    this->update();
  }

  bool		Input::isKeyDown(Input::Keys::Key key)
  {
    return (this->_input_key_mouse->isKeyDown(this->_key[key]));
  }

  bool		Input::isMouseButtonDown(Input::Mouse::Button but)
  {
    return (this->_input_key_mouse->isMouseButtonDown(this->_gdl_button[but]));
  }

  bool		Input::isMouseMove(void)
  {
    if (this->_input_key_mouse->getMousePositionX() !=  0 ||
	this->_input_key_mouse->getMousePositionY() != 0)
      /*if ((this->_mouse_x != this->_input_key_mouse->getMousePositionX())
	|| (this->_mouse_y != this->_input_key_mouse->getMousePositionY()))*/
      return true;
    return false;
  }

  int		Input::getMousePositionX(void)
  {
    this->_mouse_x = this->_input_key_mouse->getMousePositionX();
    return (this->_mouse_x);
  }

  int		Input::getMousePositionY(void)
  {
    this->_mouse_y = this->_input_key_mouse->getMousePositionY();
    return (this->_mouse_y);
  }

  bool		Input::isJoystickButtonDown(Input::JoystickButton::Button but, int idjoy)
  {
    return (this->_input_joystick.isJoyButtonDown(this->_joystick_button[but], idjoy));
  }

  int		Input::getJoystickAxis(Input::JoystickAxes::Axis axis, int idjoy)
  {
    if (this->_input_joystick.getAxisPos(this->_joystick_axis[axis], idjoy) == 1)
      return this->_value_axis[axis];
    else
      this->_value_axis[axis] = this->_input_joystick.getAxisPos(this->_joystick_axis[axis], idjoy);
    return (this->_value_axis[axis]);
  }

  int		Input::getNbJoysticks(void) const
  {
    return this->_input_joystick.nbJoystick();
  }
};
