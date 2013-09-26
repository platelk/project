//
// Button.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 10:19:49 2013 alexis leprovost
// Last update Sat Jun  8 10:54:14 2013 alexis leprovost
//

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Timer.hh"
#include "Color.hh"
#include "Client/Interface/Image.hh"
#include "Client/Interface/IWidgetObject.hh"
#include "Client/Interface/ButtonManager.hh"

namespace Client
{
  class Button : public IWidgetObject
  {
  protected:
    Image	_normal;
    Image	_select;
    bool	_isSelect;
    std::string	_target;
    bool	_hasTarget;
    size_t	_link[4];
  public:
    Button(std::string const& normal, std::string const& select, bool isSelect = false);
    Button(Color const& normal, Color const& select, bool isSelect = false);
    virtual ~Button();

    void		select(bool isSelect);

    void		setTarget(std::string const& target);
    bool		hasTarget() const;
    std::string const&	getTarget() const;

    void		setLink(ButtonManager::Sens sens, size_t n);
    virtual size_t	getLink(ButtonManager::Sens sens) const;

    void		setX(int x);
    void		setY(int y);
    void		setZ(int z);
    void		setPosition(int x, int y, int z);
    void		setWidth(size_t width);
    void		setHeight(size_t height);

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _BUTTON_H_ */
