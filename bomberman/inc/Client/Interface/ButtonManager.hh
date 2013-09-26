//
// ButtonManager.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Fri May 17 15:57:31 2013 alexis leprovost
// Last update Thu May 30 18:11:48 2013 alexis leprovost
//

#ifndef _BUTTONMANAGER_H_
#define _BUTTONMANAGER_H_

#include <list>

#include "Client/Interface/IWidgetObject.hh"
#include "Timer.hh"

namespace Client
{
  class Button;

  class ButtonManager : public IWidgetObject
  {
  public:
    enum Sens
      {
	Top = 0,
	Right,
	Bottom,
	Left
      };
  private:
    size_t		_index;
    std::list<Button*>	_buttons;
    Timer		_clock;
  public:
    ButtonManager();
    virtual ~ButtonManager();

    void	addButton(Button* button);
    void	delButton(Button* button);

    void	shift(ButtonManager::Sens sens);

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();
  };
}

#endif /* _BUTTONMANAGER_H_ */
