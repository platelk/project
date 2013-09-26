#ifndef __SONIC_H__
# define __SONIC_H__

#include "GameObject.hh"
#include "Player.hh"

class Sonic : public Player
{
public:
  static const std::string & NAME;
  Sonic(Listener *owner = 0, const std::string &id = "0");
  virtual ~Sonic();
};

#endif /* !__SONIC_H__ */
