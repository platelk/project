//
// Factory.hh for design_pattern in /home/leprov_a//lib/c++/design_pattern
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Tue Apr 16 16:02:07 2013 alexis leprovost
// Last update Tue Apr 16 17:43:55 2013 alexis leprovost
//

#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>
#include <map>

template <typename T, typename U = std::string>
class Factory
{
protected:
  std::map<U, T>	_man;
public:
  Factory()
  {
    this->_man = std::map<U, T>();
  }

  virtual ~Factory() {}

  virtual void	learn(U const& key, T object)
  {
    if (this->_man.find(key) == this->_man.end())
      this->_man[key] = object;
  }

  virtual void	forget(U const& key)
  {
    if (this->_man.find(key) != this->_man.end())
      this->_man.erase(key);
  }

  virtual T	create(U const& key) const
  {
    typename std::map<U, T>::const_iterator it = this->_man.find(key);

    if (it != this->_man.end())
      return (((*it).second)->clone());
    return (0);
  }
};

#endif /* _FACTORY_H_ */
