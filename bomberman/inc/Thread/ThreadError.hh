#ifndef __THREADERROR_H__
# define __THREADERROR_H__

#include <iostream>
#include <exception>

#include "ASubProcessError.hh"

class PthreadError : public ASubProcessError
{
public:
  PthreadError(std::string const &msg)
  {
    this->msg = msg;
  }
  virtual ~PthreadError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ThreadCreateError : public ASubProcessCreateError
{
public:
  ThreadCreateError(std::string const &msg)
    : ASubProcessCreateError(msg)
  {
    this->msg = msg;
  }
  virtual ~ThreadCreateError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ThreadJoinError : public ASubProcessJoinError
{
public:
  ThreadJoinError(std::string const &msg)
    : ASubProcessJoinError(msg)
  {
    this->msg = msg;
  }
  virtual ~ThreadJoinError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ThreadStopError : public ASubProcessStopError
{
public:
  ThreadStopError(std::string const &msg)
    : ASubProcessStopError(msg)
  {
    this->msg = msg;
  }
  virtual ~ThreadStopError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ThreadRunError : public ASubProcessRunError
{
public:
  ThreadRunError(std::string const &msg)
    : ASubProcessRunError(msg)
  {
    this->msg = msg;
  }
  virtual ~ThreadRunError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

#endif /* !__THREADERROR_H__ */
