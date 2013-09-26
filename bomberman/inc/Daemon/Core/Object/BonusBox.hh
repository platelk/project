//
// BonusBox.hh for BonusBox in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jun  9 00:47:31 2013 ronan guiho
// Last update Sun Jun  9 00:52:07 2013 ronan guiho
//

#ifndef __BONUS_BOX_HH__
#define __BONUS_BOX_HH__

#include "Box.hh"
#include "GameObject.hh"

class BonusBox : public Box
{
public:
  static const std::string &NAME;
  BonusBox(Listener *owner = 0, const std::string &id = "0", int x = 0, int y = 0, int z = 0,
	   const float size = 0);
  virtual ~BonusBox();
};

#endif
