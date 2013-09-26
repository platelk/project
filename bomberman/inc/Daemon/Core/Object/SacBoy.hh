#ifndef __SACBOY_H__
# define __SACBOY_H__

#include "GameObject.hh"
#include "Player.hh"

class SacBoy : public Player
{
public:
  static const std::string & NAME;

  SacBoy(Listener *owner = 0, const std::string &id = "0");
  virtual ~SacBoy();
};

#endif /* !__SACBOY_H__ */
