#ifndef __UPDATE_H__
# define __UPDATE_H__

#include <iostream>
#include "AComponent.hh"
#include "EventTree.hh"
#include "Timer.hh"

namespace Daemon
{
  class Update : public AComponent
  {
  public:
    static const std::string NAME;

    Update(GameObject *owner);
    ~Update();

    void	init();

    void	update();
    std::string	serialize();
    Update*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Update*	clone(GameObject *owner = 0) const;

    void	eventUpdate(Trame &trame);
    void	updateElem(int id, const std::string &up);
  };
}

#endif /* !__UPDATE_H__ */
