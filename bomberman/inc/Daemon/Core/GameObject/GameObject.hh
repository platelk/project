#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <iostream>
#include "AEntity.hh"
#include "AComponent.hh"

namespace Daemon
{
  class AComponent;

  class GameObject : public AEntity
  {
  protected:
    std::map<std::string, AComponent *> _component;

    std::string	serializeComponent();
  public:
    static const std::string &NAME;

    GameObject(const std::string &type, Listener *parent = 0);
    virtual ~GameObject();

    /* data */
    virtual void		init();

    virtual void		update();
    void		addComponent(AComponent *component);
    AComponent		*getComponent(const std::string &name);
    AComponent		*getComponentFamily(const std::string &name);
    bool		haveComponent(const std::string &name) const;
    bool		haveComponentFamily(const std::string &name) const;
    void		removeComponent(const std::string &name);
    void		unrefComponent(const std::string &name);

    void		transfertIn(GameObject &g);

    std::string	serialize();
    static GameObject	*unserialize(const std::string &s);
    void		unserializeComponent(std::stringstream &ss);

    GameObject 	operator=(GameObject const &obj);
    bool 		operator==(GameObject const &obj);

    virtual GameObject		*clone(Listener *owner = 0) const;

    bool		hasBeenModify;
  };
}
#endif
