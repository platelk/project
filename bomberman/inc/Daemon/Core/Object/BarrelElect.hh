//
// BarrelElect.hh for BarrelElect in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 03:28:09 2013 ronan guiho
// Last update Fri Jun  7 15:56:42 2013 ronan guiho
//

#ifndef __BARREL_ELECT_HH__
#define __BARREL_ELECT_HH__

#include "Decor.hh"

class BarrelElect : public Decor
{
public:
  static const std::string	NAME;

  BarrelElect(Listener *parent = 0, int life = 3, int x = 0, int y = 0, int z = 0);
  virtual ~BarrelElect();
};

#endif
