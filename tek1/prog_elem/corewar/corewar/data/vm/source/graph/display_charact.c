/*
** display_charact.c for corewar in /home/guiho_r/tek1/corewar/data/vm/source
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 18 18:07:09 2012 ronan guiho
** Last update Sun Mar 25 18:57:05 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void	display_charact_center_suite(t_vm *vm)
{
  if (vm->nb_champ >= 3)
    {
      vm->image[CHARACT][CARTMAN_BACK].pos.x = 1130;
      vm->image[CHARACT][CARTMAN_BACK].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][CARTMAN_BACK].img, NULL, vm->sc,
		      &vm->image[CHARACT][CARTMAN_BACK].pos);
    }
  if (vm->nb_champ == 4)
    {
      vm->image[CHARACT][STAN_BACK].pos.x = 250;
      vm->image[CHARACT][STAN_BACK].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][STAN_BACK].img, NULL, vm->sc,
		      &vm->image[CHARACT][STAN_BACK].pos);
    }
}
void	display_charact_center(t_vm *vm)
{
  if (vm->nb_champ >= 1)
    {
      vm->image[CHARACT][KENNY_BACK].pos.x = 570;
      vm->image[CHARACT][KENNY_BACK].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][KENNY_BACK].img, NULL, vm->sc,
		  &vm->image[CHARACT][KENNY_BACK].pos);
    }
  if (vm->nb_champ >= 2)
    {
      vm->image[CHARACT][KYLE_BACK].pos.x = 822;
      vm->image[CHARACT][KYLE_BACK].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][KYLE_BACK].img, NULL, vm->sc,
		  &vm->image[CHARACT][KYLE_BACK].pos);
    }
  display_charact_center_suite(vm);
}

void	display_charact_left_suite(t_vm *vm)
{
  if (vm->nb_champ >= 3)
    {
      vm->image[CHARACT][CARTMAN_LEFT].pos.x = 1130;
      vm->image[CHARACT][CARTMAN_LEFT].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][CARTMAN_LEFT].img, NULL, vm->sc,
		      &vm->image[CHARACT][CARTMAN_LEFT].pos);
    }
  if (vm->nb_champ == 4)
    {
      vm->image[CHARACT][STAN_LEFT].pos.x = 250;
      vm->image[CHARACT][STAN_LEFT].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][STAN_LEFT].img, NULL, vm->sc,
		      &vm->image[CHARACT][STAN_LEFT].pos);
    }
}
void	display_charact_left(t_vm *vm)
{
  if (vm->nb_champ >= 1)
    {
      vm->image[CHARACT][KENNY_LEFT].pos.x = 570;
      vm->image[CHARACT][KENNY_LEFT].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][KENNY_LEFT].img, NULL, vm->sc,
		      &vm->image[CHARACT][KENNY_LEFT].pos);
    }
  if (vm->nb_champ >= 2)
    {
      vm->image[CHARACT][KYLE_LEFT].pos.x = 822;
      vm->image[CHARACT][KYLE_LEFT].pos.y = 680;
      SDL_BlitSurface(vm->image[CHARACT][KYLE_LEFT].img, NULL, vm->sc,
		      &vm->image[CHARACT][KYLE_LEFT].pos);
    }
  display_charact_left_suite(vm);
}
