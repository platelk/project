#ifndef __ACOMPONENT_H__
#define __ACOMPONENT_H__

#include <iostream>
#include <deque>

#include "IAction.hh"
#include "utils.hh"

namespace Daemon
{
  class GameObject;
  class AComponent
  {
  private:
    std::string			_name;
  protected:
    std::string			_family;
    GameObject*			_owner;
    bool			_isInit;
    std::deque<AComponent *>	_child;

    std::string		createData(const std::string &s);
    std::string		createData(int i);
    std::string		createData(double i);
    std::string		createPackage(const std::string &a);
    std::string		unPack(std::stringstream &s);
    std::string		getData(std::stringstream &s);
    std::string		getData(const std::string &s);
  public:
    AComponent(const std::string &name, const std::string &family = "", GameObject *owner = 0);
    virtual ~AComponent();

    virtual void	init();


    virtual void	update() = 0;
    virtual std::string serialize() = 0;
    virtual AComponent* unserialize(std::stringstream & s, GameObject *owner = 0) = 0;
    virtual AComponent	*clone(GameObject *owner = 0) const = 0;

    void	setName(const std::string &name);
    void	setOwner(GameObject *owner);
    std::string	getName() const;
    std::string	getFamily() const;
    GameObject*	getOwner() const;
    void	addChild(AComponent *child);
    void	removeChild(AComponent *child);

  };
}

#endif
