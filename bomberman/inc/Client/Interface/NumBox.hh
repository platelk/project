#ifndef __NUMBOX_H__
# define __NUMBOX_H__

#include	"Client/Interface/KeyBox.hh"

namespace Client
{
  class NumBox : public KeyBox
  {
  public:
    typedef std::map<Input::Keys::Key, char>	Manual;

    NumBox(std::string const& normal, std::string const& select,
	   std::string const& text = "", size_t size = 14,
	   Color const& color = Color(0.0f, 0.0f, 0.0f), bool isSelect = false);
    virtual ~NumBox();

    virtual void	addChar(Input::Keys::Key c);

    static Manual	manual;
  };
}

#endif /* !__NUMBOX_H__ */
