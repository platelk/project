//
// BarrelWood.hh for BarrelWood in /home/guiho_r/depot/bomberman/src/Tools
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 15:56:30 2013 ronan guiho
// Last update Fri Jun  7 15:58:18 2013 ronan guiho
//

#ifndef __BARREL_WOOD_HH__
#define __BARREL_WOOD_HH__

#include "Decor.hh"

class BarrelWood : public Decor
{
public:
  static const std::string	NAME;

  BarrelWood(Listener *parent = 0, int life = 3, int x = 0, int y = 0, int z = 0);
  virtual ~BarrelWood();
};

#endif
