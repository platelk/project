//
// MouseEvent.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:27:01 2013 alexis leprovost
// Last update Tue May 21 10:58:40 2013 alexis leprovost
//

#ifndef _MOUSEEVENT_H_
#define _MOUSEEVENT_H_

#include <string>

#include "Point.hh"
#include "Client/Event/Event.hh"

namespace Client
{
  class MouseEvent : public Event
  {
  private:
    Point	_position;
  public:
    MouseEvent(std::string const& type, int x = 0, int y = 0);
    virtual ~MouseEvent();

    int	getPosX() const;
    int	getPosY() const;

    void	setPosX(int x);
    void	setPosY(int y);

    static std::string const	CLICK;
    static std::string const	MIDDLE_CLICK;
    static std::string const	RIGHT_CLICK;
    static std::string const	LEFT_CLICK;
    static std::string const	MOUSE_WHEEL;
    static std::string const	MOUSE_WHEEL_UP;
    static std::string const	MOUSE_WHEEL_DOWN;
    static std::string const	MOUSE_MOVE;
  };
}

#endif /* _MOUSEEVENT_H_ */
