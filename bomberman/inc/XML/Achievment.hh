#ifndef __ACHIEVMENT_HH__
#define __ACHIEVMENT_HH__

#include	<string>

class Achievment
{
public:
  Achievment(const std::string & name, const std::string & desc, const std::string & sprite,
	     long int players, long int games, long int damages);
  ~Achievment();

  const std::string &		getName() const;
  const std::string &		getDescription() const;
  const std::string &	       	getSprite() const;
  long int			getPlayersKilled() const;
  long int			getGamesPlayed() const;
  long int			getDamages() const;

private:
  std::string		_name;
  std::string		_desc;
  std::string		_sprite;
  long int		_players;
  long int		_games;
  long int		_damages;
};

#endif
