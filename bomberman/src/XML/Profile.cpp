//
// Profile.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Mon Jun  3 13:16:53 2013 alexis leprovost
// Last update Sat Jun  8 01:50:07 2013 ronan guiho
//

#include <string>
#include <iostream>

#include "Profile.hh"
#include "Client/Controller/Input.hh"

Profile::Profile(const std::string & name,  ParsLevels* parsLevels,
		 ParsPersos* parsPersos, std::vector<Achievment*> achievments,
		 int id, long int xp, long int gamesPlayed,
		 long int playerKilled, int damages,
		 size_t effect, size_t ambiance)
  : _name(name),
    _id(id < 0 ? 0 : id),
    _xp(xp < 0 ? 0 : xp),
    _gamesPlayed(gamesPlayed < 0 ? 0 : gamesPlayed),
    _playersKilled(playerKilled < 0 ? 0 : playerKilled),
    _damages(damages < 0 ? 0 : damages),
    _effect(effect),
    _ambiance(ambiance),
  _parsLevels(parsLevels),
  _achievments(achievments),
  _persos(parsPersos->getPersos()),
  _newLevel(false),
  _newAchievments(false)
{
  this->_keys[Profile::ONE][Profile::UP] = Client::Input::Keys::Z;
  this->_keys[Profile::ONE][Profile::RIGHT] = Client::Input::Keys::D;
  this->_keys[Profile::ONE][Profile::DOWN] = Client::Input::Keys::S;
  this->_keys[Profile::ONE][Profile::LEFT] = Client::Input::Keys::Q;
  this->_keys[Profile::ONE][Profile::THROW] = Client::Input::Keys::Y;
  this->_keys[Profile::ONE][Profile::SPELL] = Client::Input::Keys::U;
  this->_keys[Profile::TWO][Profile::UP] = Client::Input::Keys::Up;
  this->_keys[Profile::TWO][Profile::RIGHT] = Client::Input::Keys::Right;
  this->_keys[Profile::TWO][Profile::DOWN] = Client::Input::Keys::Down;
  this->_keys[Profile::TWO][Profile::LEFT] = Client::Input::Keys::Left;
  this->_keys[Profile::TWO][Profile::THROW] = Client::Input::Keys::Num0;
  this->_keys[Profile::TWO][Profile::SPELL] = Client::Input::Keys::Enter;
  this->getLevel();
  this->updateProfile();
  this->_newAchievments = false;
  this->_lastAchievments.clear();
}

Profile::~Profile()
{

}

std::string				Profile::getName() const
{
  return this->_name;
}

void					Profile::setName(const std::string &name)
{
  this->_name = name;
}

int					Profile::getId() const
{
  return this->_id;
}

void					Profile::setId(int id)
{
  this->_id = id;
}

std::pair<int, Level*>			Profile::getLevel()
{
  this->_newLevel = false;
  this->_level = this->_parsLevels->getNbLevel(this->_xp);
  return this->_parsLevels->getLevel(this->_xp);
}

int			 		Profile::getXpLevel()
{
  this->_newLevel = false;
  return this->_parsLevels->getXpLevel(this->_xp);
}

int			 		Profile::getNbLevel()
{
  this->_newLevel = false;
  return this->_parsLevels->getNbLevel(this->_xp);
}

std::string		 		Profile::getStringLevel()
{
  this->_newLevel = false;
  return this->_parsLevels->getStringLevel(this->_xp);
}

std::string		 		Profile::getImageLevel()
{
  this->_newLevel = false;
  return this->_parsLevels->getImageLevel(this->_xp);
}

long int			       	Profile::getXp() const
{
  return this->_xp;
}

void					Profile::addXp(long int xp)
{
  this->_xp += xp;
  this->updateProfile();
}

long int				Profile::getGamesPlayed() const
{
  return this->_gamesPlayed;
}

void					Profile::addGamesPlayed(long int gamesPlayed)
{
  this->addXp(gamesPlayed * XP_PER_GAME_PLAYED);
  this->_gamesPlayed += gamesPlayed;
}

