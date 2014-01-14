#ifndef __OPERAND_H__
# define __OPERAND_H__

#include <sstream>
#include "IOperand.hh"
#include "Memory.hh"

template<class T>
class Operand : public IOperand
{
private:
  eOperandType	_type;
  const T		_value;

  T		getValueOfType(std::string const & string_value) const
  {
    std::stringstream	ss;
    T tmp;

    ss << string_value;
    ss >> tmp;

    return (tmp);
  }
public:
  Operand(eOperandType type, T const value)
    : _type(type), _value(value)
  {
  }
  Operand(eOperandType type, std::string const & value)
    : _type(type), _value(this->getValueOfType(value))
  {
  }
  virtual ~Operand() {}

  int		getPrecision() const
  {
    return (this->_type);
  }

  eOperandType	getType() const
  {
    return (this->_type);
  }

  std::string	toString() const
  {
    std::stringstream ss;

    ss << this->_value;
    return (ss.str());
  }

  IOperand*	operator+(const IOperand *op) const
  {
    T op_value;

    op_value = this->getValueOfType((op->toString()));
    return (new Operand<T>(this->_type, this->_value + op_value));
  }

  IOperand*	operator-(const IOperand *op) const
  {
    T op_value;

    op_value = this->getValueOfType(op->toString());
    return (new Operand<T>(this->_type, this->_value - op_value));
  }

  IOperand*	operator*(const IOperand *op) const
  {
    T op_value;

    op_value = this->getValueOfType(op->toString());
    return (new Operand<T>(this->_type, this->_value * op_value));
  }

  IOperand*	operator/(const IOperand *op) const
  {
    T op_value;

    op_value = this->getValueOfType(op->toString());
    return (new Operand<T>(this->_type, this->_value / op_value));
  }

  IOperand*	operator%(const IOperand *op) const;
};


template<typename T>
IOperand*	Operand<T>::operator%(const IOperand *op) const
{
  T op_value;

  op_value = this->getValueOfType(op->toString());
  return (new Operand<T>(this->_type, this->_value % op_value));
}


template<>
IOperand*	Operand<double>::operator%(const IOperand *) const
{
  return 0;
}

template<>
IOperand*	Operand<float>::operator%(const IOperand *) const
{
  return 0;
}

template<>
char		Operand<char>::getValueOfType(std::string const & string_value) const
{
  std::stringstream	ss;
  int tmp;

  ss << string_value;
  ss >> tmp;

  return (static_cast<char>(tmp));
}

template<>
std::string	Operand<char>::toString() const
{
  std::stringstream ss;

  ss << static_cast<int>(this->_value);
  return (ss.str());
}

#endif /* !__OPERAND_H__ */
