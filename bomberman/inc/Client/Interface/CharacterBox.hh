//
// CharacterBox.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Fri Jun  7 12:22:55 2013 alexis leprovost
// Last update Sun Jun  9 10:59:43 2013 alexis leprovost
//

#ifndef _CHARACTERBOX_H_
#define _CHARACTERBOX_H_

#include <vector>

#include "Text.hh"
#include "Timer.hh"
#include "Image.hh"
#include "PlayerRender.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/Image.hh"
#include "Client/Event/Event.hh"

namespace Client
{
  namespace State
  {
    enum State
      {
	SELECT1 = 0,
	SELECT2,
	NORMAL,
	LOCK,
	COUNT,
	DISABLE
      };
  }
  class CharacterBox : public Button
  {
  public:
    struct Character
    {
      Character(std::string const& name);
      ~Character();

      void	initialize();
      void	draw();

      std::string		name;
      Daemon::PlayerRender	model;
      Image			image[State::COUNT];
      State::State		state;
    };
    typedef std::vector<Character>	Manual;
  private:
    Manual	_manual;
    int		_index[2];
    bool	_lock[2];
    int		_angle;
    Timer	_clock;

    void	_up(int id);
    void	_down(int id);
    void	_left(int id);
    void	_right(int id);
    void	_choose(int id);
 public:
    CharacterBox();
    virtual ~CharacterBox();

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
    virtual size_t	getLink(ButtonManager::Sens sens) const;

    std::string const	getPlayerName(int id);

    static std::string const	getRandName();
  };
}

#endif /* _CHARACTERBOX_H_ */
