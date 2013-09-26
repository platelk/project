#include "Map.hh"

Map::Map(const std::string & name, int id, const std::string & serialContent,
	 const std::string & screen)
  : _name(name), _id(id < 0 ? 0 : id), _serialContent(serialContent), _screen(screen)
{}

Map::Map(const std::string & name, int id, const std::string & serialContent,
	 const std::string & serialPlayer_1, const std::string & serialPlayer_2,
	 std::vector<std::string> ia, const std::string & screen)
  : _name(name), _id(id < 0 ? 0 : id), _serialContent(serialContent),
    _serialPlayer_1(serialPlayer_1), _serialPlayer_2(serialPlayer_2),
    _ia(ia), _screen(screen)
{}

Map::~Map()
{}

std::string				Map::getName() const
{
  return this->_name;
}

int					Map::getId() const
{
  return this->_id;
}

void					Map::setId(int id)
{
  this->_id = id;
}

std::string				Map::getSerialContent() const
{
  return this->_serialContent;
}

std::string				Map::getSerialPlayer_1() const
{
  return this->_serialPlayer_1;
}

std::string				Map::getSerialPlayer_2() const
{
  return this->_serialPlayer_2;
}

std::vector<std::string>      		Map::getIa() const
{
  return this->_ia;
}

std::string				Map::getScreen() const
{
  return this->_screen;
}
