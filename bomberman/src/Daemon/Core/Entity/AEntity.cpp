#include	<iostream>
#include	"AEntity.hh"

Daemon::AEntity::AEntity(const std::string &type, Daemon::Listener *elem, const std::string &parent)
: Daemon::Listener(type)
{
  this->init();
  if (elem)
    {
      if (parent != "")
	elem->findParent(this, parent);
      else
	{
	  elem->addChild(this);
	  this->setParent(elem);
	}
    }
}

Daemon::AEntity::~AEntity()
{
	this->del();
}

double	Daemon::AEntity::getTimeElapse()	const
{
  return ((clock() - this->current_time) / CLOCKS_PER_SEC);
}

void   	Daemon::AEntity::updateTimer()
{
  this->current_time = clock();
}

void	Daemon::AEntity::init()
{
	this->updateTimer();
}

void	Daemon::AEntity::del()
{
}
