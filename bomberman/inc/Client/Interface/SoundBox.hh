//
// SoundBox.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Thu Jun  6 17:37:20 2013 alexis leprovost
// Last update Thu Jun  6 18:42:52 2013 alexis leprovost
//

#ifndef _SOUNDBOX_H_
#define _SOUNDBOX_H_

#include <string>

#include "Color.hh"
#include "Client/Interface/Button.hh"

namespace Client
{
  class SoundBox : public Button
  {
  private:
    Image	_bar;
    size_t	_power;
  public:
    SoundBox(std::string const& normal, std::string const& select,
	     Color const& color = Color(0.0f, 0.0f, 0.0f),
	     bool isSelect = false, size_t power = 100);
    virtual ~SoundBox();

    void		setWidthBar(size_t width);
    void		setHeightBar(size_t height);
    void		setPositionBar(int x, int y, int z);
    void		setColorBar(float red, float green, float blue);
    void		setPowerBar(size_t power);
    size_t		getPowerBar() const;

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _SOUNDBOX_H_ */
