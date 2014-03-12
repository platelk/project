/*
** display_text.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 22 16:16:49 2012 ronan guiho
** Last update Sun Mar 25 10:11:33 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void			display_text_suite(t_vm *vm, SDL_Rect pos)
{
  if (vm->nb_champ >= 3)
    {
      vm->image[GAME][TEXT].pos.x = 1300;
      vm->image[GAME][TEXT].pos.y = 730;
      SDL_BlitSurface(vm->image[GAME][TEXT].img, &pos, vm->sc,
		      &vm->image[GAME][TEXT].pos);
    }
  if (vm->nb_champ >= 4)
    {
      vm->image[GAME][TEXT].pos.x = 275;
      vm->image[GAME][TEXT].pos.y = 730;
      SDL_BlitSurface(vm->image[GAME][TEXT].img, &pos, vm->sc,
		      &vm->image[GAME][TEXT].pos);
    }
}
void			display_text(t_vm *vm)
{
  static SDL_Rect	pos;

  pos.w = 90;
  pos.h = 90;
  if (pos.y > 900)
    pos.y = 0;
  if (vm->nb_champ >= 1)
    {
      vm->image[GAME][TEXT].pos.x = 595;
      vm->image[GAME][TEXT].pos.y = 730;
      SDL_BlitSurface(vm->image[GAME][TEXT].img, &pos, vm->sc,
		      &vm->image[GAME][TEXT].pos);
    }
  if (vm->nb_champ >= 2)
    {
      vm->image[GAME][TEXT].pos.x = 995;
      vm->image[GAME][TEXT].pos.y = 730;
      SDL_BlitSurface(vm->image[GAME][TEXT].img, &pos, vm->sc,
		      &vm->image[GAME][TEXT].pos);
    }
  display_text_suite(vm, pos);
  pos.y = pos.y + 100;
}
