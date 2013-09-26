//
// GameManager.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sat Jun  1 11:17:21 2013 alexis leprovost
// Last update Sat Jun  8 22:50:31 2013 phalip_z
//

#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <queue>
#include <map>

#include "Profile.hh"
#include "Vector.hh"
#include "Timer.hh"
#include "Client/Interface/IWidgetObject.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Event/JoystickEvent.hh"

namespace Client
{
  class GameManager : public IWidgetObject
  {
  public:
    typedef std::queue<int>		Move;
    typedef std::map<Profile::Key, int>	Manual;
  private:
    size_t				_frame;
    std::map<Profile::Player, float>   _strength;
    std::map<Profile::Player, Timer>	_clock;
    std::map<Profile::Player, Move>	_move;
    std::map<Profile::Player, Timer>	_clock2;

    Vector	_getMove(Profile::Player id);
    void	_setMove(Profile::Player id);
    void	_setThrow(Profile::Player id);
    void	_setSpell(Profile::Player id);

    int		_getAngle(int keycode, Profile::Player id);
    bool	_isKeyMove(int keycode, Profile::Player id) const;
    bool	_isKeyThrow(int keycode, Profile::Player id) const;
    bool	_isKeySpell(int keycode, Profile::Player id) const;

    int		_getAngle(const Point &position);
    bool	_isKeyMove(const Point &position) const;

    void	_action(Profile::Player id);
  public:
    GameManager(size_t frame = 60);
    virtual ~GameManager();

    void		setFrame(size_t frame);
    size_t		getFrame() const;

    virtual void	initialize();
    virtual void	draw();
    virtual void	update(Event* event);
    void		update(KeyboardEvent* event, Profile::Player id);
    void		update(JoystickEvent* event, Profile::Player id);
    virtual void	unload();
  };
}

#endif /* _GAMEMANAGER_H_ */
