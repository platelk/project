#ifndef __THREADPOOL_H__
# define __THREADPOOL_H__

#include "Thread.hpp"

class ThreadPool
{
private:

public:
  ThreadPool(size_t size = 0);
  virtual ~ThreadPool();
};

#endif /* !__THREADPOOL_H__ */
