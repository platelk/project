#include	"ParsScores.hh"

#include	<iostream>

ParsScores::ParsScores(const std::string & nameFile)
  : _tiny(new OverTiny(nameFile)), _nameFile(nameFile)
{
  this->parsScores();
}

ParsScores::~ParsScores()
{}

std::string					ParsScores::intToString(int a)
{
  std::stringstream s;

  s << a;
  return s.str();
}

void						ParsScores::parsScores()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Scores");
    this->_tiny->getNode("Score");
    while (this->_tiny->getActualNode()){
      std::string	name = "";
      int		id = 0;
      long int		score = 0;
      name = this->_tiny->getStringAttribute("name");
      id = this->_tiny->getIntegerAttribute("id");
      score = this->_tiny->getIntegerAttribute("value");
      if (this->_tiny->getIntegerAttribute("game") == 1)
	this->_scores.push_back(new Score(name, id, score, Score::ONLINE));
      else
	this->_scores.push_back(new Score(name, id, score, Score::LOCAL));
      this->_tiny->getNextNode();
    }
  }
}

void						ParsScores::saveScores()
{
  std::ofstream				file;

  file.open(this->_nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Scores>" << std::endl;
    for (std::vector<Score *>::iterator it = this->_scores.begin(); it != this->_scores.end(); ++it){
      file << "\t<Score "
	   << "name=\"" << (*it)->getName() << "\" "
	   << "id=\"" << (*it)->getId() << "\" "
	   << "value=\"" << (*it)->getScore() << "\" "
	   << "game=\"" << (*it)->getGame() << "\"/>" << std::endl;
    }
    file << "</Scores>" << std::endl;
    file.close();
  }
}

std::vector<Score *>				ParsScores::getScoresByName(const std::string &name, int id) const
{
  std::vector<Score *>		scores;

  if (this->_scores.size() > 0)
    for (std::vector<Score *>::const_iterator it = this->_scores.begin(); it != this->_scores.end(); ++it){
      if ((*it)->getName().compare(name) == 0
	  && (*it)->getId() == id){
	scores.push_back(*it);
      }
    }
  return scores;
}

std::vector<Score *>		       		ParsScores::getScoresByScore(int score) const
{
  std::vector<Score *>		scores;

  if (this->_scores.size() > 0)
    for (std::vector<Score *>::const_iterator it = this->_scores.begin(); it != this->_scores.end(); ++it){
      if ((*it)->getScore() == score)
	scores.push_back(*it);
    }
  return scores;
}

std::map<int, Score *>		     		ParsScores::getScores() const
{
  std::map<int, Score *>	ret;

  for (std::vector<Score *>::const_iterator it = this->_scores.begin(); it != this->_scores.end(); ++it)
    ret.insert(std::pair<int, Score *> ((*it)->getScore(), (*it)));
  return ret;
}

long int					ParsScores::getLowerScore()
{
  if (!this->_scores.empty()){
    long int		lower = this->_scores[0]->getScore();
    for (std::vector<Score *>::iterator it = this->_scores.begin(); it != this->_scores.end(); ++it){
      if ((*it)->getScore() < lower)
	lower = (*it)->getScore();
    }
    return lower;
  }
  return 0;
}

void						ParsScores::addScore(Score *score)
{
  std::string				name = score->getName();
  int					lowerScore  = this->getLowerScore();

  if (this->_scores.size() >= 10 && score->getScore() > lowerScore){
    for (std::vector<Score *>::iterator it = this->_scores.begin(); it != this->_scores.end(); ++it)
      if ((*it)->getScore() != lowerScore)
	*it = score;
  }
  else
    this->_scores.push_back(score);
}
