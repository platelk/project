#ifndef __PARS_SCORES_HH__
#define __PARS_SCORES_HH__

//C++
#include	<string>
#include	<map>
#include	<vector>
#include	<sstream>
#include	<fstream>
#include        <ios>

//Libs
#include	<tinyxml2.h>

//Local
#include	"OverTiny.hh"
#include	"Score.hh"

class ParsScores
{
public:
  ParsScores(const std::string & nameFile = "./conf/scores.xml");
  ~ParsScores();

  //Outils
  std::string				intToString(int);

  //Pars
  void				       	parsScores();

  //Save
  void				       	saveScores();

  //Get
  std::vector<Score *>	  		getScoresByName(const std::string &, int id = 1) const;
  std::vector<Score *>	       		getScoresByScore(int) const;
  std::map<int, Score *>		getScores() const;
  long int				getLowerScore();

  //ADD
  void					addScore(Score *);

private:
  OverTiny*				_tiny;
  std::string				_nameFile;
  std::vector<Score *>			_scores;
};

#endif
