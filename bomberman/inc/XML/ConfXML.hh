#ifndef __CONF_XML_HH__
#define __CONF_XML_HH__

#include	<string>
#include	<vector>

#include	<ParsLevels.hh>
#include	<ParsAchievments.hh>
#include	<ParsPersos.hh>
#include	<ParsProfiles.hh>
#include	<ParsMaps.hh>
#include	<ParsScores.hh>
#include	<ParsSaves.hh>

class ConfXML
{
public:
  ConfXML(const std::string & levelsFile  = "./conf/levels.xml",
	  const std::string & achievmentsFile  = "./conf/achievments.xml",
	  const std::string & persosFile  = "./conf/persos.xml",
	  const std::string & profilesFile  = "./conf/profiles.xml",
	  const std::string & mapsFile  = "./conf/maps.xml",
	  const std::string & scoresFile  = "./conf/scores.xml",
	  const std::string & savesFile  = "./conf/saves.xml");
  ~ConfXML();

  //Levels
  ParsLevels*				getParsLevel() const;

  //Persos
  ParsPersos*				getParsPersos() const;

  //Achievments
  std::vector<Achievment*>     		getAchievments() const;

  //Profile
  Profile*				getProfile(const std::string &, int id = 1) const;
  std::vector<Profile *>       		getProfilesByName(const std::string &) const;
  std::vector<Profile*>			getProfiles() const;
  void					addProfile(Profile *) const;
  void					deleteProfile(Profile *) const;

  //Map
  Map*					getMap(const std::string &, int id = 1) const;
  std::vector<Map *>       		getMapsByName(const std::string &) const;
  std::vector<Map *>			getMaps() const;
  void					addMap(Map *) const;
  void					deleteMap(Map *) const;

  //Scores
  std::vector<Score *>	  		getScoresByName(const std::string &, int id = 1) const;
  std::vector<Score *>	       		getScoresByScore(int) const;
  std::map<int, Score *>	       	getScores() const;
  void					addScore(Score *) const;

  //Saves
  Map*					getSave(const std::string &, int id = 1) const;
  std::vector<Map *>	       	       	getSavesByName(const std::string &) const;
  std::vector<Map *>			getSaves() const;
  void					addSave(Map *) const;
  void					deleteSave(Map *) const;

  void					save() const;

private:
  ParsLevels*				_parsLevels;
  ParsAchievments*     			_parsAchievments;
  ParsPersos*				_parsPersos;
  ParsProfiles*				_parsProfiles;
  ParsMaps*				_parsMaps;
  ParsScores*				_parsScores;
  ParsSaves*				_parsSaves;

};

#endif