long int			       	Profile::getPlayersKilled() const
{
  return this->_playersKilled;
}

void					Profile::addPlayersKilled(long int playerKilled)
{
  this->_playersKilled += playerKilled;
  this->addXp(playerKilled * XP_PER_PLAYER);
}

int					Profile::getDamages() const
{
  return this->_damages;
}

void					Profile::addDamages(int damages)
{
  this->_damages += damages;
  this->addXp(damages * XP_PER_DAMAGE);
}

void					Profile::setKey(int key, Key ref, Player id)
{
  this->_keys[id][ref] = key;
}

int					Profile::getKey(Key ref, Player id)
{
  return (this->_keys[id][ref]);
}

int					Profile::getAmbiance() const
{
  return this->_ambiance;
}

int					Profile::getEffect() const
{
  return this->_effect;
}

void					Profile::setAmbiance(size_t ambiance)
{
  this->_ambiance = ambiance;
}

void					Profile::setEffect(size_t effect)
{
  this->_effect = effect;
}

bool					Profile::isAvailable(const std::string & name)
{
  if (!this->_persos.empty())
    for (std::map<std::string, int>::const_iterator it = this->_persos.begin(); it != this->_persos.end(); ++it){
      if ((*it).first.compare(name) == 0 && (*it).second <= this->_level)
	return true;
    }
  return false;
}

std::vector<Achievment*>		Profile::getDoneAchievments() const
{
  return this->_doneAchievments;
}

std::vector<Achievment*>		Profile::getLastAchievments()
{
  this->_newAchievments = false;
  return this->_lastAchievments;
}

std::map<bool, Achievment*>		Profile::getMappedAchievments()
{
  std::map<bool, Achievment*>	map;

  for (std::vector<Achievment*>::iterator it = this->_achievments.begin();
       it != this->_achievments.end(); ++it){
    if (checkIsInDone(*it))
      map.insert(std::pair<bool, Achievment*> (true, (*it)));
    else
      map.insert(std::pair<bool, Achievment*> (false, (*it)));
  }
  return map;
}

bool					Profile::newLevel() const
{
  return this->_newLevel;
}

bool					Profile::newAchievments() const
{
  return this->_newAchievments;
}

bool					Profile::checkIsInDone(Achievment *ach)
{
  for (std::vector<Achievment *>::iterator it = this->_doneAchievments.begin();
       it != this->_doneAchievments.end(); ++it){
    if ((*it)->getName().compare(ach->getName()) == 0){
      return true;
    }
  }
  return false;
}

bool					Profile::checkIsInLast(Achievment *ach)
{
  for (std::vector<Achievment *>::iterator it = this->_lastAchievments.begin();
       it != this->_lastAchievments.end(); ++it){
    if ((*it)->getName().compare(ach->getName()) == 0){
      return true;
    }
  }
  return false;
}

void					Profile::doneAchiev(Achievment *it)
{
  if (!this->checkIsInLast(it) && !this->checkIsInDone(it)){
    this->_lastAchievments.push_back(it);
    this->_newAchievments = true;
    this->_doneAchievments.push_back(it);
  }

}

void					Profile::updateProfile()
{
  int		lastLevel = this->_level;

  if (!this->_lastAchievments.empty() && this->_newAchievments == false)
    this->_lastAchievments.clear();
  if (this->getLevel().first != lastLevel)
    this->_newLevel = true;
  if (!this->_achievments.empty())
    for (std::vector<Achievment*>::iterator it = this->_achievments.begin(); it != this->_achievments.end(); ++it){
      if ((*it)->getPlayersKilled() > 0 && (*it)->getPlayersKilled() <= this->_playersKilled)
	this->doneAchiev(*it);
      if ((*it)->getGamesPlayed() > 0 && (*it)->getGamesPlayed() <= this->_gamesPlayed)
	this->doneAchiev(*it);
      if ((*it)->getDamages() > 0 && (*it)->getDamages() <= this->_damages)
	this->doneAchiev(*it);
    }
}
