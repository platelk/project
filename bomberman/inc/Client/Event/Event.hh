//
// Event.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Sun May 12 12:11:26 2013 alexis leprovost
// Last update Sun Jun  9 16:58:30 2013 alexis leprovost
//

#ifndef _EVENT_H_
#define _EVENT_H_

#include <string>

namespace Client
{
  class Event
  {
  protected:
    std::string		_type;
    std::string		_name;

    Event(Event const& cpy);
    Event&	operator=(Event const& cpy);
  public:
    Event(std::string const& type, std::string const& name);
    virtual ~Event();

    std::string const&	getType() const;
    std::string const&	getName() const;

    static std::string const	MOUSE;
    static std::string const	KEYBOARD;
    static std::string const	JOYSTICK;
    static std::string const	CAMERA;
    static std::string const	UPDATE;
    static std::string const	DRAW;
    static std::string const	STATE;
    static std::string const	NETWORK;
    static std::string const	INITIALIZE;
    static std::string const	SYNCHRONISATION;
    static std::string const	START;
    static std::string const	END;
    static std::string const	SAVE;
  };
}

#endif /* _EVENT_H_ */
