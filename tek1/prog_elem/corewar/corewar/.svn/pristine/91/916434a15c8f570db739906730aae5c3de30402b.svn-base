/*
** write.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/struct/mnemoniques
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Mar 20 14:15:09 2012 ronan guiho
** Last update Sun Mar 25 20:54:16 2012 alexis leprovost
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

int		disp_write_mem(t_vm *vm, t_mem *ptr)
{
  SDL_Surface	*txt;
  TTF_Font	*police;
  SDL_Color	color;

  color.r = ptr->color[RED];
  color.g = ptr->color[GREEN];
  color.b = ptr->color[BLUE];
  if ((TTF_Init()) == -1)
    return (EXIT_FAILURE);
  if ((police = TTF_OpenFont("./clips/font/1.ttf", 7)) == NULL)
    return (EXIT_FAILURE);
  txt = TTF_RenderText_Blended(police, "x", color);
  SDL_FillRect(vm->sc_mem, &ptr->p, SDL_MapRGB(vm->sc_mem->format,
					       255, 255, 255));
  SDL_BlitSurface(txt, NULL, vm->sc_mem, &ptr->p);
  TTF_CloseFont(police);
  return (EXIT_SUCCESS);
}
