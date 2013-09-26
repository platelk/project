#ifndef __IENTITY_H__
#define __IENTITY_H__

namespace Daemon
{
	class IEntity
	{
	public:
		virtual ~IEntity() {}

	/* data */
		virtual void	del() = 0;
		virtual void	init() = 0;
		virtual void	update() = 0;
	};
}

#endif