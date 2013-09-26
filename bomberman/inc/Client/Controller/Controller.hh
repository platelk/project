#ifndef __CONTROLLER_H__
# define __CONTROLLER_H__

#include	<queue>
#include	<map>

#include	"Client/Event/Event.hh"
#include	"Client/Controller/Input.hh"

namespace Client
{
  class Input;

  class Controller
  {
    std::queue<Event *>	_event;
    std::map<int, std::string> _mouse;

  public:
    Controller();
    virtual ~Controller();
    bool	hasEvent(void) const;
    void	setInput(Input &input);
    Event	*getEvent(void);

  private:
    bool	_isControlDown(Input &input);
    bool	_isShiftDown(Input& input);
    bool	_isControl(Input::Keys::Key key);
    bool	_isShift(Input::Keys::Key key);
    void	_setKeyboardEvent(Input& input);
    void	_setMouseEvent(Input& input);
    void	_setJoystickEvent(Input& input);
  };
}

#endif /* !__CONTROLLER_H__ */
