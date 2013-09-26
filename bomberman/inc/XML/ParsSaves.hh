#ifndef __PARS_SAVES_HH__
#define __PARS_SAVES_HH__

#include <string>
#include <vector>

#include <string>
#include <fstream>
#include <ios>

#include "Map.hh"
#include "OverTiny.hh"

class ParsSaves
{
public:
  ParsSaves(const std::string & nameFile = "./conf/saves.xml",
	   const std::string & directoryWay = "./conf/saves/");
  ~ParsSaves();

  std::string				intToString(int);

  void					parsSaves();
  Map*					parsSave(const std::string &);

  void					saveSaves();
  void					saveSave(const std::string &, Map *);

  Map*					getSave(const std::string &, int id = 1) const;
  std::vector<Map *>	       	       	getSavesByName(const std::string &) const;
  std::vector<Map *>			getSaves() const;
  void					addSave(Map *);
  void					deleteSave(Map *);

private:
  std::string				_nameFile;
  OverTiny*				_tiny;
  std::vector<Map *>			_saves;
  std::string				_directoryWay;
};

#endif
