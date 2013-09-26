//
// LogicTree.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Fri May 31 20:23:04 2013 alexis leprovost
// Last update Sun Jun  9 17:17:53 2013 kevin platel
//

#ifndef __LOGIC_TREE__
#define __LOGIC_TREE__

#include "Client/Interface/IWidgetObject.hh"
#include "GameObject.hh"
#include "EventTree.hh"
#include "Player.hh"

class LogicTree : public Client::IWidgetObject
{
private:
  std::vector<int>			_player_id;
  std::vector<Daemon::GameObject *>	_player;

public:
  LogicTree();
  virtual ~LogicTree();

  /* data */
  int		getIdPlayer(int i = 0) const;
  Daemon::GameObject *getPlayer(int i = 0) const;
  std::deque<Daemon::GameObject *> &getGameObject();
  std::string	getMap();

  void	clear();
  void	unLoad();
  void	initialize();
  void	update(Client::Event *event);
  void	draw();
  void	unload();

  static bool	isInFieldOfVision(Daemon::GameObject *ref, Daemon::GameObject *toAff, size_t vision);
};

#endif
