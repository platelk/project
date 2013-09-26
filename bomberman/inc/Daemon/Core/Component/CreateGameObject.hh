#ifndef __CreateGameObject_H__
#define __CreateGameObject_H__

#include "AComponent.hh"
#include "GameObject.hh"

namespace Daemon
{
  class CreateGameObject : public AComponent
  {
  public:
    static const	std::string	NAME;

    CreateGameObject(GameObject *owner = 0);
    virtual ~CreateGameObject();

    void	createMap(const std::string &map);
    void	createPlayer(const std::string &player);

    void	eventMap(Daemon::Trame &trame);
    void	eventPlayer(Daemon::Trame &trame);

    void	init();

    void		update();
    std::string 	serialize();
    CreateGameObject*		unserialize(std::stringstream &s, Daemon::GameObject *owner = 0);
    CreateGameObject*		clone(Daemon::GameObject *owner = 0) const;
  };
}

#endif /* !__CreateGameObject_H__ */
