#ifndef __SOUND_H__
# define __SOUND_H__

#include	<string>


#include "fmod.hpp"
#include "fmod.h"
#include "fmod_codec.h"
#include "fmod_dsp.h"
#include "fmodlinux.h"
#include "fmod_memoryinfo.h"
#include "fmod_errors.h"

class Sound
{
  FMOD_SYSTEM	*_system;
  FMOD_SOUND	*_sound;
  FMOD_CHANNEL	*_channel;
  FMOD_BOOL	_tmp;

public:
  Sound(const std::string &name);
  virtual ~Sound();
  void	play(void);
  void	stop(void) const;
  void	pause(void);
  bool	isPlaying(void);
  void	volume(float ds) const;
  void	repeat(void);

  static std::string const AMBIANCE;
  static std::string const EFFECT;
};

#endif /* !__SOUND_H__ */
