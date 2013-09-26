#include <algorithm>
#include "AComponent.hh"
#include "Characteristic.hh"
#include <cstring>

Daemon::AComponent::AComponent(const std::string &name, const std::string &family, GameObject *owner)
  : _name(name), _family(family), _owner(owner), _isInit(false)
{
}

Daemon::AComponent::~AComponent()
{
  while (this->_child.empty() == false)
    {
      delete this->_child.front();
      this->_child.pop_front();
    }
}

void	Daemon::AComponent::init()
{

}

std::string	Daemon::AComponent::getName() const
{
  return this->_name;
}

std::string	Daemon::AComponent::getFamily() const
{
  return this->_family;
}

void		Daemon::AComponent::setName(const std::string &name)
{
  this->_name = name;
}

void		Daemon::AComponent::setOwner(GameObject *owner)
{
  this->_owner = owner;
}

void		Daemon::AComponent::update()
{

}

Daemon::GameObject *	Daemon::AComponent::getOwner() const
{
  return this->_owner;
}

void			Daemon::AComponent::addChild(AComponent *child)
{
  this->_child.push_back(child);
}

void			Daemon::AComponent::removeChild(AComponent *child)
{
  std::deque<AComponent *>::iterator it;

  if ((it = find(this->_child.begin(), this->_child.end(), child)) != this->_child.end())
    {
      this->_child.erase(it);
    }
}

std::string		Daemon::AComponent::createData(const std::string &s)
{
  std::stringstream ss;

  ss << "s:";
  ss << s.size();
  ss << ":" << s << ";";
  return ss.str();
}

std::string		Daemon::AComponent::createData(int i)
{
  std::stringstream ss;

  ss << "i:";
  ss << int_to_str(i).size();
  ss << ":" << i << ";";
  return ss.str();
}

std::string		Daemon::AComponent::createData(double i)
{
  std::stringstream ss;

  ss << "d:";
  ss << double_to_str(i).size();
  ss << ":" << i << ";";
  return ss.str();
}

std::string		Daemon::AComponent::createPackage(const std::string &s)
{
  std::stringstream ss;

  ss << "CP:" << (this->getName()).size() << ":" << this->getName() << ":" << (s.size() + 2 - (s.size() == 0 ? 0 : 1)) << ":{" << s.substr(0, s.size()-1) << "}";
  return ss.str();
}

std::string	Daemon::AComponent::unPack(std::stringstream &ss)
{
  size_t	size;

  ss >> size;
  char	buff[size];
  bzero(buff, size);
  if (ss.get() == ':' && ss.get() == '{')
    {
      ss.read(buff, size-2);
      buff[size-1] = 0;
      if (ss.get() == '}')
	{
	  return buff;
	}
    }
  return "";
}

std::string		Daemon::AComponent::getData(const std::string &s)
{
  std::stringstream ss;

  if (s == "")
    return "";
  ss << s;
  char	buff[2];
  int	size;

  ss.read(buff, 1);
  ss >> size;
  if (size < 0)
    return "";
  ss.get();
  char buffer[size+1];

  ss.read(buffer, size);
  buffer[size] = 0;
  if (ss.peek() == ';')
    ss.get();
  return  std::string(buffer);
}

std::string		Daemon::AComponent::getData(std::stringstream &ss)
{
  char	buff[2];
  int	size = 0;
  char *buffer = 0;

  if (!ss)
    return "";
  ss.read(buff, 2);
  ss >> size;
  ss.get();
  if (size < 0)
    return "";
  buffer = new char[size+1];
  bzero(buffer, size);
  if (ss)
    {
      ss.read(buffer, size);
      buffer[size] = 0;
      if (ss.peek() == ';')
	ss.get();
      return  std::string(buffer);
    }
  return "";
}
