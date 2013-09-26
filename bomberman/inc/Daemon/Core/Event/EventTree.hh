#ifndef __EVENTTREE_H__
# define __EVENTTREE_H__

#include <iostream>
#include <stack>

#include "Trame.hh"
#include "Listener.hh"
#include "Mutex.hh"
#include "ThreadPool.hpp"
#include "LockScope.hh"
#include "DaemonServer.hh"
#include "Core.hh"

namespace Daemon
{
  class EventTree
  {
  private:
    EventTree();
    ~EventTree();

    static Mutex			_mutex;
    static ThreadPool<Trame *, int>	_event;
  public:
    static Core				*core;
    static Listener			*root;
    static void				pushEvent(Trame *trame);
    static void				resolve();
    static int				spread(Trame *trame);
    static ExecuteQueue<std::string>	*reseau;
  };
}

#endif /* !__EVENTTREE_H__ */
