#ifndef __THREAD_H__
# define __THREAD_H__

#include <iostream>

#include "ASubProcess.hh"
#include "ThreadError.hh"

// Pthread Include

#include <pthread.h>

// This class is an abstraction of pthread library of Unix
// Is an inheritence of ASubProcess
// who share this abstract class with Fork class

class Thread : public ASubProcess
{
public:
  typedef struct thread_info
  {
    time_t	*start;
    time_t	*end;
    double	*time;
    void		*param;
    void		*ret;
    thread_func	func;
    bool		*stop;
  } t_thread_info;
private:
  pthread_t	*_thread_id;
  t_thread_info *_thread_info;
public:

  // func  -> the function to call when you running the thread
  // param -> the param to send in the function
  // stat  -> if you want waitting the result of the thread or not

  Thread(thread_func func = 0, void *param = 0, ASubProcess::State stat = NONE_BLOCK);
  virtual ~Thread();

  void	stop();
  int	join();
  int	join(void **ret);
  int	run(thread_func func = 0, void *param = 0, State stat = NONE_BLOCK);
};

#endif /* !__THREAD_H__ */
