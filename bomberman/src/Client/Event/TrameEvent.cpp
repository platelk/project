//
// TrameEvent.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 09:07:00 2013 alexis leprovost
// Last update Sat Jun  1 01:14:09 2013 alexis leprovost
//

#include "Client/Event/TrameEvent.hh"

namespace Client
{
  std::string const	TrameEvent::TRAME = "trame";

  TrameEvent::TrameEvent(std::string const& type, Daemon::Trame const& trame)
    : Event(Event::NETWORK, type), _trame(trame)
  {

  }

  TrameEvent::~TrameEvent()
  {

  }

  Daemon::Trame const&	TrameEvent::getTrame() const
  {
    return (this->_trame);
  }

  Daemon::Trame&	TrameEvent::getTrame()
  {
    return (this->_trame);
  }

  void			TrameEvent::setTrame(Daemon::Trame const& trame)
  {
    this->_trame = trame;
  }
}
