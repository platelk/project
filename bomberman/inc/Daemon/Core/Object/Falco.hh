#ifndef __FALCO_H__
# define __FALCO_H__

#include "GameObject.hh"
#include "Player.hh"

class Falco : public Player
{
public:
  static const std::string & NAME;

  Falco(Listener *owner = 0, const std::string &id = "0");
  virtual ~Falco();
};


#endif /* !__FALCO_H__ */
