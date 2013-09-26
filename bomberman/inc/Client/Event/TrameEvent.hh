//
// TrameEvent.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 09:06:21 2013 alexis leprovost
// Last update Sat Jun  1 01:13:58 2013 alexis leprovost
//

#ifndef _TRAMEEVENT_H_
#define _TRAMEEVENT_H_

#include <string>

#include "Trame.hh"
#include "Client/Event/Event.hh"

namespace Client
{
  class TrameEvent : public Event
  {
  private:
    Daemon::Trame	_trame;
  public:
    TrameEvent(std::string const& type, Daemon::Trame const& trame = Daemon::Trame(""));
    virtual ~TrameEvent();

    Daemon::Trame const&	getTrame() const;
    Daemon::Trame&		getTrame();
    void			setTrame(Daemon::Trame const& trame);

    static std::string const	TRAME;
  };
}

#endif /* _TRAMEEVENT_H_ */
