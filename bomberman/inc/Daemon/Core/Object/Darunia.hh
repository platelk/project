#ifndef __DARUNIA_H__
# define __DARUNIA_H__

#include "GameObject.hh"
#include "Player.hh"

class Darunia : public Player
{
public:
  static const std::string & NAME;

  Darunia(Listener *owner = 0, const std::string &id = "0");
  virtual ~Darunia();
};

#endif /* !__DARUNIA_H__ */
