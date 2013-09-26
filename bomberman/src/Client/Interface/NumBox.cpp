//
// NumBox.cpp for /home/phalip_z/bomberman/src/Client/Interface/NumBox.cpp in /home/phalip_z//bomberman/src/Client/Interface
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Fri Jun  7 20:13:37 2013 phalip_z
// Last update Sun Jun  9 10:04:50 2013 alexis leprovost
//

#include "Client/Interface/NumBox.hh"
#include "Client/Interface/Interface.hh"

namespace Client
{
  NumBox::Manual	NumBox::manual;

  NumBox::NumBox(std::string const& normal, std::string const& select,
	 std::string const& text, size_t size,
	 Color const& color, bool isSelect)
    : KeyBox(normal, select, text, size, color, isSelect)
  {
    this->_keycode = 0;
    this->_isLock = false;
    this->_toUnlock = false;
    this->setName(Interface::NUM_BOX);
    if (NumBox::manual.empty())
      {
	char	c;
	int	i;
	c = 47;
	for (i = 76; i < 85; ++i)
	  NumBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	c = 47;
	for (i = 27; i < 36; ++i)
	  NumBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
      }
  }

  NumBox::~NumBox()
  {
  }

  void	NumBox::addChar(Input::Keys::Key c)
  {
    if (this->_isLock)
      {
	std::string	text = this->_text.getText();
	if (c == Input::Keys::Back)
	  this->_text.setText(text.empty() ? "" : text.substr(0, (text.size() - 1)));
	else
	  {
	    if (NumBox::manual.find(c) != NumBox::manual.end() &&
		this->_text.getText().size() < this->_sizeMax)
	      {
		this->_text.setText(text + NumBox::manual[c]);
		this->_keycode = c;
	      }
	  }
      }
  }
}
