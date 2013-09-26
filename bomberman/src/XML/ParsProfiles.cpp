#include	"ParsProfiles.hh"

#include	<iostream>

ParsProfiles::ParsProfiles(ParsLevels *parsLevels, ParsPersos *parsPersos,
			   std::vector<Achievment*> achievments,
			   const std::string & nameFile, const std::string &directoryWay)
  : _parsLevels(parsLevels),
    _parsPersos(parsPersos),
    _achievments(achievments),
    _tiny(new OverTiny(nameFile)), _directoryWay(directoryWay), _nameFile(nameFile)
{
  this->parsProfiles();
}

ParsProfiles::~ParsProfiles()
{
  delete _tiny;
  for (std::vector<Profile*>::iterator it = _profiles.begin(); it != _profiles.end(); ++it)
    delete (*it);
}

std::string					ParsProfiles::intToString(int a)
{
  std::stringstream s;

  s << a;
  return s.str();
}

void						ParsProfiles::parsProfiles()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Profiles");
    this->_tiny->getNode("Profile");
    while (this->_tiny->getActualNode()){
      std::string		file = this->_directoryWay + this->_tiny->getStringAttribute("name") + "_" + this->_tiny->getStringAttribute("id") + ".xml";
      if (this->parsProfile(file))
	this->_profiles.push_back(this->parsProfile(file));
      this->_tiny->getNextNode();
    }
  }
}

Profile *					ParsProfiles::parsProfile(const std::string & nameFile)
{
  std::string			name = "";
  int				id = 0;
  long int		       	xp = 0;
  long int			gamesPlayed = 0;
  long int		       	playersKilled = 0;
  int				damages = 0;
  int				ambiance = 0;
  int				effect = 0;
  OverTiny*			tiny = new OverTiny(nameFile);

  if (tiny->docIsLoad()){
    tiny->getRootNode("Profile");
    name = tiny->getRootStringAttribute("name");
    id = tiny->getRootIntegerAttribute("id");
    if (tiny->getNode("Experience"))
      xp = tiny->getIntegerAttribute("value");
    if (tiny->getNode("GamesPlayed"))
      gamesPlayed = tiny->getIntegerAttribute("value");
    if (tiny->getNode("PlayersKilled"))
    playersKilled = tiny->getIntegerAttribute("value");
    if (tiny->getNode("Damages"))
      damages = tiny->getIntegerAttribute("value");
    if (tiny->getNode("Ambiance"))
      ambiance = tiny->getIntegerAttribute("value");
    if (tiny->getNode("Effect"))
      effect = tiny->getIntegerAttribute("value");
    Profile	*profile = new Profile(name, this->_parsLevels, this->_parsPersos, this->_achievments,
				       id, xp, gamesPlayed, playersKilled, damages, ambiance, effect);
    if (tiny->getNode("Player_1"))
      this->getProfilePlayers(tiny, profile, 1);
    if (tiny->getNode("Player_2"))
      this->getProfilePlayers(tiny, profile, 2);
    delete tiny;
    return profile;
  }
  return 0;
}

void						ParsProfiles::getProfilePlayers(OverTiny *tiny, Profile *profile, int p)
{
  int		up;
  int		down;
  int		left;
  int		right;
  int		spell;
  int		throw_;

  Profile::Player player;
  if (p == 1)
    player = Profile::ONE;
  else
    player = Profile::TWO;
  up = tiny->getIntegerAttribute("up");
  profile->setKey(up, Profile::UP, player);
  down = tiny->getIntegerAttribute("down");
  profile->setKey(down, Profile::DOWN, player);
  right = tiny->getIntegerAttribute("right");
  profile->setKey(right, Profile::RIGHT, player);
  left = tiny->getIntegerAttribute("left");
  profile->setKey(left, Profile::LEFT, player);
  spell = tiny->getIntegerAttribute("spell");
  profile->setKey(spell, Profile::SPELL, player);
  throw_ = tiny->getIntegerAttribute("throw");
  profile->setKey(throw_, Profile::THROW, player);
}

void						ParsProfiles::saveProfiles()
{
  std::ofstream				file;

  file.open(this->_nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Profiles>" << std::endl;
    for (std::vector<Profile *>::iterator it = this->_profiles.begin(); it != this->_profiles.end(); ++it){
      file << "\t<Profile "
	   << "name=\"" << (*it)->getName() << "\" "
	   << "id=\"" << (*it)->getId() << "\"/>" << std::endl;
      this->saveProfile((this->_directoryWay + (*it)->getName() + "_" + this->intToString((*it)->getId()) + ".xml"), *it);
    }
    file << "</Profiles>" << std::endl;
    file.close();
  }
}

