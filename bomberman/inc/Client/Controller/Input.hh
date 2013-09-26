#ifndef __INPUT_H__
# define __INPUT_H__

#include	<map>

#include	"InputJoystick.hh"
#include	"Input.hpp"

namespace Client
{
  class Input
  {
    gdl::Input			*_input_key_mouse;
    Client::InputJoystick	_input_joystick;
  public:
    class Keys
    {
    public:
      enum Key
	{
	  A = 0, B, C, D, E, F, G, H, I, J, K, L, M,
	  N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	  Num0, Num1, Num2, Num3, Num4,
	  Num5, Num6, Num7, Num8, Num9,
	  Escape, LControl, LShift, LAlt, LSystem,
	  RControl, RShift, RAlt, RSystem, Menu,
	  LBracket, RBracket, SemiColon, Comma,
	  Period, Quote, Slash, BackSlash, Tilde,
	  Equal, Dash, Space, Enter, Back, Tab,
	  PageUp, PageDown, End, Home, Insert,
	  Delete, Add, Subtract, Multiply,
	  Divide, Left, Right, Up, Down,
	  Numpad0, Numpad1, Numpad2, Numpad3, Numpad4,
	  Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
	  F1, F2, F3, F4, F5, F6, F7, F8, F9,
	  F10, F11, F12, F13, F14, F15,
	  Pause, Count
	};
    private:
      Keys(){}
      ~Keys(){}
    };

    class Mouse
    {
    public:
      enum Button
	{
	  Left = 0, Right, Middle
	};
    private:
      Mouse(){}
      ~Mouse(){}
    };

    class JoystickButton
    {
    public:
    enum Button
      {
	A = 0, B, X, Y,
	LB, RB, BACK,
	START
      };
    private:
      JoystickButton(){}
      ~JoystickButton(){}
    };

    class JoystickAxes
    {
    public:
      enum Axis
	{
	  AX = 0, AY, AZ, BZ = 5, BX, BY
	};
    private:
      JoystickAxes(){}
      ~JoystickAxes(){}
    };

    Input(gdl::Input *input);
    Input();
    virtual ~Input();

    void	update(void);
    void	update(gdl::Input *input);
    bool	isKeyDown(Input::Keys::Key key);
    bool	isMouseButtonDown(Input::Mouse::Button but);
    int		getMousePositionX(void);
    int		getMousePositionY(void);
    bool	isJoystickButtonDown(Input::JoystickButton::Button but, int idjoy);
    int		getJoystickAxis(Input::JoystickAxes::Axis axis, int idjoy);
    bool	isMouseMove(void);
    void	initialize();

    int		getNbJoysticks(void) const;
  private:

    void	_initMaps();

    std::map<Input::Keys::Key, gdl::Keys::Key> _key;
    std::map<Input::Mouse::Button, gdl::Mouse::Button> _gdl_button;
    std::map<Input::JoystickButton::Button, InputJoystick::Button> _joystick_button;
    std::map<Input::JoystickAxes::Axis, InputJoystick::Axis> _joystick_axis;
    std::map<Input::JoystickAxes::Axis, int>			_value_axis;
    int		_mouse_x;
    int		_mouse_y;
  };
}

#endif /* !__INPUT_H__ */
