#ifndef __MEGAMAN_H__
# define __MEGAMAN_H__

#include "GameObject.hh"
#include "Player.hh"

class Megaman : public Player
{
public:
  static const std::string & NAME;

  Megaman(Listener *owner = 0, const std::string &id = "0");
  virtual ~Megaman();
};

#endif /* !__MEGAMAN_H__ */
