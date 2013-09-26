//
// Bonus.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Bonus.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sat Jun  8 11:13:52 2013 kevin platel
// Last update Sun Jun  9 07:59:26 2013 kevin platel
//

#include <map>
#include <utility>

#include "AComponent.hh"
#include "Characteristic.hh"
#include "Timer.hh"

namespace Daemon
{
  class Bonus : public AComponent
  {
private:
    std::map<std::string, void (Bonus::*)() >	_func;

    Timer	_t;
    bool	_isActive;
    Characteristic *getCharac();
    std::string	_bonus_name;
  public:
    static const std::string & NAME;

    Bonus(GameObject *owner = 0);
    virtual ~Bonus();

    void	init();

    void	randomBonus();
    void	applyResi();
    void	applyDamage();
    void	applySpeed();
    void	applyASPD();
    void	applyStrength();
    void	applyRange();

    void	applyBonus(const std::string &name);

    void	update();
    std::string	serialize();
    Bonus*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Bonus*	clone(Daemon::GameObject *owner = 0) const;
  };
}
