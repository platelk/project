#ifndef __STORE_H__
# define __STORE_H__

#include <map>
#include <utility>
#include "AComponent.hh"

namespace Daemon
{
  class Store : public AComponent
  {
  private:
    std::map<std::string, std::pair<size_t, size_t> >	_store;
  public:
    static const std::string	NAME;

    Store(GameObject *owner = 0);
    virtual ~Store();

    void	newStock(const std::string &name, size_t max, size_t quantity = 0);
    void	store(const std::string &name, size_t quantity);
    bool	take(const std::string &name, size_t quantity);

    void	setMax(const std::string &name, size_t max);
    size_t	getMax(const std::string &name) const;

    size_t	getQuantity(const std::string &name) const;
    bool	haveStock(const std::string &name) const;


    void	update();
    std::string	serialize();
    Store    *unserialize(std::stringstream &s, GameObject *owner);
    Store    *clone(GameObject *owner) const;
  };
}

#endif /* !__STORE_H__ */