void						ParsProfiles::saveProfile(const std::string &nameFile, Profile *profile)
{
  std::ofstream				file;

  file.open(nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Profile "
	 << "name=\"" << profile->getName() << "\" id=\"" << profile->getId()
	 << "\">" << std::endl;
    file << "\t<Experience value=\"" << profile->getXp() << "\"/>" << std::endl;
    file << "\t<GamesPlayed value=\"" << profile->getGamesPlayed() << "\"/>" << std::endl;
    file << "\t<PlayersKilled value=\"" << profile->getPlayersKilled() << "\"/>" << std::endl;
    file << "\t<Damages value=\"" << profile->getDamages() << "\"/>" << std::endl;
    file << "\t<Player_1 up=\"" << profile->getKey(Profile::UP, Profile::ONE)
	 << "\" down=\"" << profile->getKey(Profile::DOWN, Profile::ONE)
	 << "\" right=\"" << profile->getKey(Profile::RIGHT, Profile::ONE)
	 << "\" left=\"" << profile->getKey(Profile::LEFT, Profile::ONE)
	 << "\" spell=\"" << profile->getKey(Profile::SPELL, Profile::ONE)
	 << "\" throw=\"" << profile->getKey(Profile::THROW, Profile::ONE)
	 << "\"/>" << std::endl;
    file << "\t<Player_2 up=\"" << profile->getKey(Profile::UP, Profile::TWO)
	 << "\" down=\"" << profile->getKey(Profile::DOWN, Profile::TWO)
	 << "\" right=\"" << profile->getKey(Profile::RIGHT, Profile::TWO)
	 << "\" left=\"" << profile->getKey(Profile::LEFT, Profile::TWO)
	 << "\" spell=\"" << profile->getKey(Profile::SPELL, Profile::TWO)
	 << "\" throw=\"" << profile->getKey(Profile::THROW, Profile::TWO)
	 << "\"/>" << std::endl;
    file << "\t<Ambiance value=\"" << profile->getAmbiance() << "\"/>" << std::endl;
    file << "\t<Effect value=\"" << profile->getEffect() << "\"/>" << std::endl;
    file << "</Profile>" << std::endl;
    file.close();
  }
}

Profile*					ParsProfiles::getProfile(const std::string & name, int id) const
{
  if (this->_profiles.size() > 0)
    for (std::vector<Profile *>::const_iterator it = this->_profiles.begin(); it != this->_profiles.end(); ++it){
      if ((*it)->getName().compare(name) == 0
	  && (*it)->getId() == id){
	return *it;
      }
    }
  return 0;
}

std::vector<Profile *>	       			ParsProfiles::getProfilesByName(const std::string & name) const
{
  std::vector<Profile *>		profiles;

  if (this->_profiles.size() > 0)
    for (std::vector<Profile *>::const_iterator it = this->_profiles.begin(); it != this->_profiles.end(); ++it){
      if ((*it)->getName().compare(name) == 0)
	profiles.push_back(*it);
    }
  return profiles;
}

std::vector<Profile *>		     		ParsProfiles::getProfiles() const
{
  return this->_profiles;
}

void						ParsProfiles::addProfile(Profile *profile)
{
  std::string				name = profile->getName();
  int					id  = profile->getId();
  bool					exist = false;

  for (std::vector<Profile *>::iterator it = this->_profiles.begin(); it != this->_profiles.end(); ++it){
    if ((*it)->getName().compare(name) == 0){
      exist = true;
      if ((*it)->getId() > id)
	id = (*it)->getId();
    }
  }
  if (exist == true)
    profile->setId(id + 1);
  if (profile->getId() <= 100)
    this->_profiles.push_back(profile);
}

void						ParsProfiles::deleteProfile(Profile *profile)
{
  std::string				name = profile->getName();

  for (std::vector<Profile *>::iterator it = this->_profiles.begin(); it != this->_profiles.end(); ++it){
    if ((*it)->getName().compare(name) == 0 &&
	(*it)->getId() == profile->getId()){
      this->_profiles.erase(it);
    }
  }
}
