#ifndef __PARS_ACHIEVMENTS_HH__
#define __PARS_ACHIEVMENTS_HH__

//C++
#include	<string>
#include	<vector>

//Local
#include	"OverTiny.hh"
#include	"Achievment.hh"

class ParsAchievments
{
public:
  ParsAchievments(const std::string & nameFile = "./conf/achievments.xml");
  ~ParsAchievments();

  //Pars
  void				       	parsAchievments();

  //Get
  std::vector<Achievment*> 		getAchievments() const;

private:
  OverTiny*				_tiny;
  std::string				_nameFile;
  std::vector<Achievment*>		_achievments;
};

#endif
