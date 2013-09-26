//
// JoystickEvent.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 20 15:34:01 2013 alexis leprovost
// Last update Mon May 20 17:40:35 2013 alexis leprovost
//

#ifndef _JOYSTICKEVENT_H_
#define _JOYSTICKEVENT_H_

#include "Client/Event/Event.hh"
#include "Point.hh"

namespace Client
{
  class JoystickEvent : public Event
  {
  private:
    int		_id;
    Point	_axis;
    char       	_leftTrigger;
    int		_button;
  public:
    JoystickEvent(std::string const& type, int id, int x, int y);
    JoystickEvent(std::string const& type, int id, int button);
    JoystickEvent(std::string const& type, int id, bool leftTrigger);
    JoystickEvent(std::string const& type, int id);
    virtual ~JoystickEvent();

    Point const&	getAxisPosition();
    bool       		isLeftTrigger();
    bool       		isRightTrigger();
    int			getButton();
    int			getId();

    void	setAxisPosition(int x, int y);
    void	setAxisPosition(Point const& axis);
    void	setLeftTrigger();
    void	setRightTrigger();
    void	setButton(int button);

    static std::string const	AXIS;
    static std::string const	BUTTON;
    static std::string const	TRIGGER;
  };
}

#endif /* _JOYSTICKEVENT_H_ */
