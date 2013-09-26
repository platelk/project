//
// Timer.hh for plazza in /home/leprov_a//project/tek2/nibbler/dev/src/Tool
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon Mar  4 18:32:42 2013 alexis leprovost
// Last update Tue Apr 16 17:32:38 2013 alexis leprovost
//

#ifndef _TIMER_H_
# define _TIMER_H_

class Timer
{
public:
  struct Time
  {
    Time(int const& sec, int const& usec);
    Time();
    ~Time();
    int sec;
    int usec;
  };
private:
  Time		_begin;
  Time		_end;
  bool		_run;
  bool		_stop;
public:
  Timer();
  ~Timer();
  void	start();
  void	stop();
  void	reset();
  bool	isRunning() const;
  bool	isStopped() const;
  bool	isTimeOut(double seconds) const;
  double	getTime() const;
  Timer::Time	clock() const;
};

Timer::Time	operator-(Timer::Time const& t1, Timer::Time const& t2);

#endif /* _TIMER_H_ */
