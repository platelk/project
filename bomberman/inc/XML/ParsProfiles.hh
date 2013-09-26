#ifndef __PARS_PROFILES_HH__
#define __PARS_PROFILES_HH__

//C++
#include	<string>
#include	<vector>
#include	<sstream>
#include	<fstream>
#include        <ios>

//Libs
#include	<tinyxml2.h>

//Local
#include	"OverTiny.hh"
#include	"Profile.hh"
#include	"ParsLevels.hh"
#include	"ParsPersos.hh"

class ParsProfiles
{
public:
  ParsProfiles(ParsLevels *, ParsPersos *, std::vector<Achievment*>,
	       const std::string & nameFile = "./conf/profiles.xml",
	       const std::string & directoryWay = "./conf/profiles/");
  ~ParsProfiles();

  //Outils
  std::string				intToString(int);

  //Pars
  void				       	parsProfiles();
  void				       	getProfilePlayers(OverTiny*, Profile*, int);
  Profile*			       	parsProfile(const std::string &);

  //Save
  void				       	saveProfiles();
  void				       	saveProfile(const std::string &, Profile *);
  //Get

  Profile*				getProfile(const std::string &, int id = 1) const;
  std::vector<Profile *>       		getProfilesByName(const std::string & name) const;
  std::vector<Profile *>		getProfiles() const;

  //ADD
  void					addProfile(Profile *);
  void					deleteProfile(Profile *);

private:
  ParsLevels*				_parsLevels;
  ParsPersos*				_parsPersos;
  std::vector<Achievment*>    		_achievments;
  OverTiny*				_tiny;
  std::string				_directoryWay;
  std::string				_nameFile;
  std::vector<Profile*>			_profiles;
};

#endif
