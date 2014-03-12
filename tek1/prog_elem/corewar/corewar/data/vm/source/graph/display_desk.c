/*
** display_desk.c for corewar in /home/guiho_r/tek1/corewar/data/VM/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 14 13:30:36 2012 ronan guiho
** Last update Mon Mar 19 10:12:56 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void	display_desk(t_vm *vm)
{
  vm->image[GAME][DESK_LEFT].pos.x = 215;
  vm->image[GAME][DESK_LEFT].pos.y = 710;
  SDL_BlitSurface(vm->image[GAME][DESK_LEFT].img, NULL, vm->sc,
		  &vm->image[GAME][DESK_LEFT].pos);
  vm->image[GAME][DESK_LEFT].pos.x = 535;
  vm->image[GAME][DESK_LEFT].pos.y = 710;
  SDL_BlitSurface(vm->image[GAME][DESK_LEFT].img, NULL, vm->sc,
		  &vm->image[GAME][DESK_LEFT].pos);
  vm->image[GAME][DESK_RIGHT].pos.x = 855;
  vm->image[GAME][DESK_RIGHT].pos.y = 710;
  SDL_BlitSurface(vm->image[GAME][DESK_RIGHT].img, NULL, vm->sc,
		  &vm->image[GAME][DESK_RIGHT].pos);
  vm->image[GAME][DESK_RIGHT].pos.x = 1162;
  vm->image[GAME][DESK_RIGHT].pos.y = 710;
  SDL_BlitSurface(vm->image[GAME][DESK_RIGHT].img, NULL, vm->sc,
		  &vm->image[GAME][DESK_RIGHT].pos);
}
