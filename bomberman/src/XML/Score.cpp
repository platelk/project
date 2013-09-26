#include	"Score.hh"

Score::Score(const std::string &name, int id, long int score, Score::Game game)
  : _name(name), _id(id < 0 ? 0 : id), _score(score < 0 ? 0 : score), _game(game)
{}

Score::~Score()
{}

const std::string &		Score::getName() const
{
  return this->_name;
}

void				Score::setName(const std::string &name)
{
  this->_name = name;
}

int				Score::getId() const
{
  return this->_id;
}

void				Score::setId(int id)
{
  this->_id = id;
}

long int			Score::getScore() const
{
  return this->_score;
}

void				Score::setScore(long int score)
{
  this->_score = score;
}

Score::Game				Score::getGame() const
{
  return this->_game;
}
