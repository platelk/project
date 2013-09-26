#ifndef __SANDGROUND_HH__
#define __SANDGROUND_HH__

#include "GameObject.hh"
#include "Ground.hh"
#include "GroundRender.hh"

class SandGround : public Ground
{
public:
  static const std::string &NAME;
  SandGround(Listener *owner = 0, const std::string &id = "0", int x = 0, int y = 0, int z = 0, const float width = 0, const float heigth = 0);
  virtual ~SandGround();
};

#endif
