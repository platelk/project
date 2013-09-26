#ifndef __GAME_H__
# define __GAME_H__

#include "GameObject.hh"

class Game : public Daemon::GameObject
{
public:
  static const std::string NAME;

  Game(Listener *parent = 0);
  virtual ~Game();

  Game	*clone(Listener *parent = 0) const;
};

#endif /* !__GAME_H__ */
