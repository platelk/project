//
// Update.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Update.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu Jun  6 19:11:05 2013 kevin platel
// Last update Sun Jun  9 21:23:19 2013 kevin platel
//

#include "Factory.hh"
#include "Update.hh"
#include "Render.hh"
#include "PlayerRender.hh"

namespace Daemon
{
  const std::string Update::NAME = "update";

  Update::Update(GameObject *owner)
    : AComponent(Update::NAME, "", owner)
  {
    if (this->_owner)
      {
	this->_owner->addEvent("tile", new Action<Update>(*this, &Update::eventUpdate));
	this->_owner->addEvent("player", new Action<Update>(*this, &Update::eventUpdate));
	this->_isInit = true;
      }
  }

  Update::~Update()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("player");
	this->_owner->removeEvent("tile");
      }
  }

  void	Update::init()
  {
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("tile", new Action<Update>(*this, &Update::eventUpdate));
	this->_owner->addEvent("player", new Action<Update>(*this, &Update::eventUpdate));
	this->_isInit = true;
      }
  }

  void	Update::eventUpdate(Trame &trame)
  {
    this->updateElem(trame.getId(), trame.getArgument());
  }

  void	Update::updateElem(int, const std::string &player)
  {
    GameObject	*ptr = 0;
    ptr = this->_owner;
    if (ptr)
      {
	GameObject	*character = 0;
	character = GameObjectFactory::factory.create(Daemon::GameObject::NAME, player, this->_owner);
	if (character)
	  {
	    for (size_t i = 0; i < Daemon::EventTree::core->_entity.size(); i++)
	      {
		if (Daemon::EventTree::core->_entity[i] != character && Daemon::EventTree::core->_entity[i]->getId() == character->getId())
		  {
		    character->removeComponent(Render::NAME);
		    character->removeComponent(PlayerRender::NAME);
		    character->transfertIn(*ptr);
		    delete character;
		    return ;
		  }
	      }
	    if (character->haveComponentFamily(Daemon::Render::NAME))
	      {
		Daemon::Render *p = dynamic_cast<Daemon::Render *>(character->getComponentFamily(Daemon::Render::NAME));
		if (p)
		  {
		    p->initialize();
		  }
	      }
	    character->init();
	  }
      }
  }

  void	Update::update()
  {
  }

  std::string  Update::serialize()
  {
    return this->createPackage("");
  }

  Update	*Update::unserialize(std::stringstream &s, GameObject *owner)
  {
    this->unPack(s);
    return new Update(owner);
  }

  Update	*Update::clone(GameObject *owner) const
  {
    return new Update(owner);
  }
}
