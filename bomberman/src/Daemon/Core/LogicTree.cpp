#include "LogicTree.hh"
#include "CreateGameObject.hh"

LogicTree::LogicTree()
: Client::IWidgetObject("LogicTree")
{
  this->_player_id = -1;
  this->_player = 0;

  if (Daemon::EventTree::core == 0)
    {
      GameObject *p = new GameObject("logic", 0);
      p->addComponent(new Daemon::CreateGameObject(this));
      Daemon::EventTree::core = new Daemon::Core;
      Daemon::EventTree::core->newEntity(p);
    }
}

LogicTree::~LogicTree()
{

}

Player	*LogicTree::getPlayer() const
{
	return this->_player;
}

std::deque<Daemon::GameObject *>&	LogicTree::getGameObject()
{
  return Daemon::EventTree::core->_entity;
}

void	LogicTree::initialize()
{

}

void	LogicTree::update(Client::Event *event)
{
  Client::TrameEvent *ptr = dynamic_cast<TrameEvent *>(event);
  Daemon::Trame *trame = new Trame(ptr->getTrame().toString());

  if (trame->getEvent() == "id_player")
    {
       this->_player_id = str_to_int(trame->getArgument());
    }
  for (int i = 0; i < Daemon::EventTree::core->_entity; ++i)
    {
      Daemon::EventTree::core->_entity[i]->disperse(trame, false);
    }
}

void	LogicTree::draw()
{

}

void	LogicTree::unload()
{

}
