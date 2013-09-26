//
// BlastBox.hh for BlastBox in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 03:22:42 2013 ronan guiho
// Last update Fri Jun  7 03:27:57 2013 ronan guiho
//


#ifndef __BLASTBOX_HH__
#define __BLASTBOX_HH__

#include "Decor.hh"

class BlastBox : public Decor
{
public:
  static const std::string	NAME;

  BlastBox(Listener *parent = 0, int life = 3, int x = 0, int y = 0, int z = 0);
  virtual ~BlastBox();
};

#endif
