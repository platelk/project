#ifndef __ISUBPROCESSPOOL_H__
# define __ISUBPROCESSPOOL_H__

#include <iostream>
#include "ASubProcess.hh"

class ISubProcessPool
{
public:
  virtual ~ISubProcessPool() {};

  virtual void	pushTask() = 0;
  virtual
};

#endif /* !__ISUBPROCESSPOOL_H__ */
