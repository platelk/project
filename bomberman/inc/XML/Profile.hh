#ifndef __PROFILE_HH__
#define __PROFILE_HH__

#define	XP_PER_DAMAGE		1
#define	XP_PER_PLAYER		5
#define	XP_PER_GAME_PLAYED	10

#include <map>
#include <vector>

#include "ParsLevels.hh"
#include "ParsPersos.hh"
#include "Achievment.hh"

class Profile
{
public:
  enum Player
    {
      ONE = 0,
      TWO
    };
  enum Key
    {
      UP,
      RIGHT,
      DOWN,
      LEFT,
      THROW,
      SPELL
    };
  typedef std::map<Player, std::map<int, int > >	Manual;
  Profile(const std::string & name , ParsLevels* parsLevels, ParsPersos* parsPersos,
	  std::vector<Achievment*> achievments,
	  int id = 1, long int xp = 0, long int gamesPlayed = 0,
	  long int playerKilled = 0, int damages= 0, size_t effect = 50, size_t ambiance = 20);
  ~Profile();

  //Levels
  std::pair<int, Level*> 	getLevel();
  int			 	getXpLevel();
  int			 	getNbLevel();
  std::string		 	getStringLevel();
  std::string		 	getImageLevel();

  //Getters
  std::string			getName() const;
  int				getId() const;
  long int		       	getXp() const;
  long int			getGamesPlayed() const;
  long int		       	getPlayersKilled() const;
  int				getDamages() const;
  int				getKey(Key, Player);
  int				getAmbiance() const;
  int				getEffect() const;

  //Setters
  void				setName(const std::string &);
  void				setId(int);
  void			       	addXp(long int);
  void				addGamesPlayed(long int);
  void			       	addPlayersKilled(long int);
  void				addDamages(int);
  void				setKey(int, Key, Player);
  void				setAmbiance(size_t ambiance);
  void				setEffect(size_t effect);

  //Perso
  bool				isAvailable(const std::string &);

  //Achievments
  std::vector<Achievment*>	getDoneAchievments() const;
  std::vector<Achievment*>	getLastAchievments();
  std::map<bool, Achievment*>	getMappedAchievments();

  //Check Updates
  bool				newLevel() const;
  bool				newAchievments() const;

  //Updates
  void				doneAchiev(Achievment *);
  bool				checkIsInDone(Achievment*);
  bool				checkIsInLast(Achievment*);
  void				updateProfile();

private:
  std::string			_name;
  int				_id;
  long int		       	_xp;
  long int			_gamesPlayed;
  long int		       	_playersKilled;
  int				_damages;
  size_t			_effect;
  size_t			_ambiance;
  ParsLevels*			_parsLevels;
  std::vector<Achievment*>	_achievments;
  std::vector<Achievment*>	_doneAchievments;
  std::vector<Achievment*>	_lastAchievments;
  std::map<std::string, int>	_persos;
  Manual			_keys;
  bool				_newLevel;
  bool				_newAchievments;
  int				_level;
};

#endif
