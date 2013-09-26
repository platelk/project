#ifndef __NARUTO_H__
# define __NARUTO_H__

#include "GameObject.hh"
#include "Player.hh"

class Naruto : public Player
{
public:
  static const std::string & NAME;

  Naruto(Listener *owner = 0, const std::string &id = "0");
  virtual ~Naruto();
};

#endif /* !__NARUTO_H__ */
