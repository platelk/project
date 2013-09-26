#ifndef __SCORE_HH__
#define __SCORE_HH__

#include	<string>

class Score
{
public:

  enum Game
    {
      LOCAL = 0,
      ONLINE
    };

  Score(const std::string &, int, long int, Score::Game);
  ~Score();

  const std::string &		getName() const;
  void				setName(const std::string &);
  int				getId() const;
  void				setId(int);
  long int			getScore() const;
  void				setScore(long int);
  Game				getGame() const;

private:
  std::string		_name;
  int			_id;
  long int     		_score;
  Game			_game;
};

#endif
