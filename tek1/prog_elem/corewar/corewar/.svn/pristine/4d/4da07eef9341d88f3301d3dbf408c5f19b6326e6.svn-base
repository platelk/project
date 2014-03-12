/*
** display_credit.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 24 23:52:00 2012 ronan guiho
** Last update Sun Mar 25 21:49:34 2012 alexis leprovost
*/

#include <stdlib.h>
#include <unistd.h>

#include "vm.h"
#include "corewar.h"

void	fill_pos_generique(SDL_Rect p)
{
  p.x = 0;
  p.y = 0;
  p.w = 640;
  p.h = 500;
}
void	display_credit(t_vm *vm)
{
  FMOD_CHANNEL	*ch;
  SDL_Rect	p;

  FMOD_System_PlaySound(vm->sound[EVENT][SPLASH].sys, FMOD_CHANNEL_FREE,
			vm->sound[EVENT][SPLASH].sound, 0, &ch);
  display_all(vm, 0);
  vm->image[GAME][BLOOD].pos.x = 0;
  vm->image[GAME][BLOOD].pos.y = 0;
  SDL_BlitSurface(vm->image[GAME][BLOOD].img, NULL, vm->sc,
		  &vm->image[GAME][BLOOD].pos);
  vm->image[GAME][GENERIQUE].pos.x = 500;
  vm->image[GAME][GENERIQUE].pos.y = 50;
  fill_pos_generique(p);
  while (p.y < 1000 && !usleep(20000))
    {
      key_battel_ground(vm);
      vm->image[GAME][BLOOD].pos.x = 0;
      vm->image[GAME][BLOOD].pos.y = 0;
      SDL_BlitSurface(vm->image[GAME][BLOOD].img, NULL, vm->sc,
		      &vm->image[GAME][BLOOD].pos);
      SDL_BlitSurface(vm->image[GAME][GENERIQUE].img, &p, vm->sc,
		      &vm->image[GAME][GENERIQUE].pos);
      p.y = p.y + 1;
      SDL_Flip(vm->sc);
    }
}
