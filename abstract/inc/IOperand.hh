#ifndef __IOPERAND_H__
# define __IOPERAND_H__

#include <iostream>

enum eOperandType
  {
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
  };

class IOperand
{
public:
  virtual ~IOperand() {};
  virtual int	getPrecision() const = 0;
  virtual eOperandType	getType() const = 0;
  virtual std::string	toString() const = 0;

  virtual IOperand*	operator+(const IOperand *op) const = 0;
  virtual IOperand*	operator-(const IOperand *op) const = 0;
  virtual IOperand*	operator*(const IOperand *op) const = 0;
  virtual IOperand*	operator/(const IOperand *op) const = 0;
  virtual IOperand*	operator%(const IOperand *op) const = 0;
};

#endif /* !__IOPERAND_H__ */
