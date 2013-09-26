#ifndef __NEWPLAYER_H__
#define __NEWPLAYER_H__

#include "AComponent.hh"
#include "GameObject.hh"

namespace Daemon
{
  class NewPlayer : public AComponent
  {
  public:
    static const	std::string	NAME;

    NewPlayer(GameObject *owner = 0);
    virtual ~NewPlayer();

    void	init();

    void	addPlayer(const std::string &id);

    void	eventAddPlayer(Trame &trame);

    void		update();
    std::string 	serialize();
    NewPlayer*		unserialize(std::stringstream &s, Daemon::GameObject *owner = 0);
    NewPlayer*		clone(Daemon::GameObject *owner = 0) const;
  };
}

#endif /* !__NEWPLAYER_H__ */
