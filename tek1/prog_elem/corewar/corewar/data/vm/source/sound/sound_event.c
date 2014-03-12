/*
** sound_event.c for corewar in /home/guiho_r/tek1/corewar/source/VM/sound
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 11:57:06 2012 ronan guiho
** Last update Sun Mar 25 03:07:08 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "fmod.h"
#include "corewar.h"

t_sound		*init_sound_event(char *path)
{
  int		i;
  char		*path_sound;
  char		*tmp;
  t_sound	*sound_tab;
  FMOD_RESULT	c;

  i = -1;
  if ((sound_tab = malloc(sizeof(t_sound) * NB_SOUND_EVENT_MAX)) == NULL)
    return (NULL);
  while (++i < NB_SOUND_EVENT_MAX)
    {
      FMOD_System_Create(&sound_tab[i].sys);
      FMOD_System_Init(sound_tab[i].sys, 1, FMOD_INIT_NORMAL, NULL);
      tmp = my_getstr(i, "0123456789");
      path_sound = my_str_concat(tmp, FORMAT_SOUND);
      if ((c = FMOD_System_CreateSound
	   (sound_tab[i].sys, my_str_concat(path, path_sound),
	    FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0,
	    &sound_tab[i].sound)) != FMOD_OK)
	return (NULL);
      printf("[*] Sound event %s load\n", path_sound);
      free(tmp);
      free(path_sound);
    }
  return (sound_tab);
}
