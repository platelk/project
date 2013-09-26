#ifndef __WOODBOX_H__
# define __WOODBOX_H__

#include "Decor.hh"

class WoodBox : public Decor
{
public:
  static const std::string	NAME;

  WoodBox(Listener *parent = 0, int life = 1
, int x = 0, int y = 0, int z = 0);
  virtual ~WoodBox();
};

#endif /* !__WOODBOX_H__ */
