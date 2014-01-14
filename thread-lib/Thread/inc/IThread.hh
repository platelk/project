#ifndef __ITHREAD_H__
# define __ITHREAD_H__

class IThread
{
public:
  virtual ~IThread() {};

  virtual void	stop() = 0;
  virtual int	join() = 0;
  virtual int	run() = 0;
};

#endif /* !__ITHREAD_H__ */
