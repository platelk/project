#ifndef __SUPERMAN_H__
# define __SUPERMAN_H__

#include "GameObject.hh"
#include "Player.hh"

class Superman : public Player
{
public:
  static const std::string & NAME;

  Superman(Listener *owner = 0, const std::string &id = "0");
  virtual ~Superman();
};

#endif /* !__SUPERMAN_H__ */
