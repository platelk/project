#ifndef __PARS_LEVELS_HH__
#define __PARS_LEVELS_HH__

//C++
#include	<string>
#include	<map>

//Local
#include	"OverTiny.hh"
#include	"Level.hh"

class ParsLevels
{
public:
  ParsLevels(const std::string & nameFile = "./conf/levels.xml");
  ~ParsLevels();

  //Pars
  void				       	parsLevels();

  //Get
  std::pair<int, Level*> 		getLevel(int) const;
  int			 		getXpLevel(int) const;
  int			 		getNbLevel(int);
  std::string		 		getStringLevel(int) const;
  std::string		 		getImageLevel(int) const;

  std::pair<int, Level*> 		getLowerLevel(int) const;
  std::pair<int, Level*> 		getHigherLevel(int) const;
  std::map<int, Level*> 		getLevels() const;

private:
  OverTiny*				_tiny;
  std::string				_nameFile;
  std::map<int, Level*> 		_levels;
};

#endif
