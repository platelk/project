//
// TextBox.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Thu May 30 15:16:35 2013 alexis leprovost
// Last update Wed Jun  5 12:26:31 2013 alexis leprovost
//

#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include <map>

#include "Color.hh"
#include "Timer.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/ButtonManager.hh"
#include "Client/Interface/Image.hh"
#include "Client/Interface/Text.hh"
#include "Client/Controller/Input.hh"
#include "Client/Event/Event.hh"

namespace Client
{
  class TextBox : public Button
  {
  public:
    typedef std::map<Input::Keys::Key, char>	Manual;
  protected:
    Text	_text;
    bool	_isLock;
    size_t	_sizeMax;
    bool	_toDraw;
    Timer	_clign;
    Timer	_clock;
  public:
    TextBox(std::string const& normal, std::string const& select,
	    std::string const& text = "", size_t size = 14, size_t sizeMax = -1,
	    Color const& color = Color(0.0f, 0.0f, 0.0f), bool isSelect = false);
    virtual ~TextBox();

    void	setSizeText(size_t size);
    void	setText(std::string const& text);
    void	setColorText(float red, float green, float blue);
    void	setPositionText(int x, int y, int z);
    void	setSizeMax(size_t sizeMax);

    void	lock(bool isLock);
    bool	isLock() const;

    size_t		getSizeText() const;
    std::string const&	getText() const;
    size_t		getSizeMax() const;

    void	addChar(Input::Keys::Key c);

    virtual size_t	getLink(ButtonManager::Sens sens) const;

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();

    static Manual	manual;
  };
}

#endif /* _TEXTBOX_H_ */
