//
// UI.hh for /home/phalip_z/tmp/bomberman/inc/Client/Interface/UI.hh in /home/phalip_z//tmp/bomberman
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Sun Jun  9 13:46:54 2013 phalip_z
// Last update Sun Jun  9 14:24:26 2013 phalip_z
//

#ifndef	_UI_H_
# define _UI_H_

#include	<vector>

#include	"Client/Interface/Image.hh"
#include	"Client/Interface/Text.hh"

namespace Client
{
  class	Ui : public IWidgetObject
  {
    Image			_gui;
    std::vector<Text >		_data;
    bool			_on_left;

  public:

    Ui(const std::string &texture, bool on_left);
    virtual ~Ui();

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();

  };
}

#endif  /* _UI_H_ */
