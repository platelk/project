#ifndef __PIT_H__
# define __PIT_H__

#include "GameObject.hh"
#include "Player.hh"

class Pit : public Player
{
public:
  static const std::string & NAME;

  Pit(Listener *owner = 0, const std::string &id = "0");
  virtual ~Pit();
};

#endif /* !__PIT_H__ */
