#ifndef __AENTITY_H__
#define __AENTITY_H__


#include	<utility>
#include	<string>
#include	<ctime>

#include 	"Listener.hh"
#include	"IEntity.hh"

namespace Daemon
{
	class AEntity : public Daemon::Listener, public IEntity
	{
	private:
		clock_t		current_time;
		
	public:
		AEntity(const std::string &type, Daemon::Listener *elem, const std::string &parent = "");
		virtual ~AEntity();
		
	/* data */
		double	getTimeElapse() const;
		void	updateTimer();
		
		virtual	void	init();
		virtual void	del();
		
		virtual void	update() = 0;
	};
}
#endif