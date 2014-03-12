/*
** sound.c for corewar in /home/guiho_r/tek1/corewar/source/VM/sound
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 11:12:27 2012 ronan guiho
** Last update Wed Mar 21 10:08:57 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

/*
  FMOD_System_PlaySound(sound_tab[EVENT][0].sys, FMOD_CHANNEL_FREE,
			sound_tab[EVENT][0].sound, 0, NULL);
*/
t_sound		**init_sound()
{
  t_sound	**sound_tab;

  if ((sound_tab = malloc(sizeof(t_sound *) * NB_SOUND_TYPE_MAX)) == NULL)
    return (NULL);
  if ((sound_tab[EVENT] = init_sound_event(PATH_SOUND_EVENT)) == NULL)
    return (NULL);
  if ((sound_tab[AMB] = init_sound_amb(PATH_SOUND_AMB)) == NULL)
    return (NULL);
  return (sound_tab);
}
