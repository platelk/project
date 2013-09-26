//
// DispersalEffect.hh for DispersalEffect in /home/guiho_r/depot/bomberman/inc/Daemon/Core/Component
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sat Jun  8 16:57:13 2013 ronan guiho
// Last update Sat Jun  8 17:09:49 2013 ronan guiho
//

#ifndef __DISPERSAL_EFFECT_HH__
#define __DISPERSAL_EFFECT_HH__

#include <string>

#include "Vector.hh"
#include "DispersalEffect.hh"

class DispersalEffect : public Daemon::GameObject
{
public:
  static const std::string NAME;

  DispersalEffect(Listener *parent, const std::string &id, const int x, const int y,
		  const int z, const int count, const double size, const std::string &texture);
  DispersalEffect(Listener *parent, const std::string &id, const int x, const int y,
		  const int z, const int count, const double size, const Vector color);
  virtual ~DispersalEffect();
  DispersalEffect *clone(Listener *owner = 0) const;
};

#endif
