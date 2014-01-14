#ifndef __FORK_H__
# define __FORK_H__

#include <iostream>
#include "ASubProcess.hh"

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

class Fork : public ASubProcess
{
  pid_t	_pid;
public:
  Fork(thread_func func = 0, void *param = 0, ASubProcess::State stat = NONE_BLOCK);
  virtual ~Fork();

  void	stop();
  int	join();
  int	run(thread_func func = 0, void *param = 0, ASubProcess::State stat = NONE_BLOCK);
};

#endif /* !__FORK_H__ */
