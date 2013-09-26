//
// Trame.cpp for /home/vink/projet/cpp/bomberman/src/Daemon/Core/Trame/Trame.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Thu May  9 23:01:03 2013 vink
// Last update Sat Jun  8 19:42:18 2013 kevin platel
//

#include <string.h>
#include <iostream>
#include <sstream>
#include "utils.hh"
#include "Trame.hh"

Daemon::Trame::Trame(const std::string &msg)
{
  this->exec = true;
  this->init(msg);
}

Daemon::Trame::Trame(int id,
                    const std::string &event,
                    const std::string &type,
                    const std::string &targ_type,
                    const std::string & targ_id,
                    const std::string &arg)
{
  this->init(id, event, type, targ_type, targ_id, arg);
}

Daemon::Trame::~Trame()
{
}

std::string        Daemon::Trame::getData(std::stringstream &ss)
{
  size_t size = 0;

  ss >> size;
  if (!ss && (ss.str()).size() < size)
    return ("");
  ss.get();
  char buff[size+1];
  bzero(buff, size+1);
  ss.read(buff, size);

  buff[size] = 0;
  ss.get();
  if (buff[0] == 0)
    return ("");
  return (std::string(buff));
}

void        Daemon::Trame::recupId(std::stringstream & ss)
{
  this->_id = str_to_int(this->getData(ss));
}

void        Daemon::Trame::recupEvent(std::stringstream &ss)
{
  this->_event = this->getData(ss);
}

void        Daemon::Trame::recupType(std::stringstream &ss)
{
  this->_type = this->getData(ss);
}

void        Daemon::Trame::recupTargetType(std::stringstream &ss)
{
  this->_targ_type = this->getData(ss);
}

void        Daemon::Trame::recupTargetId(std::stringstream &ss)
{
  this->_targ_id = this->getData(ss);
}

void        Daemon::Trame::recupArgument(std::stringstream &ss)
{
  this->_arg = this->getData(ss);
}

void        Daemon::Trame::init(const std::string &msg)
{
  std::stringstream ss;

  this->_arg = "";
  this->_event = "";
  this->_targ_id = "";
  this->_targ_type = "";
  this->_type = "";
  this->_id = -1;
  if (msg.size() > 0)
  {
    ss << msg;
    if (ss)
      this->recupId(ss);
    if (ss)
      this->recupEvent(ss);
    if (ss)
      this->recupType(ss);
    if (ss)
      this->recupTargetType(ss);
    if (ss)
      this->recupTargetId(ss);
    if (ss)
      this->recupArgument(ss);
  }
}

void        Daemon::Trame::init(int id, const std::string &event, const std::string &type,
  const std::string &targ_type, const std::string & targ_id, const std::string &arg)
{
  this->_id = id;
  this->_event = event;
  this->_type = type;
  this->_targ_type = targ_type;
  this->_targ_id = targ_id;
  this->_arg = arg;
}

std::string	Daemon::Trame::getArgument() const
{
  return this->_arg;
}

std::string			Daemon::Trame::getEvent() const
{
  return this->_event;
}

int				Daemon::Trame::getId() const
{
  return this->_id;
}

std::vector<std::string>		Daemon::Trame::getTargetId() const
{
  return split_string(this->_targ_id, "|");
}

std::vector<std::string>			Daemon::Trame::getTargetType() const
{
  return split_string(this->_targ_type, "|");
}

std::string			Daemon::Trame::getType() const
{
  return this->_type;
}

void    Daemon::Trame::setArgument(std::string v)
{
  this->_arg = v;
}

void    Daemon::Trame::setEvent(const std::string &e)
{
  this->_event = e;
}

void    Daemon::Trame::setId(int id)
{
  this->_id = id;
}

void    Daemon::Trame::setTargetId(std::string v)
{
  this->_targ_id = v;
}

void    Daemon::Trame::setTargetType(std::string v)
{
  this->_targ_type = v;
}

void    Daemon::Trame::setType(const std::string &type)
{
  this->_type = type;
}

void          Daemon::Trame::transformData(std::stringstream & ss, const std::string &s) const
{
  ss << (s).size();
  ss << ":";
  ss << s;
}

void          Daemon::Trame::transformData(std::stringstream & ss, int i) const
{
  ss << (int_to_str(i).size());
  ss << ":";
  ss << i;
}

std::string   Daemon::Trame::toString() const
{
  std::stringstream ss("");

  this->transformData(ss, this->getId());
  ss << ";";
  this->transformData(ss, this->getEvent());
  ss << ";";
  this->transformData(ss, this->getType());
  ss << ";";
  this->transformData(ss, this->_targ_type);
  ss << ";";
  this->transformData(ss, this->_targ_id);
  ss << ";";
  this->transformData(ss, this->getArgument());
  ss << "\r\n";
  return ss.str();
}
