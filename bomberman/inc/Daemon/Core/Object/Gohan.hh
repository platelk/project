//
// Gohan.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Daemon/Core/Object
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Fri Jun  7 11:57:02 2013 alexis leprovost
// Last update Fri Jun  7 11:57:11 2013 alexis leprovost
//

#ifndef __GOHAN_H__
# define __GOHAN_H__

#include "GameObject.hh"
#include "Player.hh"

class Gohan : public Player
{
public:
  static const std::string & NAME;

  Gohan(Listener *owner = 0, const std::string &id = "0");
  virtual ~Gohan();
};


#endif /* !__GOHAN_H__ */
