//
// Peach.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Daemon/Core/Object
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Fri Jun  7 11:56:11 2013 alexis leprovost
// Last update Fri Jun  7 12:08:15 2013 alexis leprovost
//

#ifndef __PEACH_H__
# define __PEACH_H__

#include "GameObject.hh"
#include "Player.hh"

class Peach : public Player
{
public:
  static const std::string & NAME;

  Peach(Listener *owner = 0, const std::string &id = "0");
  virtual ~Peach();
};

#endif /* !__PEACH_H__ */
