//
// TextManager.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 29 20:09:29 2013 alexis leprovost
// Last update Wed May 29 21:12:38 2013 alexis leprovost
//

#include "utils.hh"
#include "Client/Interface/TextManager.hh"

namespace Client
{
  TextManager::TextManager()
  {

  }

  TextManager::~TextManager()
  {

  }

  void	TextManager::add(int letter)
  {
    this->_manual[letter] = gdl::Image::load("assets/clips/text/" +	\
					     int_to_str(letter) +	\
					     ".png");
  }

  void	TextManager::del(int letter)
  {
    Manual::iterator	it = this->_manual.find(letter);

    if (it != this->_manual.end())
      this->_manual.erase(it);
  }

  gdl::Image const&	TextManager::get(int letter) const
  {
    Manual::const_iterator	it = this->_manual.find(letter);

    if (it == this->_manual.end())
      throw TextManager::Error("Character '" + int_to_str(letter) + "' not found");
    return ((*it).second);
  }

  TextManager::Error::Error(std::string const& message) throw()
    : _message(message.c_str())
  {

  }

  TextManager::Error::~Error() throw()
  {

  }

  const char*	TextManager::Error::what() throw()
  {
    return (this->_message);
  }
}
