#ifndef __FLASH_H__
# define __FLASH_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class Flash : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    Flash(GameObject *owner = 0);
    virtual ~Flash();

    void	spellFlash();
    void	execFlash();
    void	eventFlash(Trame &trame);
    void	eventExecFlash(Trame &trame);

    void	init();

    void	update();
    std::string	serialize();
    Flash*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Flash*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__FLASH_H__ */
