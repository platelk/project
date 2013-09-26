#ifndef __CHOUXPETEUR_H__
# define __CHOUXPETEUR_H__

#include "GameObject.hh"
#include "AComponent.hh"
#include "Timer.hh"

namespace Daemon
{
  class ChouxPeteur : public AComponent
  {
  private:
    Timer	_t;
  public:
    static const std::string &NAME;

    ChouxPeteur(GameObject *owner = 0);
    virtual ~ChouxPeteur();

    void	spellChouxPeteur();
    void	eventChouxPeteur(Trame &trame);

    void	init();

    void	update();
    std::string	serialize();
    ChouxPeteur*	unserialize(std::stringstream &s, GameObject *owner = 0);
    ChouxPeteur*	clone(GameObject *owner = 0) const;
  };
}

#endif /* !__CHOUXPETEUR_H__ */
