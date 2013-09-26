#ifndef __FORK_H__
# define __FORK_H__

#include <iostream>
#include "ASubProcess.hpp"
#include "ForkError.hh"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



template<typename P = int, typename R = int>
class Fork : public ASubProcess<P, R>
{
private:
  pid_t	_id;
public:
  Fork(typename ASubProcess<P, R>::thread_func func = 0,
	 P param = 0,
	 typename ASubProcess<P, R>::State stat = ASubProcess<P, R>::NONE_BLOCK)
    : ASubProcess<P, R>(func, param, stat), _id(-1)
  {
  }

  virtual ~Fork()
  {
    if (this->_id >= 0)
      kill(this->_id, SIGKILL);
  }

  void	stop()
  {
    if (this->_id >= 0)
      {
	if (kill(this->_id, SIGKILL) < 0)
	  throw ForkStopError("Cannot kill the subproccess.\n");
      }
    else
      throw ForkStopError("Stop on a not running fork.\n");
  }

  int	join()
  {
    int	status;

    if (this->_id >= 0)
      waitpid(this->_id, &status, 0);
    else
      throw ForkJoinError("Join on a not running fork.\n");
    return (status);
  }

  int	run()
  {
    if (this->_func)
      {
	if ((this->_id = fork()) == 0)
	  {
	    this->_func(this->_param);
	    exit(-1);
	  }
	else if (this->_id < 0)
	  throw ForkRunError("Cannot fork.\n");
      }
    else
      throw ForkRunError("Invalid run function.\n");

    if (this->_state == ASubProcess<P, R>::BLOCK)
      this->join();
    return 0;
  }

  int	run(P param,
	    typename ASubProcess<P, R>::thread_func func = 0,
	    typename ASubProcess<P, R>::State stat = ASubProcess<P, R>::NONE_BLOCK)
  {
    if (func)
      this->_func = func;
    this->_param = param;
    if (stat != this->_state)
      this->_state = stat;
    return this->run();
  }
};

#endif /* !__FORK_H__ */
