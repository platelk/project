//
// Memory.cpp for /home/vink/projet/cpp/abstract/src/Memory.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Tue Feb 12 10:24:50 2013 vink
// Last update Tue Feb 12 13:06:35 2013 vink
//

#include <iostream>
#include <algorithm>
#include "Memory.hh"
#include "Operand.hpp"

void	print(IOperand *a)
{
  std::cout << a->toString() << std::endl;
}

Memory::Memory()
{
  this->create[Int8] = &Memory::createInt8;
  this->create[Int16] = &Memory::createInt16;
  this->create[Int32] = &Memory::createInt32;
  this->create[Float] = &Memory::createFloat;
  this->create[Double] = &Memory::createDouble;
}

void	Memory::dump()
{
  std::for_each(this->mem.begin(), this->mem.end(), print);
}

IOperand*	Memory::get() const
{
  return (this->mem[0]);
}

IOperand*	Memory::pop()
{
  IOperand*	tmp;

  tmp = this->mem[0];
  this->mem.pop_front();
  return (tmp);
}

void		Memory::push(IOperand *a)
{
  this->mem.push_front(a);
}

IOperand*	Memory::createOperand(eOperandType type, std::string const & value)
{
  return ((this->*(this->create[type]))(value));
}

IOperand*	Memory::createDouble(const std::string &value)
{
  return (new Operand<double>(Double, value));
}

IOperand*	Memory::createFloat(const std::string &value)
{
  return (new Operand<float>(Float, value));
}

IOperand*	Memory::createInt32(const std::string &value)
{
  return (new Operand<int>(Int32, value));
}

IOperand*	Memory::createInt16(const std::string &value)
{
  return (new Operand<short>(Int16, value));
}

IOperand*	Memory::createInt8(const std::string &value)
{
  return (new Operand<char>(Int8, value));
}
