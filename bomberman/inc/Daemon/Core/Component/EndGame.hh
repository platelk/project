#ifndef __EndGame_H__
#define __EndGame_H__

#include "AComponent.hh"
#include "GameObject.hh"
#include "Timer.hh"

namespace Daemon
{
  class EndGame : public AComponent
  {
  private:
    Timer t;
    double  _over;
  public:
    static const	std::string	NAME;

    EndGame(GameObject *owner = 0, double over = 60);
    virtual ~EndGame();

    void		eventEnd(Trame &);

    void		init();
    void		update();
    std::string 	serialize();
    EndGame*		unserialize(std::stringstream &s, Daemon::GameObject *owner = 0);
    EndGame*		clone(Daemon::GameObject *owner = 0) const;
  };
}

#endif /* !__EndGame_H__ */
