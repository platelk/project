#ifndef __Bomb_H__
#define __Bomb_H__

#include "GameObject.hh"

class Bomb : public Daemon::GameObject
{
public:
  static const std::string	NAME;

  Bomb(Listener *parent = 0);
  virtual ~Bomb();

  Bomb *clone(Listener *owner = 0) const;
};

#endif
