//
// ChannelConsole.cpp
//
// Made by Guiho Ronan
//
// Started on  Wed May  8 17:57:41 2013 Guiho Ronan
//

#include <iostream>

#include "Logging/ChannelConsole.hh"

const std::string Logging::ChannelConsole::refPriority[] =
{
  "\033[1;31m",
  "\033[1;35m",
  "\033[1;31m",
  "\033[1;31m",
  "\033[1;33m",
  "\033[1;32m",
  "\033[1;37m",
  "\033[1;33m"
};

Logging::ChannelConsole::ChannelConsole()
  : _name("Console")
{
}

const std::string &Logging::ChannelConsole::getName() const
{
  return (this->_name);
}

bool Logging::ChannelConsole::isValid() const
{
  return (true);
}

void Logging::ChannelConsole::setName(const std::string &) const
{
}

void Logging::ChannelConsole::write(const Message &msg) const
{
  std::cout << Logging::ChannelConsole::refPriority[msg.getPriority()] <<
    msg.serialize() << "\033[0;40m";
}
