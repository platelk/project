#ifndef __STOCK_H__
# define __STOCK_H__

#include <iostream>
#include <map>

#include "Timer.hh"
#include "Ingredient.hh"

class Stock
{
  std::map<std::string, size_t>	_stock;
  Timer					_timer;
  double				_up_stock;
public:
  Stock(double up_time);
  virtual ~Stock();

  Ingredient	*getIngredient(std::string const &name, size_t nb = 1);
  bool		haveIngredient(std::string const &name, size_t nb = 1);
  void		updateStock();
};

#endif /* !__STOCK_H__ */
