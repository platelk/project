//
// SoundManager.cpp for /home/phalip_z/projet_tek2/test_fmod/SoundManager.cpp in /home/phalip_z//projet_tek2/test_fmod
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Fri May 10 16:19:24 2013 phalip_z
// Last update Mon Jun 10 23:01:10 2013 alexis leprovost
//

#include	<iostream>

#include	"Client/Sound/SoundManager.hh"

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void	SoundManager::addSound(const std::string &name,
			       const std::string &file_name, const std::string &type)
{
  if (type == Sound::AMBIANCE)
    this->_ambiance[name] = new Sound(file_name);
  else if (type == Sound::EFFECT)
    this->_effect[name] = new Sound(file_name);
}

Sound	*SoundManager::getSound(const std::string &name)
{
  std::map<std::string, Sound *>::iterator	it1;

  it1 = this->_ambiance.find(name);
  if (it1 != this->_ambiance.end())
    return (*it1).second;
  it1 = this->_effect.find(name);
  if (it1 != this->_ambiance.end())
    return (*it1).second;
  return (0);
}

void   	SoundManager::setAmbianceVolume(float ds, const std::string &type)
{
  std::map<std::string, Sound *>::iterator	it;

    if (type == Sound::AMBIANCE)
      {
	if (!this->_ambiance.empty())
	  for (it = this->_ambiance.begin() ; it != this->_ambiance.end(); ++it)
	    ((*it).second)->volume(ds);
      }
    else
      if (!this->_effect.empty())
	for (it = this->_effect.begin() ; it != this->_effect.end(); ++it)
	  ((*it).second)->volume(ds);
}

