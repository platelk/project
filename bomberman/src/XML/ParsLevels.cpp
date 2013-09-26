
#include		"ParsLevels.hh"

ParsLevels::ParsLevels(const std::string & nameFile)
  : _tiny(new OverTiny(nameFile)), _nameFile(nameFile)
{
  this->parsLevels();
}

ParsLevels::~ParsLevels()
{
  delete _tiny;
  for (std::map<int, Level*>::iterator it = _levels.begin(); it != _levels.end(); ++it)
    delete (*it).second;
}

void				       	ParsLevels::parsLevels()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Levels");
    this->_tiny->getNode("Level");
    while (this->_tiny->getActualNode()){
      std::string name = this->_tiny->getStringAttribute("name");
      int xp = this->_tiny->getIntegerAttribute("xp");
      std::string sprite = this->_tiny->getStringAttribute("sprite");
      this->_levels.insert(std::pair<int, Level*>(xp, new Level(name, xp, sprite)));
      this->_tiny->getNextNode();
    }
  }
}

std::pair<int, Level*>			ParsLevels::getLevel(int xp) const
{
   if (this->_levels.find(xp) == this->_levels.end())
    return std::pair<int, Level*> (0, 0);
  return *this->_levels.find(xp);
}

int			 		ParsLevels::getXpLevel(int xp) const
{
   if (this->getLevel(xp).first == xp)
    return this->getLevel(xp).first;
  return this->getLowerLevel(xp).first;
}

int			 		ParsLevels::getNbLevel(int xp)
{
   int	level = 0;

  std::pair<int, Level*>	stock = std::pair<int, Level*> (0, 0);

  for (std::map<int, Level*>::const_iterator it = this->_levels.begin(); it != this->_levels.end(); ++it){
    if (it->first <= xp && it->first >= stock.first){
      level++;
      stock = *it;
    }
  }
  return level;
}

std::string		 		ParsLevels::getStringLevel(int xp) const
{
  if (this->getLevel(xp).first == xp)
    return this->getLevel(xp).second->getName();
  return this->getLowerLevel(xp).second->getName();
}

std::string		 		ParsLevels::getImageLevel(int xp) const
{
  if (this->getLevel(xp).first == xp)
    return this->getLevel(xp).second->getSprite();
  return this->getLowerLevel(xp).second->getSprite();
}

std::pair<int, Level*> 		ParsLevels::getLowerLevel(int xp) const
{
  std::pair<int, Level*>	stock = std::pair<int, Level*> (0, 0);

  for (std::map<int, Level*>::const_iterator it = this->_levels.begin(); it != this->_levels.end(); ++it){
    if (it->first <= xp && it->first >= stock.first)
      stock = *it;
  }
return stock;
}

std::pair<int, Level*>			ParsLevels::getHigherLevel(int xp) const
{
  std::pair<int, Level*>	stock = std::pair<int, Level*> (120280, 0);

  for (std::map<int, Level*>::const_iterator it = this->_levels.begin(); it != this->_levels.end(); ++it){
    if (it->first >= xp && it->first <= stock.first)
      stock = *it;
  }
  return stock;
}

std::map<int, Level*>			ParsLevels::getLevels() const
{
  return this->_levels;
}
