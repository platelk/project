#ifndef __MARIO_H__
# define __MARIO_H__

#include "GameObject.hh"
#include "Player.hh"

class Mario : public Player
{
public:
  static const std::string & NAME;

  Mario(Listener *owner = 0, const std::string &id = "0");
  virtual ~Mario();
};

#endif /* !__MARIO_H__ */
