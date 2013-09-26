//
// MushRoom.hh for MushRoom in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 02:41:54 2013 ronan guiho
// Last update Fri Jun  7 02:47:01 2013 ronan guiho
//

#ifndef __MUSHROOM_H__
#define __MUSHROOM_H__

#include "Decor.hh"

class MushRoom : public Decor
{
public:
  static const std::string NAME;

  MushRoom(Listener *parent = 0, const int life = 3, const int x = 0,
	   const int y = 0, const int z = 0);
  virtual ~MushRoom();
};

#endif
