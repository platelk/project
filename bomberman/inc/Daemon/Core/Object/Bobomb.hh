//
// Bobomb.hh for Bobomb in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 02:49:54 2013 ronan guiho
// Last update Sun Jun  9 03:24:12 2013 kevin platel
//

#ifndef __BOBOMB_HH__
#define __BOBOMB_HH__

#include "Decor.hh"

class Bobomb : public Decor
{
public:
  static const std::string	NAME;

  Bobomb(Listener *parent = 0, int life = 1, int x = 0, int y = 0, int z = 0);
  virtual ~Bobomb();
};

#endif
