//
// Image.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 13:13:02 2013 alexis leprovost
// Last update Sun Jun  9 08:25:06 2013 alexis leprovost
//

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Image.hpp"
#include "Color.hh"
#include "Vector.hh"
#include "Client/Interface/IWidgetObject.hh"

namespace Client
{
  class Image : public IWidgetObject
  {
    Color	_color;
    std::string	_filename;
    Vector	_rotation;
    bool	_isInit;
    gdl::Image	_texture;
  public:
    Image(std::string const& filename, Color const& color = Color(1.0f, 1.0f, 1.0f));
    Image(float red, float green, float blue,
	  std::string const& filename = "assets/clips/menu/default.png");
    Image(Color const& color,
	  std::string const& filename = "assets/clips/menu/default.png");
    virtual ~Image();

    bool		isInit() const;

    void		setFilename(std::string const& filename);
    std::string const&	getFilename() const;
    void		setColor(float red, float green, float blue);
    void		setColor(Color const& color);
    Color const&	getColor() const;
    void		setRotation(float x, float y, float z);
    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _IMAGE_H_ */
