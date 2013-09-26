#ifndef __RESEAU_H__
# define __RESEAU_H__

#include "AComponent.hh"
#include "GameObject.hh"

namespace Daemon
{
  class Networks : public AComponent
  {
  private:
    std::string	_id;
    bool	_state;
    bool	_sync;
  public:
    static const	std::string	NAME;
    Networks(GameObject *owner = 0, const std::string &id = "0");
    virtual ~Networks();

    void	init();

    std::string		getId();
    void		setId(const std::string &id);
    void		sendTo(const std::string &msg);

    void		setState(const std::string &state);
    void		eventConnected(Trame &trame);
    void		eventSendTo(Trame &trame);
    void		eventSync(Trame &trame);
    void		eventDisconnect(Trame &trame);

    bool		isSync();
    void		sync(bool s);

    void		update();
    std::string 	serialize();
    Networks*	unserialize(std::stringstream &s, GameObject *owner = 0);
    Networks*	clone(Daemon::GameObject *owner = 0) const;
  };
}

#endif /* !__RESEAU_H__ */
