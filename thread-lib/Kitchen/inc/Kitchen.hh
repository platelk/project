#ifndef __KITCHEN_H__
# define __KITCHEN_H__

#include <iostream>
#include "ThreadPool.hpp"
#include "NamedPipeManager.hh"

class Kitchen
{
  ThreadPool<int, Pizza *>	_cook;
  NamedPipeManager		_pipe;
  Stock				_stock;
public:
  Kitchen();
  virtual ~Kitchen();

  Pizza	*makePizza();
  bool	haveFreeCook();
  void	sendPizza();
  void	getCmd();
  void	sendState();
};

#endif /* !__KITCHEN_H__ */
