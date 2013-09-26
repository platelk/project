#ifndef __PARS_MAPS_HH__
#define __PARS_MAPS_HH__

#include <string>
#include <vector>

#include <string>
#include <fstream>
#include <ios>

#include "Map.hh"
#include "OverTiny.hh"

class ParsMaps
{
public:
  ParsMaps(const std::string & nameFile = "./conf/maps.xml",
	   const std::string & directoryWay = "./conf/maps/");
  ~ParsMaps();

  std::string				intToString(int);

  void					parsMaps();
  Map*					parsMap(const std::string &);

  void					saveMaps();
  void					saveMap(const std::string &, Map *);

  Map*					getMap(const std::string &, int id = 1) const;
  std::vector<Map *>	       	       	getMapsByName(const std::string &) const;
  std::vector<Map *>			getMaps() const;

  void					addMap(Map *);
  void					deleteMap(Map *);

private:
  std::string				_nameFile;
  OverTiny*				_tiny;
  std::vector<Map *>			_maps;
  std::string				_directoryWay;
};

#endif
