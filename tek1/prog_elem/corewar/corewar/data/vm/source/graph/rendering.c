/*
** rendering.c for corewar in /home/guiho_r/tek1/corewar/source/VM/image
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar  8 00:07:03 2012 ronan guiho
** Last update Sun Mar 25 10:43:52 2012 ronan guiho
*/

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include "vm.h"
#include "corewar.h"

int		rendering_suite(t_vm *vm, TTF_Font *police)
{
  display_animation(vm->sc, vm->image);
  display_all(vm, 0);
  display_decompt(vm, police);
  SDL_Flip(vm->sc);
  vm->sc_mem = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH_MEM, HEIGHT_MEM - 17,
				    32, 0, 0, 0, 0);
  SDL_FillRect(vm->sc_mem, NULL, SDL_MapRGB(vm->sc_mem->format, \
					    255, 255, 255));
  if (pthread_create(&vm->thread, NULL, thread_projector, (void *)vm) < 0)
    return (1);
  return (0);
}
int		rendering(t_vm *vm)
{
  TTF_Font	*police;

  if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
    return (EXIT_FAILURE);
  if ((TTF_Init()) == -1)
    return (EXIT_FAILURE);
  if ((police = TTF_OpenFont("./clips/font/0.ttf", 280)) == NULL)
    {
      my_printf("Corewar: error: load font 0.ttf\n");
      return (EXIT_FAILURE);
    }
  create_disp_mem(vm);
  vm->sc = SDL_SetVideoMode(X_WIN, Y_WIN, 32, SDL_HWSURFACE
			    | SDL_DOUBLEBUF);
  SDL_WM_SetCaption(NAME_WIN, NULL);
  display_menu(vm->sc, vm->image[MENU_IMG], vm->sound);
  SDL_SetColorKey(vm->image[GAME][BACK_IG].img, SDL_SRCCOLORKEY,
		  SDL_MapRGB(vm->image[GAME][BACK_IG].img->format,
		       0xff, 0x00, 0xc6));
  rendering_suite(vm, police);
  return (EXIT_SUCCESS);
}
