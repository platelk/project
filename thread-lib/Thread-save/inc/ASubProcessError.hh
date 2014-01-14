#ifndef __ASUBPROCESSERROR_H__
# define __ASUBPROCESSERROR_H__

#include <iostream>
#include <exception>

class ASubProcessError : std::exception
{
protected:
  std::string	       msg;
public:
  ASubProcessError(std::string const &msg = "SubProccess Exception.")
    : msg(msg)
  {
  }
  virtual ~ASubProcessError() throw() {};

  virtual const char	*what() const throw() = 0;
};

class ASubProcessCreateError : public ASubProcessError
{
public:
  ASubProcessCreateError(std::string const &msg)
  {
    this->msg = msg;
  }
  virtual ~ASubProcessCreateError() throw() {};

  virtual const char	*what() const throw() = 0;
};

class ASubProcessJoinError : public ASubProcessError
{
public:
  ASubProcessJoinError(std::string const &msg)
  {
    this->msg = msg;
  }
  virtual ~ASubProcessJoinError() throw() {};

  virtual const char	*what() const throw() = 0;
};

class ASubProcessStopError : public ASubProcessError
{
public:
  ASubProcessStopError(std::string const &msg)
  {
    this->msg = msg;
  }
  virtual ~ASubProcessStopError() throw() {};

  virtual const char	*what() const throw() = 0;
};

class ASubProcessRunError : public ASubProcessError
{
public:
  ASubProcessRunError(std::string const &msg)
  {
    this->msg = msg;
  }
  virtual ~ASubProcessRunError() throw() {};

  virtual const char	*what() const throw() = 0;
};


#endif /* !__ASUBPROCESSERROR_H__ */
