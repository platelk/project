//
// DeleteBuff.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/DeleteBuff.cpp in /home/vink/projet/cpp/bomberman/test
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon May 27 00:02:33 2013 kevin platel
// Last update Fri May 31 18:38:23 2013 alexis leprovost
//

#include <string>

#include "EventTree.hh"
#include "DeleteBuff.hh"
#include "Network.hh"
#include "Player.hh"
#include "utils.hh"

const std::string	Daemon::DeleteBuff::NAME = "delete_buff";

Daemon::DeleteBuff::DeleteBuff(Daemon::GameObject *owner, double over)
  : AComponent(DeleteBuff::NAME, "", owner), _over(over), _obj(0)
{
}

Daemon::DeleteBuff::~DeleteBuff()
{
}

void	Daemon::DeleteBuff::update()
{
  if (this->_obj && t.isTimeOut(this->_over))
  {
    (this->_obj->getParent())->removeChild(this->_owner);
    Daemon::EventTree::core->removeEntity(this->_obj);
    this->_obj = 0;
    t.stop();
  }
}

void  Daemon::DeleteBuff::deleteGameObject(Daemon::GameObject *obj)
{
  t.start();
  this->_obj = obj;
}

std::string	Daemon::DeleteBuff::serialize()
{
  return this->createPackage("");
}

Daemon::DeleteBuff	*Daemon::DeleteBuff::unserialize(std::stringstream &s, Daemon::GameObject *owner)
{
  std::stringstream ss;
  ss << this->unPack(s);
  return new DeleteBuff(owner);
}

Daemon::DeleteBuff	*Daemon::DeleteBuff::clone(Daemon::GameObject *owner) const
{
  return new DeleteBuff(owner);
}
