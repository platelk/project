//
// KeyboardEvent.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:27:20 2013 alexis leprovost
// Last update Mon May 20 18:34:46 2013 alexis leprovost
//

#ifndef _KEYBOARDEVENT_H_
#define _KEYBOARDEVENT_H_

#include <sys/types.h>
#include <string>

#include "Client/Event/Event.hh"

namespace Client
{
  class KeyboardEvent : public Event
  {
  private:
    size_t	_keyCode;
    bool	_ctrl;
    bool	_shift;
  public:
    KeyboardEvent(std::string const& type, size_t keyCode = 0,
		  bool ctrl = false, bool shift = false);
    virtual ~KeyboardEvent();

    void		setKeyCode(size_t keyCode);
    void		setCtrl(bool ctrl);
    void		setShift(bool shift);

    size_t	getKeyCode() const;

    bool	isPressedCtrl() const;
    bool	isPressedShift() const;

    static std::string const	KEY_DOWN;
    static std::string const	KEY_UP;
  };
}

#endif /* _KEYBOARDEVENT_H_ */
