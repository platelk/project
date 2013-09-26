#ifndef __DeleteBuff_H__
#define __DeleteBuff_H__

#include "AComponent.hh"
#include "GameObject.hh"
#include "Timer.hh"

namespace Daemon
{
  class DeleteBuff : public AComponent
  {
  private:
    Timer t;
    double  _over;
    Daemon::GameObject  *_obj;
  public:
    static const	std::string	NAME;

    DeleteBuff(GameObject *owner = 0, double over = 0);
    virtual ~DeleteBuff();

    void    deleteGameObject(Daemon::GameObject *obj);

    void		update();
    std::string 	serialize();
    DeleteBuff*		unserialize(std::stringstream &s, Daemon::GameObject *owner = 0);
    DeleteBuff*		clone(Daemon::GameObject *owner = 0) const;
  };
}

#endif /* !__DeleteBuff_H__ */
