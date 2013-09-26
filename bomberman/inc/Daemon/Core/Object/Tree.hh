//
// Tree.hh for Tree in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Object
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 14:33:34 2013 ronan guiho
// Last update Fri Jun  7 14:34:34 2013 ronan guiho
//

#ifndef __TREE_HH__
#define __TREE_HH__

#include "Decor.hh"

class Tree : public Decor
{
public:
  static const std::string	NAME;

  Tree(Listener *parent = 0, int life = 3, int x = 0, int y = 0, int z = 0);
  virtual ~Tree();
};

#endif
