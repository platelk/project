//
// Text.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 19:50:51 2013 alexis leprovost
// Last update Sun Jun  9 08:50:44 2013 alexis leprovost
//

#ifndef _TEXT_H_
#define _TEXT_H_

#include <map>

#include "Color.hh"
#include "Vector.hh"
#include "Client/Interface/IWidgetObject.hh"
#include "Client/Interface/TextManager.hh"

namespace Client
{
  class Text : public IWidgetObject
  {
  public:
    typedef std::map<char, int>	Manual;
  private:
    std::string	_text;
    size_t	_size;
    Vector	_rotation;
    Color	_color;
  public:
    Text(std::string const& text = "", size_t size = 14,
	 Color const& color = Color(0.0f, 0.0f, 0.0f));
    virtual ~Text();

    void		setSize(size_t size);
    void		setText(std::string const& text);
    void		setColor(float red, float green, float blue);

    size_t		getSize() const;
    std::string const&	getText() const;
    Color const&	getColor() const;
    void		setRotation(float x, float y, float z);

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();

    static TextManager	manager;
    static bool		init;
    static Manual	manual;
 };
}

#endif /* _TEXT_H_ */
