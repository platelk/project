//
// Aggregator.hh for Aggregator in /home/guiho_r/depot/bomberman/inc/Daemon
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Sun May 26 11:10:11 2013 ronan guiho
// Last update Mon May 27 10:33:12 2013 ronan guiho
//

#ifndef __AGGREGATOR_HH__
#define __AGGREGATOR_HH__

#include <list>
#include <string>

class Aggregator
{
private:
  std::string _sep;
  std::list<std::string> _queue;
public:
  Aggregator(const std::string &sep);
  void push(const std::string &msg);
  bool checksum(std::string &msg);
  bool isEmpty() const;
};

#endif
