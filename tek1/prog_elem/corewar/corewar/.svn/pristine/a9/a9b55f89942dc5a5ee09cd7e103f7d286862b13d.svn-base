/*
** display_env.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Mar 19 09:31:56 2012 ronan guiho
** Last update Wed Mar 21 10:05:45 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void		display_environ(t_vm *vm)
{
  vm->image[GAME][BACK_RIGHT].pos.x = 1400;
  vm->image[GAME][BACK_RIGHT].pos.y = 310;
  SDL_BlitSurface(vm->image[GAME][BACK_RIGHT].img, NULL, vm->sc,
		  &vm->image[GAME][BACK_RIGHT].pos);
  vm->image[GAME][BACK_LEFT].pos.x = 0;
  vm->image[GAME][BACK_LEFT].pos.y = 330;
  SDL_BlitSurface(vm->image[GAME][BACK_LEFT].img, NULL, vm->sc,
		  &vm->image[GAME][BACK_LEFT].pos);
}
