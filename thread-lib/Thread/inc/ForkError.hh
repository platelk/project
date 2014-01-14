#ifndef __FORKERROR_H__
# define __FORKERROR_H__

#include <iostream>
#include <exception>

#include "ASubProcessError.hh"

class ForkError : public ASubProcessError
{
public:
  ForkError(std::string const &msg)
  {
    this->msg = msg;
  }
  virtual ~ForkError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ForkCreateError : public ASubProcessCreateError
{
public:
  ForkCreateError(std::string const &msg)
    : ASubProcessCreateError(msg)
  {
    this->msg = msg;
  }
  virtual ~ForkCreateError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ForkJoinError : public ASubProcessJoinError
{
public:
  ForkJoinError(std::string const &msg)
    : ASubProcessJoinError(msg)
  {
    this->msg = msg;
  }
  virtual ~ForkJoinError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ForkStopError : public ASubProcessStopError
{
public:
  ForkStopError(std::string const &msg)
    : ASubProcessStopError(msg)
  {
    this->msg = msg;
  }
  virtual ~ForkStopError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

class ForkRunError : public ASubProcessRunError
{
public:
  ForkRunError(std::string const &msg)
    : ASubProcessRunError(msg)
  {
    this->msg = msg;
  }
  virtual ~ForkRunError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

#endif /* !__FORKERROR_H__ */
