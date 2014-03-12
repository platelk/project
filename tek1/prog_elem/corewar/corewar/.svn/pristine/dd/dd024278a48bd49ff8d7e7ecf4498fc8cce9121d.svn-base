/*
** display_die.c for Corewar in /home/guiho_r/tek1/corewar/include/vm
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 25 18:52:27 2012 ronan guiho
** Last update Sun Mar 25 21:10:30 2012 alexis leprovost
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void	display_die_suite(t_vm *vm)
{
  if (vm->nb_champ >= 3 &&
      counter_live(vm->champ, vm->champ->next->next->data[ID]) == -1)
    {
      vm->image[CHARACT][CARTMAN_DIE].pos.x = 1130;
      vm->image[CHARACT][CARTMAN_DIE].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][CARTMAN_DIE].img, NULL, vm->sc,
		      &vm->image[CHARACT][CARTMAN_DIE].pos);
    }
  if (vm->nb_champ == 4 &&
      counter_live(vm->champ, vm->champ->next->next->next->data[ID]) == -1)
    {
      vm->image[CHARACT][STAN_DIE].pos.x = 250;
      vm->image[CHARACT][STAN_DIE].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][STAN_DIE].img, NULL, vm->sc,
		      &vm->image[CHARACT][STAN_DIE].pos);
    }
}

void	display_die(t_vm *vm)
{
  if (vm->nb_champ >= 1 && counter_live(vm->champ, vm->champ->data[ID]) == -1)
    {
      vm->image[CHARACT][KENNY_DIE].pos.x = 570;
      vm->image[CHARACT][KENNY_DIE].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][KENNY_DIE].img, NULL, vm->sc,
		  &vm->image[CHARACT][KENNY_DIE].pos);
    }
  if (vm->nb_champ >= 2 && counter_live(vm->champ,
					vm->champ->next->data[ID]) == -1)
    {
      vm->image[CHARACT][KYLE_DIE].pos.x = 822;
      vm->image[CHARACT][KYLE_DIE].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][KYLE_DIE].img, NULL, vm->sc,
		  &vm->image[CHARACT][KYLE_DIE].pos);
    }
  display_die_suite(vm);
}
