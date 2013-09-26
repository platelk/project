#ifndef __LUCARIO_H__
# define __LUCARIO_H__

#include "GameObject.hh"
#include "Player.hh"

class Lucario : public Player
{
public:
  static const std::string & NAME;

  Lucario(Listener *owner = 0, const std::string &id = "0");
  virtual ~Lucario();
};

#endif /* !__LUCARIO_H__ */
