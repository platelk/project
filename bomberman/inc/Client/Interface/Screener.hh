//
// Screener.hh for bomberman in /home/leprov_a//project/tek2/bomberman/bomberman
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun Jun  9 17:48:43 2013 alexis leprovost
// Last update Sun Jun  9 18:16:05 2013 alexis leprovost
//

//

#ifndef _SCREENER_H_
#define _SCREENER_H_

#include "Timer.hh"
#include "Client/Interface/IWidgetObject.hh"

namespace Client
{
  class Screener : public IWidgetObject
  {
  private:
    bool	_screen;
    Timer	_clock;
  public:
    Screener();
    virtual ~Screener();

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _SCREENER_H_ */
