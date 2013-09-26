//
// Timer.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Tool
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Tue May 14 13:28:20 2013 alexis leprovost
// Last update Mon May 20 13:47:25 2013 alexis leprovost
//

#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#include "Timer.hh"

#define ABS(v)	((v) < 0 ? ((v) * (-1)) : (v))

Timer::Timer()
  : _begin(), _end(), _run(false), _stop(false)
{

}

Timer::Time::Time()
  : sec(0), usec(0)
{

}

Timer::~Timer()
{

}

Timer::Time::Time(int const& sec, int const& usec)
{
  this->sec = sec;
  this->usec = usec;
}

Timer::Time	operator-(Timer::Time const& t1, Timer::Time const& t2)
{
  Timer::Time	t(ABS(t1.sec - t2.sec), t1.usec - t2.usec);

  if (t.usec < 0)
    {
      --t.sec;
      t.usec = 1000000 + t.usec;
    }
  return (t);
}

Timer::Time::~Time()
{

}

void	Timer::start()
{
  if (!this->isRunning())
    {
      if (this->isStopped())
	{
	  this->_begin = this->clock() - (this->_end - this->_begin);
	  this->_stop = false;
	}
      else
	this->_begin = this->clock();
      this->_run = true;
    }
}

double		Timer::getTime() const
{
  Timer::Time	time = this->clock() - this->_begin;

  return (static_cast<double>(time.sec) + (static_cast<double>(time.usec) / 1000000));
}

Timer::Time	Timer::clock() const
{
  struct timeval time;

  gettimeofday(&time, NULL);
  return (Timer::Time(time.tv_sec, time.tv_usec));
}

void	Timer::stop()
{
  if (this->isRunning())
    {
      this->_stop = true;
      this->_run = false;
      this->_end = this->clock();
    }
}

void	Timer::reset()
{
  this->_begin = Timer::Time(0, 0);
  this->_end = Timer::Time(0, 0);
  this->_run = false;
  this->_stop = false;
}

 bool	Timer::isRunning() const
{
  return (this->_run);
}

bool	Timer::isStopped() const
{
  return (this->_stop);
}

bool	Timer::isTimeOut(double seconds) const
{
  Timer::Time	time;
  int const	sec = static_cast<int>(seconds);
  int const	usec = (seconds - static_cast<double>(sec)) * 1000000.0f;

  time = this->isRunning() ? (this->clock() - this->_begin) : (this->_end - this->_begin);
  return (time.sec > sec ? true : (time.sec == sec && time.usec > usec ? true : false));
}
