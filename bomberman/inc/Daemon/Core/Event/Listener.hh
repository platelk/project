#ifndef __LISTENER_H__
# define __LISTENER_H__

#include <iostream>
#include <deque>
#include <map>

#include "Trame.hh"
#include "IAction.hh"
#include "Mutex.hh"
#include "LockScope.hh"
#include <stack>

namespace Daemon
{
  class Listener
  {
  protected:
    static size_t				  _id;
    size_t				          _my_id;
    Mutex                         _mutex;
    std::string				      _type;
    Listener*				      _parent;

    std::deque<Listener *>		        _child;
    std::map<std::string, IAction * >	_listen;
    std::stack<Listener *>				_to_delete;

    bool    execEvent(Trame &trame);
    void    sendEvent(Trame &trame, bool spread);

  public:
    Listener(const std::string & type, Listener *parent = 0);
    virtual ~Listener();

    void    addEvent(const std::string &event, IAction *action);
    void    addEvent(Trame &event, IAction *action);

    void    removeEvent(const std::string &event);
    void    removeEvent(Trame &event);
    void    removeChild(Listener *child);
    void    addChild(Listener *child);

    void    toDelete(Listener *child);
    void    clear();

    void	clearEvent();

    bool    findParent(Listener *child, const std::string &parent_type);

    void    disperse(Trame &trame, bool spread = false);

    bool    isListen(const std::string &event);
    bool    isListen(Trame &trame);

    std::string	    getType() const;
    int		        getId() const;
    Listener	    *getParent() const;

    void            setType(const std::string &type);
    void            setParent(Listener *parent);
    void            setId(size_t id);
  };
}
#endif /* !__LISTENER_H__ */
