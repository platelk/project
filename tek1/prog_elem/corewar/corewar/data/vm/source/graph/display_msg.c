/*
** display_msg.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/graph
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sun Mar 25 17:21:49 2012 alexandre deceneux
** Last update Sun Mar 25 21:44:03 2012 alexis leprovost
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void		display_kenny_angel(t_vm *vm)
{
  FMOD_CHANNEL	*ch;

  FMOD_Channel_Stop(vm->sound[AMB][1].ch);
  FMOD_System_PlaySound(vm->sound[EVENT][KILL_KENNY].sys, FMOD_CHANNEL_FREE,
			vm->sound[EVENT][KILL_KENNY].sound, 0, &ch);
  vm->image[GAME][KENNY_ANGEL].pos.x = 570;
  vm->image[GAME][KENNY_ANGEL].pos.y = 400;
  vm->nb_champ = 0;
  while (vm->image[GAME][KENNY_ANGEL].pos.y > 220)
    {
      display_all(vm, 0);
      SDL_BlitSurface(vm->image[GAME][KENNY_ANGEL].img, NULL, vm->sc,
		      &vm->image[GAME][KENNY_ANGEL].pos);
      vm->image[GAME][KENNY_ANGEL].pos.y =
	vm->image[GAME][KENNY_ANGEL].pos.y - 2;
      SDL_Flip(vm->sc);
    }
}

void		display_cartman_leave(t_vm *vm)
{
  FMOD_CHANNEL	*ch;

  FMOD_Channel_Stop(vm->sound[AMB][1].ch);
  FMOD_System_PlaySound(vm->sound[EVENT][CARTMAN_LEAVE].sys, FMOD_CHANNEL_FREE,
			vm->sound[EVENT][CARTMAN_LEAVE].sound, 0, &ch);
  vm->image[GAME][CARTMAN_FRONT].pos.x = 535;
  vm->image[GAME][CARTMAN_FRONT].pos.y = 750;
  vm->nb_champ = 0;
  while (vm->image[GAME][CARTMAN_FRONT].pos.x < 1250)
    {
      display_all(vm, 0);
      SDL_BlitSurface(vm->image[GAME][CARTMAN_FRONT].img, NULL, vm->sc,
		      &vm->image[GAME][CARTMAN_FRONT].pos);
      vm->image[GAME][CARTMAN_FRONT].pos.x =
	vm->image[GAME][CARTMAN_FRONT].pos.x + 4;
      SDL_Flip(vm->sc);
    }
}

int		key_msg_end(t_vm *vm)
{
  SDL_Event	event;

  SDL_WaitEvent(&event);
  if (event.type == SDL_QUIT)
    exit (1);
  if (event.type == SDL_MOUSEBUTTONUP)
    if (event.button.button == SDL_BUTTON_LEFT)
      {
	if ((event.button.x >= 672 && event.button.x <= 830) &&
	    (event.button.y >= 571 && event.button.y <= 657))
	  {
	    vm->nb_champ = 0;
	    display_kenny_angel(vm);
	    return (1);
	  }
	if ((event.button.x >= 868 && event.button.x <= 1024) &&
	    (event.button.y >= 571 && event.button.y <= 659))
	  {
	    vm->nb_champ = 0;
	    display_cartman_leave(vm);
	    return (1);
	  }
      }
  return (0);
}

int		display_loop_msg_end(t_vm *vm)
{
  while (42)
    {
      if ((key_msg_end(vm)) == 1)
	{
	  display_credit(vm);
	  return (1);
	}
      SDL_Flip(vm->sc);
    }
  return (0);
}
int		display_msg(t_vm *vm)
{
  SDL_Surface	*txt;
  SDL_Rect	p;
  TTF_Font	*police;
  static SDL_Color	color;

  pthread_cancel(vm->thread);
  display_all(vm, 0);
  if ((police = TTF_OpenFont("./clips/font/0.ttf", 37)) == NULL)
    return (EXIT_FAILURE);
  p.x = 635;
  p.y = 353;
  vm->image[GAME][MSG_KENNY].pos.x = 600;
  vm->image[GAME][MSG_KENNY].pos.y = 330;
  SDL_BlitSurface(vm->image[GAME][MSG_KENNY].img, NULL, vm->sc,
		  &vm->image[GAME][MSG_KENNY].pos);
  if (vm->winner != NULL && vm->no_graph != EXIT_FAILURE)
    txt = TTF_RenderText_Blended(police,
				 my_str_concat(my_str_concat("Le joueur ", \
				 vm->winner->prog_name), " a gagne"), color);
  SDL_BlitSurface(txt, NULL, vm->sc, &p);
  SDL_Flip(vm->sc);
  display_loop_msg_end(vm);
  return (0);
}
