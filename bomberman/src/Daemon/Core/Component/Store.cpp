//
// Store.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Component/Store.cpp in /home/vink/projet/cpp/bomberman
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sun Jun  2 23:26:34 2013 kevin platel
// Last update Mon Jun  3 13:16:02 2013 kevin platel
//

#include "Store.hh"

namespace Daemon
{

  const	std::string Store::NAME = "store";

  Store::Store(GameObject *owner)
    : AComponent(Store::NAME, "player", owner)
  {
  }

  Store::~Store()
  {
  }

  void	Store::newStock(const std::string &name, size_t max, size_t quantity)
  {
    (this->_store[name]).first = max;
    (this->_store[name]).second = quantity;
  }

  void	Store::store(const std::string &name, size_t quantity)
  {
    if (this->_store.find(name) != this->_store.end())
      {
	if ((this->_store[name].second + quantity) > this->_store[name].first)
	  this->_store[name].second = this->_store[name].first;
	else
	  (this->_store[name]).second += quantity;
      }
  }

  bool	Store::take(const std::string &name, size_t quantity)
  {
    if (this->_store.find(name) != this->_store.end())
      {
	if (this->_store[name].second >= quantity)
	  {
	    this->_store[name].second -= quantity;
	    return true;
	  }
	else
	  return false;
      }
    else
      return false;
  }

  void	Store::setMax(const std::string &name, size_t max)
  {
    if (this->_store.find(name) != this->_store.end())
      {
	this->_store[name].first = max;
	if (this->_store[name].second > this->_store[name].first)
	  this->_store[name].second = this->_store[name].first;
      }
  }

  size_t	Store::getMax(const std::string &name) const
  {
    std::map<std::string, std::pair<size_t, size_t> >::const_iterator it = this->_store.find(name);

    if (it != this->_store.end())
      {
	return (it->second).first;
      }
    return 0;
  }

  size_t	Store::getQuantity(const std::string &name) const
  {
    std::map<std::string, std::pair<size_t, size_t> >::const_iterator it = this->_store.find(name);

    if (it != this->_store.end())
      {
	return (it->second).second;
      }
    return 0;
  }

  bool		Store::haveStock(const std::string &name) const
  {
    return (this->_store.find(name) != this->_store.end());
  }

  void		Store::update()
  {
  }

  std::string	Store::serialize()
  {
    std::string s = this->createData(static_cast<int>(this->_store.size()));
    std::map<std::string, std::pair<size_t, size_t> >::iterator it = this->_store.begin();

    while (it != this->_store.end())
      {
	s += this->createData(it->first);
	s += this->createData(static_cast<int>((it->second).first));
	s += this->createData(static_cast<int>((it->second).second));
      }
    return this->createPackage(s);
  }

  Daemon::Store*	Daemon::Store::unserialize(std::stringstream &s, Daemon::GameObject *owner)
  {
    Store*	ptr = new Store(owner);
    std::stringstream	ss;
    int	i = 0;

    ss << this->unPack(s);
    i = str_to_int(this->getData(ss));
    while (i)
      {
	ptr->newStock(this->getData(ss), str_to_int(this->getData(ss)), str_to_int(this->getData(ss)));
	i--;
      }
    return ptr;
  }

  Daemon::Store*	Daemon::Store::clone(Daemon::GameObject *owner) const
  {
    return new Store(owner);
  }
}
