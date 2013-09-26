#ifndef __CORE_H__
#define __CORE_H__

#include <iostream>
#include <deque>
#include <vector>
#include "IEntity.hh"
#include "GameObject.hh"
#include "Mutex.hh"

namespace Daemon
{
  class Core
  {
  private:
    Mutex	_mutex;
    bool	_is_running;
  public:
    Core();
    virtual ~Core();

    void	newGame();
    void	endGame();
    bool	wait();
    bool	connection();
    bool	sync();
    void	getEvent();
    void	run();
    void	init();
    void	initEntity();
    void	loop();
    void	stop();
    void	reset();

    std::string	getMap();
    std::string	getPlayer();

    void	newEntity(GameObject *entity);
    void	removeEntity(GameObject *entity);

    std::deque<GameObject *>	_entity;
  };
}
#endif
