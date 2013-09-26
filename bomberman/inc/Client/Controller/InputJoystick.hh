#ifndef __INPUTJOYSTICK_H__
# define __INPUTJOYSTICK_H__

#include	<string>
#include	<map>
#include	<utility>
#include	<linux/joystick.h>

namespace Client
{
  class InputJoystick
  {
  public:
    enum Button
      {
	A,
	B,
	X,
	Y,
	LB,
	RB,
	BACK,
	START
      };

    enum Axis
      {
	AX,
	AY,
	AZ,
	BZ = 5,
	BX,
	BY
      };

  private:
    class Joystick
    {
    public:
      Joystick(int fd);
      virtual	~Joystick();
      int		getFd(void) const;

    private:
      int		_fd;
      int		_nb_button;
      int		_nb_axis;
    };

  public:
    InputJoystick();
    virtual	~InputJoystick();
    bool	isJoyButtonDown(Button button, int idjoy);
    int		getAxisPos(Axis axis, int idjoy);
    int		nbJoystick(void) const;
    void	active(void);
    void	update(void);
    void	initJoystick(void);

  private:
    int		_nb_joy;
    std::string	_way_joy;
    bool	_up;
    int		_value_axis;

    std::map<int, std::pair<Joystick *, js_event> >	_joysticks;

    bool	isJoyButtonUp(void);
    void	readFd(int idjoy);
  };
}

#endif /* !__INPUTJOY_H__ */
