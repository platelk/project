//
// ProfileBox.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Wed Jun  5 11:30:25 2013 alexis leprovost
// Last update Sat Jun  8 08:44:31 2013 phalip_z
//

#ifndef _PROFILEBOX_H_
#define _PROFILEBOX_H_

#include <vector>

#include "Timer.hh"
#include "Color.hh"
#include "Profile.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/Image.hh"
#include "Client/Interface/Text.hh"
#include "Client/Controller/Input.hh"

namespace Client
{
  class ProfileBox : public Button
  {
  public:
    enum
      {
	NONE = 0,
	LEFT,
	RIGHT
      };
  private:
    size_t			_index;
    Image			_left;
    Image			_right;
    Image			_level;
    int				_shift;
    Text			_name;
    Text			_playersKilled;
    Text			_gamesPlayed;
    Text			_damages;
    Text			_xp;
    Timer			_shiftClock;

    void			_shiftProfile();
 public:
    ProfileBox(std::string const& normal, std::string const& select,
	       std::string const& left, std::string const& right,
	       bool isSelect = false);
    virtual ~ProfileBox();

    void		setX(int x);
    void		setY(int y);
    void		setZ(int z);
    void		setPosition(int x, int y, int z);
    void		setWidth(size_t width);
    void		setHeight(size_t height);

    Profile*		getProfile() const;

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _PROFILEBOX_H_ */
