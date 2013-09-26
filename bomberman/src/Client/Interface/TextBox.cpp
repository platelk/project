//
// TextBox.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Thu May 30 15:15:20 2013 alexis leprovost
// Last update Sun Jun  9 02:18:32 2013 alexis leprovost
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Client/Event/KeyboardEvent.hh"
#include "Client/Interface/TextBox.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/TextManager.hh"

namespace Client
{
  TextBox::Manual	TextBox::manual;

  TextBox::TextBox(std::string const& normal, std::string const& select,
		   std::string const& text, size_t size, size_t sizeMax,
		   Color const& color, bool isSelect)
    : Button(normal, select, isSelect),
      _text(Text(text, size, color)),
      _isLock(false),
      _sizeMax(sizeMax),
      _toDraw(true)
  {
    this->setName(Interface::TEXT_BOX);
    if (TextBox::manual.empty())
      {
	char	c;
	int	i;
	c = 64;
	for (i = 0; i < 26; ++i)
	  TextBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	c = 47;
	for (i = 75; i < 85; ++i)
	  TextBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	c = 47;
	for (i = 26; i < 36; ++i)
	  TextBox::manual[static_cast<Input::Keys::Key>(i)] = ++c;
	TextBox::manual[Input::Keys::Space] = ' ';
	TextBox::manual[Input::Keys::Add] = '+';
	TextBox::manual[Input::Keys::Subtract] = '-';
	TextBox::manual[Input::Keys::Multiply] = '*';
	TextBox::manual[Input::Keys::Divide] = '/';
      }
  }

  TextBox::~TextBox()
  {

  }

  void	TextBox::setColorText(float red, float green, float blue)
  {
    this->_text.setColor(red, green, blue);
  }

  void	TextBox::setSizeText(size_t size)
  {
    this->_text.setSize(size);
  }

  void	TextBox::setText(std::string const& text)
  {
    if (!text.empty())
      this->_text.setText("");
    else
      this->_text.setText(text.substr(0, this->_sizeMax));
  }

  void	TextBox::setPositionText(int x, int y, int z)
  {
    this->_text.setPosition(x, y, z);
  }

  void	TextBox::setSizeMax(size_t sizeMax)
  {
    this->_sizeMax = sizeMax;
  }

  size_t	TextBox::getSizeText() const
  {
    return (this->_text.getSize());
  }

  size_t	TextBox::getSizeMax() const
  {
    return (this->_sizeMax);
  }

  std::string const&	TextBox::getText() const
  {
    return (this->_text.getText());
  }

  void	TextBox::addChar(Input::Keys::Key c)
  {
    if (this->_isSelect)
      {
	std::string	text = this->_text.getText();
	if (c == Input::Keys::Back)
	  this->_text.setText(text.empty() ? "" : text.substr(0, (text.size() - 1)));
	else
	  {
	    if (TextBox::manual.find(c) != TextBox::manual.end() &&
		this->_text.getText().size() < this->_sizeMax)
	      this->_text.setText(text + TextBox::manual[c]);
	  }
      }
  }

  void	TextBox::lock(bool isLock)
  {
    this->_isLock = isLock;
    this->_clign.reset();
  }

  bool	TextBox::isLock() const
  {
    return (this->_isLock);
  }

  void	TextBox::initialize()
  {
    this->_normal.initialize();
    this->_select.initialize();
    this->_text.initialize();
    this->_clock.reset();
    this->_clock.start();
    this->_text.setText("");
    this->_isLock = false;
    this->_clign.reset();
  }

  void	TextBox::update(Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);

    this->_normal.update(event);
    this->_select.update(event);
    this->_text.update(event);
    if (this->_isSelect &&
	keyboardEvent &&
	(!this->_clock.isRunning() || this->_clock.isTimeOut(0.1f)))
      {
	this->_clock.reset();
	this->_clock.start();
	if (keyboardEvent->getKeyCode() == Input::Keys::Enter)
	  this->lock(!this->_isLock);
	else
	  this->addChar(static_cast<Input::Keys::Key>(keyboardEvent->getKeyCode()));
      }
  }

  size_t	TextBox::getLink(ButtonManager::Sens sens) const
  {
    if (!this->_isLock)
      return (Button::getLink(sens));
    return (-1);
  }

  void	TextBox::draw()
  {
    try
      {
	if (this->_isSelect)
	  this->_select.draw();
	else
	  this->_normal.draw();
	this->_text.draw();
	if (this->_isLock)
	  {
	    if (this->_toDraw)
	      {
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(this->_text.getX() + static_cast<int>(this->_text.getText().size() * this->_text.getSize()), this->_text.getY(), this->_text.getZ());
		static_cast<gdl::Image>(Text::manager.get(127)).bind();
		glColor3f(this->_text.getColor().red, this->_text.getColor().green, this->_text.getColor().blue);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0f, this->_text.getSize(), 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(this->_text.getSize(), 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(this->_text.getSize(), this->_text.getSize(), 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glEnd();
		glPopMatrix();
	      }
	    if (!this->_clign.isRunning())
	      this->_clign.start();
	    else
	      if (this->_clign.isTimeOut(0.5f))
		{
		  this->_toDraw = !this->_toDraw;
		  this->_clign.reset();
		  this->_clign.start();
		}
	  }
      }
    catch (TextManager::Error e)
      {
	std::cout << e.what() << std::endl;
      }
  }

  void	TextBox::unload()
  {
    this->_normal.unload();
    this->_select.unload();
    this->_text.unload();
  }
}
