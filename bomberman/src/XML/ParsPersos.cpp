
#include	"ParsPersos.hh"

#include	<iostream>

ParsPersos::ParsPersos(const std::string & nameFile)
  : _tiny(new OverTiny(nameFile)), _nameFile(nameFile)
{
  this->parsPersos();
}

ParsPersos::~ParsPersos()
{}

void						ParsPersos::parsPersos()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Persos");
    this->_tiny->getNode("Perso");
    while (this->_tiny->getActualNode()){
      std::string	name = "";
      int		level = 0;
      name = this->_tiny->getStringAttribute("name");
      level = this->_tiny->getIntegerAttribute("level");
      this->_persos.insert(std::pair<std::string, int> (name, level));
      this->_tiny->getNextNode();
    }
  }
}

std::map<std::string, int>     	     		ParsPersos::getPersos() const
{
  return this->_persos;
}
