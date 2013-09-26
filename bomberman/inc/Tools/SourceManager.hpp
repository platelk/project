//
// SourceManager.hpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sat Jun  8 19:13:03 2013 alexis leprovost
// Last update Sun Jun  9 05:11:10 2013 alexis leprovost
//

#ifndef _SOURCEMANAGER_H_
#define _SOURCEMANAGER_H_

#include <utility>
#include <map>
#include <exception>
#include <cstdlib>
#include <iostream>

#include "Image.hpp"
#include "Model.hpp"

template <typename T>
class SourceManager
{
public:
  typedef std::map<std::string, std::pair<bool, T> >	Manual;
protected:
  Manual	_manual;
public:
  class Error : public std::exception
  {
  private:
    std::string	_what;
  public:
    Error(std::string const& what) throw() : _what(what) {}
    virtual ~Error() throw() {}

    const char*	what() const throw()
    {
      return (this->_what.c_str());
    }
  };
  SourceManager() {}
  virtual ~SourceManager() {}

  virtual bool	learn(std::string const& name)
  {
    if (this->_manual.find(name) != this->_manual.end())
      return (false);
    this->_manual[name] = std::pair<bool, T>(false, T());
    return (true);
  }

  virtual bool	forget(std::string const& name)
  {
    typename Manual::iterator	it = this->_manual.find(name);

    if (it == this->_manual.end())
      return (false);
    this->_manual.erase(it);
    return (true);
  }

  virtual bool	random()
  {
    typename Manual::iterator		it = this->_manual.begin();
    std::vector<std::string>	random;

    for (; it != this->_manual.end(); ++it)
      if (!(*it).second.first)
	random.push_back((*it).first);
    if (random.empty())
      return (false);
    return (this->init(random[rand() % random.size()]));
  }

  virtual T&	get(std::string const& name) = 0;
  virtual bool		init(std::string const& name) = 0;
};

class ImageManager : public SourceManager<gdl::Image>
{
public:
  ImageManager() {}
  virtual ~ImageManager() {}

  virtual gdl::Image&	get(std::string const& name)
  {
    typename Manual::iterator	it = this->_manual.find(name);

    if (it ==  this->_manual.end())
      throw SourceManager<gdl::Image>::Error("Image '" + name  + "' not found");
    if (!(*it).second.first)
      {
	(*it).second.second = gdl::Image::load(name);
	(*it).second.first = true;
      }
    return ((*it).second.second);
  }

  virtual bool		init(std::string const& name)
  {
    typename Manual::iterator	it = this->_manual.find(name);

    if (it == this->_manual.end() || (*it).second.first)
      return (false);
    (*it).second.second = gdl::Image::load(name);
    (*it).second.first = true;
    return (true);
  }
};

class ModelManager : public SourceManager<gdl::Model>
{
public:
  ModelManager() {}
  virtual ~ModelManager() {}

  virtual gdl::Model&	get(std::string const& name)
  {
    typename Manual::iterator	it = this->_manual.find(name);

    if (it ==  this->_manual.end())
      throw SourceManager<gdl::Model>::Error("Model '" + name  + "' not found");
    if (!(*it).second.first)
      {
	(*it).second.second = gdl::Model::load(name);
	(*it).second.first = true;
      }
    return ((*it).second.second);
  }

  virtual bool		init(std::string const& name)
  {
    typename Manual::iterator	it = this->_manual.find(name);

    if (it == this->_manual.end() || (*it).second.first)
      return (false);
    (*it).second.second = gdl::Model::load(name);
    (*it).second.first = true;
    return (true);
  }
};

#endif /* _SOURCEMANAGER_H_ */
