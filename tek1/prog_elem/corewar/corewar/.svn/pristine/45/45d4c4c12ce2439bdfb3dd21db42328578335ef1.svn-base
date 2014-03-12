/*
** display_all.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Mar 19 09:57:42 2012 ronan guiho
** Last update Sun Mar 25 19:00:52 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void	display_all(t_vm *vm, int flag)
{
  display_environ(vm);
  vm->image[GAME][BACK_IG].pos.x = 0;
  vm->image[GAME][BACK_IG].pos.y = 0;
  SDL_BlitSurface(vm->image[GAME][BACK_IG].img, NULL, vm->sc,
		  &vm->image[GAME][BACK_IG].pos);
  vm->image[GAME][PROJECTOR].pos.x = 700;
  vm->image[GAME][PROJECTOR].pos.y = 0;
  SDL_BlitSurface(vm->image[GAME][PROJECTOR].img, NULL, vm->sc,
		  &vm->image[GAME][PROJECTOR].pos);
  display_desk(vm);
  display_text(vm);
  (flag == 0) ? display_charact_center(vm) : display_charact_left(vm);
  display_die(vm);
  display_chair(vm);
  display_card_all(vm);
  aff_mem(vm);
  vm->image[GAME][BACK_IG].pos.x = X_MEM;
  vm->image[GAME][BACK_IG].pos.y = Y_MEM;
  SDL_BlitSurface(vm->sc_mem, NULL, vm->sc,
		  &vm->image[GAME][BACK_IG].pos);
}
