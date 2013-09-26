#ifndef __LINK_H__
# define __LINK_H__

#include "GameObject.hh"
#include "Player.hh"

class Link : public Player
{
public:
  static const std::string & NAME;

  Link(Listener *owner = 0, const std::string &id = "0");
  virtual ~Link();
};


#endif /* !__LINK_H__ */
