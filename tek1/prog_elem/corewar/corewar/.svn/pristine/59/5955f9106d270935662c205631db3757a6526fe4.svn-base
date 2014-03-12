/*
** sound.h for corewar in /home/guiho_r/tek1/corewar/source/VM/sound
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 11:16:27 2012 ronan guiho
** Last update Sun Mar 25 20:57:44 2012 ronan guiho
*/

#ifndef	__SOUND_H__
#define __SOUND_H__

#include "fmod.h"

#define SIZE_ID_SOUND		1
#define FORMAT_SOUND		".mp3"
#define NB_SOUND_TYPE_MAX	2
#define NB_SOUND_EVENT_MAX	10
#define NB_SOUND_AMB_MAX	2
#define PATH_SOUND_EVENT	"./clips/sound/event/"
#define PATH_SOUND_AMB		"./clips/sound/amb/"

typedef enum
{
  EVENT,
  AMB
} e_type;

typedef enum
{
  MONSTER_KILL,
  UNSTOPPABLE,
  LIVE_SOUND,
  PREPAR_FIGHT,
  FORK,
  START,
  KILL_KENNY,
  SPLASH,
  CARTMAN_LEAVE,
  BEGIN
} e_event;

typedef enum
{
  MENU_SOUND,
  IN_GAME
} e_amb;

typedef struct s_sound
{
  FMOD_SYSTEM	*sys;
  FMOD_SOUND	*sound;
  FMOD_CHANNEL	*ch;
} t_sound;

#endif
