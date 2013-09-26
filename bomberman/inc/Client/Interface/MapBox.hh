//
// MapBox.hh for MapBox in /home/guiho_r/depot/bomberman/inc/Client/Interface
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jun  9 18:59:49 2013 ronan guiho
// Last update Sun Jun  9 19:50:52 2013 ronan guiho
//

#ifndef __MAPBOX_HH__
#define __MAPBOX_HH__

#include <vector>

#include "Timer.hh"
#include "Color.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/Image.hh"
#include "Client/Interface/Text.hh"
#include "Client/Controller/Input.hh"

namespace Client
{
  class MapBox : public Button
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
    int				_shift;
    std::vector<Image>		_list_img;
    Timer			_shiftClock;
    void			_shiftMap();
 public:
    MapBox(std::string const& normal, std::string const& select,
	       std::string const& left, std::string const& right,
	       bool isSelect = false);
    virtual ~MapBox();

    void		setX(int x);
    void		setY(int y);
    void		setZ(int z);
    void		setPosition(int x, int y, int z);
    void		setWidth(size_t width);
    void		setHeight(size_t height);

    //Map*		getMap() const;

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _MAPBOX_HH__ */
