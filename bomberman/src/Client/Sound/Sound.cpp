//
// Sound.cpp for /home/phalip_z/projet_tek2/test_fmod/Sound.cpp in /home/phalip_z//projet_tek2/test_fmod
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Thu May  9 11:53:37 2013 phalip_z
// Last update Sun Jun  9 02:06:44 2013 phalip_z
//

#include	<iostream>

#include	"Client/Sound/Sound.hh"

std::string const	Sound::AMBIANCE = "ambiance";
std::string const	Sound::EFFECT = "effect";

Sound::Sound(const std::string &name)
  : _tmp(false)
{
  FMOD_System_Create(&(this->_system));
  FMOD_System_Init(this->_system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(this->_system, name.c_str(),
			  FMOD_CREATESAMPLE, 0, &(this->_sound));
}

Sound::~Sound()
{
  FMOD_System_Close(this->_system);
  FMOD_System_Release(this->_system);
}

void	Sound::play(void)
{
  if (this->_channel)
    {
    FMOD_Channel_GetPaused(this->_channel, &(this->_tmp));
    }
  if (this->_tmp == true)
    FMOD_Channel_SetPaused(this->_channel, false);
  else
    FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE,
			  this->_sound, 0, &(this->_channel));
}

void	Sound::stop(void) const
{
  FMOD_Channel_SetPaused(this->_channel, true);
}

void	Sound::pause(void)
{
  FMOD_Channel_GetPaused(this->_channel, &(this->_tmp));
  if (this->_tmp == false)
    FMOD_Channel_SetPaused(this->_channel, true);
}

bool	Sound::isPlaying(void)
{
  FMOD_Channel_IsPlaying(this->_channel, &(this->_tmp));
  return this->_tmp;
}

void	Sound::volume(float ds) const
{
  FMOD_Channel_SetVolume(this->_channel, ds);
}

void	Sound::repeat(void)
{
  FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE,
			this->_sound, 0, &(this->_channel));
}
