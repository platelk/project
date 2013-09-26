//
// Stage.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:55:49 2013 alexis leprovost
// Last update Wed May 15 21:10:21 2013 alexis leprovost
//

#ifndef _STAGE_H_
#define _STAGE_H_

#include <string>
#include <sys/types.h>

#include "Client/Interface/Widget.hh"

namespace Client
{
  class Stage : public Widget
  {
  private:
    size_t	_frame;
    Widget*	_state;
    Stage();
    static Stage*	_instance;
  public:
    virtual ~Stage();

    void	setFrame(size_t frame);
    size_t	getFrame() const;

    void	setState(Widget* state);
    Widget*	getState() const;

    static Stage*	getInstance();

    static std::string const	ADDED_TO_STAGE;
    static std::string const	REMOVED_TO_STAGE;
    static std::string const	ENTER_FRAME;
  };
}

#endif /* _STAGE_H_ */
