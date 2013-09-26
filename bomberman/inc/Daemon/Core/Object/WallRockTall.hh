#ifndef __WALLROCKTALL_H__
#define __WALLROCKTALL_H__

#include "Decor.hh"

class WallRockTall : public Decor
{
public:
  static const std::string NAME;

  WallRockTall(Listener *parent = 0, int life = 1, int x = 0, int y = 0, int z = 0);
  virtual ~WallRockTall();
};

#endif
