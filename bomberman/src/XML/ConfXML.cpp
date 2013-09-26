#include	<ConfXML.hh>

ConfXML::ConfXML(const std::string & levelsFile, const std::string & achievmentsFile,
		 const std::string &persosFile, const std::string & profilesFile,
		 const std::string & mapsFile, const std::string & scoresFile,
		 const std::string & savesFile)
  : _parsLevels(new ParsLevels(levelsFile)),
    _parsAchievments(new ParsAchievments (achievmentsFile)),
    _parsPersos(new ParsPersos (persosFile)),
    _parsProfiles(new ParsProfiles(_parsLevels, _parsPersos, _parsAchievments->getAchievments(), profilesFile)),
    _parsMaps(new ParsMaps(mapsFile)),
    _parsScores(new ParsScores(scoresFile)),
    _parsSaves(new ParsSaves(savesFile))
{}

ConfXML::~ConfXML()
{
  delete _parsLevels;
  delete _parsAchievments;
  delete _parsPersos;
  delete _parsProfiles;
  delete _parsMaps;
  delete _parsScores;
  delete _parsSaves;
}

ParsLevels*				ConfXML::getParsLevel() const
{
  return this->_parsLevels;
}

ParsPersos*				ConfXML::getParsPersos() const
{
  return this->_parsPersos;
}

std::vector<Achievment*>       		ConfXML::getAchievments() const
{
  return this->_parsAchievments->getAchievments();
}

Profile*				ConfXML::getProfile(const std::string &name, int id) const
{
  return this->_parsProfiles->getProfile(name, id);
}

std::vector<Profile *>       		ConfXML::getProfilesByName(const std::string & name) const
{
  return this->_parsProfiles->getProfilesByName(name);
}

std::vector<Profile*>			ConfXML::getProfiles() const
{
  return this->_parsProfiles->getProfiles();
}

void					ConfXML::addProfile(Profile *profile) const
{
  this->_parsProfiles->addProfile(profile);
}

void					ConfXML::deleteProfile(Profile* profile) const
{
  this->_parsProfiles->deleteProfile(profile);
}

Map*					ConfXML::getMap(const std::string & name, int id) const
{
  return this->_parsMaps->getMap(name, id);
}

std::vector<Map *>	       	       	ConfXML::getMapsByName(const std::string &name) const
{
  return this->_parsMaps->getMapsByName(name);
}

std::vector<Map *>			ConfXML::getMaps() const
{
  return this->_parsMaps->getMaps();
}

void					ConfXML::addMap(Map *map) const
{
  this->_parsMaps->addMap(map);
}

void					ConfXML::deleteMap(Map *map) const
{
  this->_parsMaps->deleteMap(map);
}

std::vector<Score *>			ConfXML::getScoresByName(const std::string &name, int id) const
{
  return this->_parsScores->getScoresByName(name, id);
}

std::vector<Score *>	       		ConfXML::getScoresByScore(int score) const
{
  return this->_parsScores->getScoresByScore(score);
}

std::map<int, Score *>			ConfXML::getScores() const
{
  return this->_parsScores->getScores();
}

void					ConfXML::addScore(Score *score) const
{
  this->_parsScores->addScore(score);
}


Map*					ConfXML::getSave(const std::string &name, int id) const
{
  return this->_parsSaves->getSave(name, id);
}

std::vector<Map *>	       	       	ConfXML::getSavesByName(const std::string &name) const
{
  return this->_parsSaves->getSavesByName(name);
}

std::vector<Map *>			ConfXML::getSaves() const
{
  return this->_parsSaves->getSaves();
}

void					ConfXML::addSave(Map *save) const
{
  this->_parsSaves->addSave(save);
}

void					ConfXML::deleteSave(Map *save) const
{
  this->_parsSaves->deleteSave(save);
}

void					ConfXML::save() const
{
  this->_parsProfiles->saveProfiles();
  this->_parsMaps->saveMaps();
  this->_parsScores->saveScores();
  this->_parsSaves->saveSaves();
}
