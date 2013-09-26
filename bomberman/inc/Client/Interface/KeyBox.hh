//
// KeyBox.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed Jun  5 10:43:28 2013 alexis leprovost
// Last update Fri Jun  7 20:40:55 2013 phalip_z
//

#ifndef _KEYBOX_H_
#define _KEYBOX_H_

#include <map>

#include "Color.hh"
#include "Client/Controller/Input.hh"
#include "Client/Interface/TextBox.hh"

namespace Client
{
  class KeyBox : public TextBox
  {
  protected:
    int		_keycode;
    bool	_toUnlock;
  public:
    typedef std::map<Input::Keys::Key, char>	Manual;
    KeyBox(std::string const& normal, std::string const& select,
	   std::string const& text = "", size_t size = 14,
	   Color const& color = Color(0.0f, 0.0f, 0.0f), bool isSelect = false);
    virtual ~KeyBox();

    int				getLastKey() const;
    virtual void		addChar(Input::Keys::Key c);
    void			update(Event* event);

    static Manual	manual;

  };
}

#endif /* _KEYBOX_H_ */
