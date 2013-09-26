#ifndef __SECRETFART_H__
# define __SECRETFART_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class SecretFart : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    SecretFart(GameObject *owner = 0);
    virtual ~SecretFart();

    void	init();

    void	spellSecretFart();
    void	eventSecretFart(Trame &trame);

    void	update();
    std::string	serialize();
    SecretFart*	unserialize(std::stringstream &s, GameObject *owner = 0);
    SecretFart*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__SECRETFART_H__ */
