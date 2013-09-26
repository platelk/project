/*
** Palm.h for Palm in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun  7 14:26:25 2013 ronan guiho
// Last update Fri Jun  7 14:34:53 2013 ronan guiho
*/

#ifndef __PALM_HH__
#define __PALM_HH__

#include "Decor.hh"

class Palm : public Decor
{
public:
  static const std::string	NAME;

  Palm(Listener *parent = 0, int life = 3, int x = 0, int y = 0, int z = 0);
  virtual ~Palm();
};

#endif
