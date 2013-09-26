//
// Prototype.hh for design pattern in /home/leprov_a//lib/c++/design_pattern
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Tue Apr 16 12:23:46 2013 alexis leprovost
// Last update Tue Apr 16 17:17:00 2013 alexis leprovost
//

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

template <typename T>
class Prototype
{
public:
  virtual ~Prototype() {}
  virtual T	clone() const = 0;
};

#endif /* _PROTOTYPE_H_ */
