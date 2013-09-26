#include	"Achievment.hh"

Achievment::Achievment(const std::string & name, const std::string & desc,
		       const std::string & sprite,
		       long int players, long int games, long int damages)
  : _name(name),
    _desc(desc),
    _sprite(sprite),
    _players(players),
    _games(games),
    _damages(damages)
{}

Achievment::~Achievment()
{}

const std::string &		Achievment::getName() const
{
  return this->_name;
}

const std::string &		Achievment::getDescription() const
{
  return this->_desc;
}

const std::string &		Achievment::getSprite() const
{
  return this->_sprite;
}

long int			Achievment::getPlayersKilled() const
{
  return this->_players;
}

long int			Achievment::getGamesPlayed() const
{
  return this->_games;
}

long int			Achievment::getDamages() const
{
  return this->_damages;
}
