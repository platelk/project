#ifndef __IACTION_H__
#define __IACTION_H__

#include <iostream>
#include "Trame.hh"

namespace Daemon
{
	class IAction
	{
	public:
		virtual ~IAction() {}

		virtual void operator()(Trame &trame) = 0;
	};

	template<typename T>
	class Action : public IAction
	{
		typedef void	(T::*func_ptr)(Trame &);
		T						&obj;
		func_ptr				ptr;
	public:
		Action(T &obj, func_ptr ptr)
		: obj(obj), ptr(ptr)
		{
		}
		virtual ~Action() {}

		void	operator()(Trame &trame)
		{
			((this->obj).*(this->ptr))(trame);
		}
	};
}

#endif
