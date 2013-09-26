#ifndef __SELECTPLAYER_H__
# define __SELECTPLAYER_H__

#include "AComponent.hh"

namespace Daemon
{
  class SelectPlayer : public AComponent
  {
  public:
    static const	std::string	NAME;

    SelectPlayer(GameObject *owner = 0);
    virtual ~SelectPlayer();

    void	init();

    void	selectPlayer(int id, const std::string &player);

    void	eventSelectPlayer(Trame &trame);

    void	update();
    std::string	serialize();
    SelectPlayer*	unserialize(std::stringstream &s, GameObject *owner = 0);
    SelectPlayer*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__SELECTPLAYER_H__ */
