//
// Ground.hh for Ground in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Fri Jun  7 18:27:53 2013 ronan guiho
// Last update Sun Jun  9 00:11:12 2013 ronan guiho
//

#ifndef __GROUND_HH__
#define __GROUND_HH__

#include <string>

#include "GameObject.hh"

class Ground : public Daemon::GameObject
{
public:
  static const std::string NAME;

  Ground(Listener *parent = 0, const std::string &id = "0", const int x = 0, const int y = 0,
	 const int z = 0, const int size = 0, const std::string &texture = "");
  virtual ~Ground();
  Ground *clone(Listener *owner = 0) const;
};

#endif
