//
// Box.hh for Box in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun Jun  9 00:03:42 2013 ronan guiho
// Last update Sun Jun  9 00:13:55 2013 ronan guiho
//

#ifndef __BOX_HH__
#define __BOX_HH__

#include "GameObject.hh"

class Box : public Daemon::GameObject
{
public:
  static const std::string NAME;
  Box(Listener *parent, const std::string &id, const int x, const int y, const int z, const float size);
  virtual ~Box();
  Box *clone(Listener *owner = 0) const;
};

#endif
