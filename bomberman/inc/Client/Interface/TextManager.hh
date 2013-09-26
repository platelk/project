//
// TextManager.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 20:10:20 2013 alexis leprovost
// Last update Wed May 29 21:13:40 2013 alexis leprovost
//

#ifndef _TEXTMANAGER_H_
#define _TEXTMANAGER_H_

#include <utility>
#include <map>

#include "Image.hpp"

namespace Client
{
  class TextManager
  {
  public:
    typedef std::map<int, gdl::Image>	Manual;
    class Error
    {
    private:
      const char*	_message;
    public:
      Error(std::string const& message) throw();
      virtual ~Error() throw();

      const char*	what() throw();
    };
  private:
    Manual	_manual;
  public:
    TextManager();
    virtual ~TextManager();

    void		add(int letter);
    void		del(int letter);
    gdl::Image const&	get(int letter) const;
  };
}

#endif /* _TEXTMANAGER_H_ */
