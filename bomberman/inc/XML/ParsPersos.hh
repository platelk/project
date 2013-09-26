#ifndef __PARS_PERSOS_HH__
#define __PARS_PERSOS_HH__

//C++
#include	<string>
#include	<map>

//Local
#include	"OverTiny.hh"

class ParsPersos
{
public:
  ParsPersos(const std::string & nameFile = "./conf/profiles.xml");
  ~ParsPersos();

  //Pars
  void				       	parsPersos();

  //Get
  std::map<std::string, int> 		getPersos() const;

private:
  OverTiny*				_tiny;
  std::string				_nameFile;
  std::map<std::string, int>		_persos;
};

#endif
