#include		"ParsAchievments.hh"

ParsAchievments::ParsAchievments(const std::string & nameFile)
  : _tiny(new OverTiny(nameFile)), _nameFile(nameFile)
{
  this->parsAchievments();
}

ParsAchievments::~ParsAchievments()
{
  delete _tiny;
  for (std::vector<Achievment*>::iterator it = _achievments.begin(); it != _achievments.end(); ++it)
    delete (*it);
}

void				       	ParsAchievments::parsAchievments()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Achievments");
    this->_tiny->getNode("Achievment");
    while (this->_tiny->getActualNode()){

      std::string	name;
      std::string	description;
      std::string	sprite;
      long int		players;
      long int		games;
      long int		damages;
      name = this->_tiny->getStringAttribute("name");
      description = this->_tiny->getStringAttribute("desc");
      sprite = this->_tiny->getStringAttribute("sprite");
      players = this->_tiny->getIntegerAttribute("players");
      games = this->_tiny->getIntegerAttribute("games");
      damages = this->_tiny->getIntegerAttribute("damages");
      this->_achievments.push_back(new Achievment(name, description, sprite, players, games, damages));
      this->_tiny->getNextNode();
    }
  }
}

std::vector<Achievment*>       		ParsAchievments::getAchievments() const
{
  return this->_achievments;
}
