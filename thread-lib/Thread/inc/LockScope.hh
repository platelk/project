#ifndef __LOCKSCOPE_H__
# define __LOCKSCOPE_H__

#include "Mutex.hh"

class LockScope
{
  Mutex &_mutex;
public:
  LockScope(Mutex &);
  virtual ~LockScope();
};

#endif /* !__LOCKSCOPE_H__ */
