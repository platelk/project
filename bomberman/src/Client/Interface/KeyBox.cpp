//
// KeyBox.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed Jun  5 10:35:31 2013 alexis leprovost
// Last update Fri Jun  7 20:58:40 2013 phalip_z
//

#include "Client/Event/KeyboardEvent.hh"
#include "Client/Interface/KeyBox.hh"
#include "Client/Interface/Interface.hh"

namespace Client
{
  KeyBox::Manual	KeyBox::manual;

  KeyBox::KeyBox(std::string const& normal, std::string const& select,
		 std::string const& text, size_t size,
		 Color const& color, bool isSelect)
    : TextBox(normal, select, text, size, 1, color, isSelect)
  {
    this->_keycode = 0;
    this->_isLock = false;
    this->_toUnlock = false;
    this->setName(Interface::KEY_BOX);
    if (KeyBox::manual.empty())
      {
	char	c;
	int	i;
	c = 64;
	for (i = 0; i < 26; ++i)
	  KeyBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	c = 47;
	for (i = 75; i < 85; ++i)
	  KeyBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	c = 47;
	for (i = 26; i < 36; ++i)
	  KeyBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	KeyBox::manual[Input::Keys::Space] = ' ';
	KeyBox::manual[Input::Keys::Add] = '+';
	KeyBox::manual[Input::Keys::Subtract] = '-';
	KeyBox::manual[Input::Keys::Multiply] = '*';
	KeyBox::manual[Input::Keys::Divide] = '/';
	KeyBox::manual[Input::Keys::Period] = '.';
	KeyBox::manual[Input::Keys::Up] = 1;
	KeyBox::manual[Input::Keys::Down] = 2;
	KeyBox::manual[Input::Keys::Left] = 3;
	KeyBox::manual[Input::Keys::Right] = 4;
	KeyBox::manual[Input::Keys::Enter] = 5;
      }
  }

  KeyBox::~KeyBox()
  {

  }

  void	KeyBox::addChar(Input::Keys::Key c)
  {
    if (this->_isLock)
      {
	std::string	text = this->_text.getText();
	if (c == Input::Keys::Back)
	  this->_text.setText(text.empty() ? "" : text.substr(0, (text.size() - 1)));
	else
	  {
	    if (KeyBox::manual.find(c) != KeyBox::manual.end() &&
		this->_text.getText().size() < this->_sizeMax)
	      {
		this->_text.setText(text + KeyBox::manual[c]);
		this->_keycode = c;
	      }
	  }
      }
  }

  void	KeyBox::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);

    this->_normal.update(event);
    this->_select.update(event);
    this->_text.update(event);
    if (this->_toUnlock)
      {
	this->lock(false);
	this->_toUnlock = false;
      }
    if (this->_isSelect &&
	keyboardEvent &&
	(!this->_clock.isRunning() || this->_clock.isTimeOut(0.1f)))
      {
	this->_clock.reset();
	this->_clock.start();
	if (!this->_isLock && keyboardEvent->getKeyCode() == Input::Keys::Enter)
	  {
	    this->_text.setText("");
	    this->lock(!this->_isLock);
	  }
	else
	  if (this->_isLock && KeyBox::manual[static_cast<Input::Keys::Key>(keyboardEvent->getKeyCode())])
	    {
	      this->addChar(static_cast<Input::Keys::Key>(keyboardEvent->getKeyCode()));
	      this->_toUnlock = true;
	    }
      }
  }

  int	KeyBox::getLastKey() const
  {
    return (this->_keycode);
  }
}
