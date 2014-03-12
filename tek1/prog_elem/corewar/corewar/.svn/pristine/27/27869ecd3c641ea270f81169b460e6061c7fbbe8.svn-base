/*
** hello_sound.c for Corewar in /home/guiho_r/tek1/corewar/include/vm
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 25 21:10:33 2012 ronan guiho
** Last update Sun Mar 25 21:51:44 2012 alexis leprovost
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void		hello_sound(SDL_Event event, t_sound **sound_tab)
{
  FMOD_CHANNEL *ch;

  if ((event.button.x >= 166 && event.button.x <= 400) &&
      (event.button.y >= 544 && event.button.y <= 944))
    FMOD_System_PlaySound(sound_tab[EVENT][BEGIN].sys,
			  FMOD_CHANNEL_FREE,
			  sound_tab[EVENT][BEGIN].sound, 0, &ch);
}
