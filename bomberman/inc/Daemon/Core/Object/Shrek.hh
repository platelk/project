#ifndef __SHREK_H__
# define __SHREK_H__

#include "GameObject.hh"
#include "Player.hh"

class Shrek : public Player
{
public:
  static const std::string & NAME;

  Shrek(Listener *owner = 0, const std::string &id = "0");
  virtual ~Shrek();
};


#endif /* !__SHREK_H__ */
