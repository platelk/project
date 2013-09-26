#ifndef __SOUNDMANAGER_H__
# define __SOUNDMANAGER_H__

#include	<map>
#include	<string>

#include	"Sound.hh"

class SoundManager
{
  std::map<std::string, Sound *>	_ambiance;
  std::map<std::string, Sound *>	_effect;

public:
  SoundManager();
  virtual ~SoundManager();
  void	addSound(const std::string &name,
		 const std::string &file_name, const std::string &type);
  void 	setAmbianceVolume(float ds, const std::string &type);
  Sound	*getSound(const std::string &name);
};

#endif /* !__SOUNDMANAGER_H__ */
