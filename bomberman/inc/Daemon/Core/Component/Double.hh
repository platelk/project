#ifndef __DOUBLE_H__
# define __DOUBLE_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Double : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Double(GameObject *owner = 0);
    virtual ~Double();

    void	spellDouble();
    void	eventDouble(Trame &trame);

    void	init();

    void	update();
    std::string	serialize();
    Double*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Double*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__DOUBLE_H__ */
