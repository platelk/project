//
// IPrototype.hpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/DesignPattern
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Mon May 13 11:00:46 2013 alexis leprovost
// Last update Mon May 13 11:01:45 2013 alexis leprovost
//

#ifndef _IPROTOTYPE_H_
#define _IPROTOTYPE_H_

template <typename T>
class IPrototype
{
public:
  virtual ~IPrototype() {}
  virtual T	clone() const = 0;
};

#endif /* _IPROTOTYPE_H_ */
