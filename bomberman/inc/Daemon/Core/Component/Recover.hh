#ifndef __RECOVER_H__
# define __RECOVER_H__

#include "AComponent.hh"
#include "Tools/Timer.hh"

namespace Daemon
{
  class Recover : public AComponent
  {
  private:
    Timer	_t;
    double	_recover;
  public:
    static const std::string & NAME;

    Recover(GameObject *owner = 0, double recover = 5.0);
    virtual ~Recover();

    double	getRecover() const;
    void	setRecover(double recover);

    void	init();

    void	update();
    std::string	serialize();
    Recover*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Recover*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__RECOVER_H__ */
