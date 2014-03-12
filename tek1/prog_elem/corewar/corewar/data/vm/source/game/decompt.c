/*
** decompt.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Mar 19 10:20:11 2012 ronan guiho
** Last update Fri Mar 23 01:17:07 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

int		display_decompt(t_vm *vm, TTF_Font *police)
{
  int		nb;
  SDL_Surface	*text;
  SDL_Rect	pos;
  SDL_Color	c;
  FMOD_CHANNEL	*chan;

  nb = 4;
  c.r = 0;
  c.g = 0;
  c.b = 0;
  pos.x = 785;
  pos.y = 265;
  FMOD_System_PlaySound(vm->sound[EVENT][PREPAR_FIGHT].sys, FMOD_CHANNEL_FREE,
			vm->sound[EVENT][PREPAR_FIGHT].sound, 0, &chan);
  while (nb > 0)
    {
      text = TTF_RenderText_Blended(police, my_getstr(nb--, "0123456789"), c);
      SDL_BlitSurface(text, NULL, vm->sc, &pos);
      SDL_Flip(vm->sc);
      SDL_Delay(1480);
      display_all(vm, 0);
    }
  return (0);
}
