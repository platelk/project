#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameObject.hh"
#include "PlayerRender.hh"

class Player : public Daemon::GameObject
{
public:
  static const std::string NAME;

  Player(Listener *parent = 0, const std::string &id = "0", int life = 0, int x = 0, int y = 0, int z = 0);
  virtual ~Player();

  Player *clone(Listener *owner = 0) const;
  void	setNetId(const std::string &id);
  std::string	getNetId();
};

#endif

