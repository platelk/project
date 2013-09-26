#ifndef __KRATOS_H__
# define __KRATOS_H__

#include "GameObject.hh"
#include "Player.hh"

class Kratos : public Player
{
public:
  static const std::string & NAME;

  Kratos(Listener *owner = 0, const std::string &id = "0");
  virtual ~Kratos();
};


#endif /* !__KRATOS_H__ */
