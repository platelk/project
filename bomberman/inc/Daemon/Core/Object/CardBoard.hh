//
// CardBoard.hh for CardBoard in /home/guiho_r/depot/bomberman/src/Daemon/Core/ObjectCreation
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Fri Jun  7 02:02:17 2013 ronan guiho
// Last update Sun Jun  9 03:24:30 2013 kevin platel
//

#ifndef __CARDBOARD_HH__
#define __CARDBOARD_HH__

#include <string>

#include "Decor.hh"

class CardBoard : public Decor
{
public:
  static const std::string NAME;

  CardBoard(Listener *parent = 0, const int life = 1, const int x = 0,
	    const int y = 0, const int z = 0);
  virtual ~CardBoard();
};

#endif
