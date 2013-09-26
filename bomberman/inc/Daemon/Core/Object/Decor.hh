#ifndef __Decor_H__
#define __Decor_H__

#include "GameObject.hh"
#include "Render.hh"

class Decor : public Daemon::GameObject
{
public:
  static const std::string	NAME;

  Decor(Listener *parent = 0, int life = 3, int x = 0, int y = 0, int z = 0);
  virtual ~Decor();
};

#endif
