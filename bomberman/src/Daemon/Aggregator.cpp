//
// Aggregator.cpp for Aggregator in /home/guiho_r/depot/bomberman/inc/Daemon
//
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
//
// Started on  Sun May 26 11:15:28 2013 ronan guiho
// Last update Sat Jun  8 01:59:23 2013 ronan guiho
//

#include <string>

#include "Aggregator.hh"
#include "utils.hh"

Aggregator::Aggregator(const std::string &sep)
  : _sep(sep)
{
}

void Aggregator::push(const std::string &msg)
{
  this->_queue.push_back(msg);
}

bool Aggregator::checksum(std::string &msg)
{
  size_t pos;
  std::string all;
  std::vector<std::string> array;
  std::vector<std::string>::iterator it;

  while (!this->isEmpty())
    {
      msg = this->_queue.front();
      this->_queue.pop_front();
      if ((pos = msg.find(this->_sep)) != std::string::npos)
	{
	  if (pos == (msg.size() - this->_sep.size()))
	    {
	      msg = all + msg;
	      return (true);
	    }
	  else
	    {
	      array = split_string(msg, this->_sep);
	      if (array.size() >= 2)
		{
		  std::string sub = msg.substr(pos + this->_sep.size());
		  msg = (array[0] + this->_sep);
		  msg = all + msg;
		  this->_queue.push_front(sub);
		  return (true);
		}
	    }
	}
      else
	all += msg;
    }
  this->_queue.push_front(all);
  return (false);
}

bool Aggregator::isEmpty() const
{
  return (this->_queue.empty());
}
