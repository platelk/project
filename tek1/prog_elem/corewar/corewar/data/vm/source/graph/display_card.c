/*
** display_card.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/game
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Mar 23 11:34:46 2012 ronan guiho
** Last update Sun Mar 25 21:24:32 2012 alexis leprovost
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

int	display_card_kyle(t_vm *vm)
{
  SDL_Surface	*txt;
  TTF_Font	*police;
  static SDL_Color	color;
  SDL_Rect	pos;

  pos.x = 949;
  pos.y = 847;
  if ((police = TTF_OpenFont("./clips/font/1.ttf", 8)) == NULL)
    return (EXIT_FAILURE);
  vm->image[GAME][KYLE_CARD].pos.x = 900;
  vm->image[GAME][KYLE_CARD].pos.y = 810;
  SDL_BlitSurface(vm->image[GAME][KYLE_CARD].img, NULL, vm->sc,
		  &vm->image[GAME][KYLE_CARD].pos);
  txt = TTF_RenderText_Blended(police, vm->champ->next->prog_name, color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  pos.x = 949;
  pos.y = 863;
  txt = TTF_RenderText_Blended(police,
			       my_getstr(counter_live(vm->champ,
					 vm->champ->next->data[ID]),
					 "0123456789"), color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  TTF_CloseFont(police);
  return (EXIT_SUCCESS);
}

int	display_card_cartman(t_vm *vm)
{
  SDL_Surface	*txt;
  TTF_Font	*police;
  static SDL_Color	color;
  SDL_Rect	pos;

  pos.x = 1260;
  pos.y = 847;
  if ((police = TTF_OpenFont("./clips/font/1.ttf", 8)) == NULL)
    return (EXIT_FAILURE);
  vm->image[GAME][CARTMAN_CARD].pos.x = 1210;
  vm->image[GAME][CARTMAN_CARD].pos.y = 810;
  SDL_BlitSurface(vm->image[GAME][CARTMAN_CARD].img, NULL, vm->sc,
		  &vm->image[GAME][CARTMAN_CARD].pos);
  txt = TTF_RenderText_Blended(police, vm->champ->next->next->prog_name,
			       color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  pos.x = 1260;
  pos.y = 863;
  txt = TTF_RenderText_Blended(police,
			       my_getstr(counter_live(vm->champ,
				 vm->champ->next->next->data[ID]),
					 "0123456789"), color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  TTF_CloseFont(police);
  return (EXIT_SUCCESS);
}

int	display_card_stan(t_vm *vm)
{
  SDL_Surface	*txt;
  TTF_Font	*police;
  static SDL_Color	color;
  SDL_Rect	pos;

  pos.x = 380;
  pos.y = 847;
  if ((police = TTF_OpenFont("./clips/font/1.ttf", 8)) == NULL)
    return (EXIT_FAILURE);
  vm->image[GAME][STAN_CARD].pos.x = 330;
  vm->image[GAME][STAN_CARD].pos.y = 810;
  SDL_BlitSurface(vm->image[GAME][STAN_CARD].img, NULL, vm->sc,
		  &vm->image[GAME][STAN_CARD].pos);
  txt = TTF_RenderText_Blended(police, vm->champ->next->next->next->prog_name,
			        color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  pos.x = 380;
  pos.y = 863;
  txt = TTF_RenderText_Blended(police,
			       my_getstr(counter_live(vm->champ,
			  vm->champ->next->next->next->data[ID]),
					 "0123456789"), color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  TTF_CloseFont(police);
  return (EXIT_SUCCESS);
}
int	display_card_kenny(t_vm *vm)
{
  SDL_Surface	*txt;
  TTF_Font	*police;
  static SDL_Color	color;
  SDL_Rect	pos;

  pos.x = 699;
  pos.y = 847;
  if ((police = TTF_OpenFont("./clips/font/1.ttf", 8)) == NULL)
    return (EXIT_FAILURE);
  vm->image[GAME][KENNY_CARD].pos.x = 650;
  vm->image[GAME][KENNY_CARD].pos.y = 810;
  SDL_BlitSurface(vm->image[GAME][KENNY_CARD].img, NULL, vm->sc,
		  &vm->image[GAME][KENNY_CARD].pos);
  txt = TTF_RenderText_Blended(police, vm->champ->prog_name, color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  pos.x = 699;
  pos.y = 863;
  txt = TTF_RenderText_Blended(police,
			       my_getstr(counter_live(vm->champ,
						      vm->champ->data[ID]),
					 "0123456789"), color);
  SDL_BlitSurface(txt, NULL, vm->sc, &pos);
  TTF_CloseFont(police);
  return (EXIT_SUCCESS);
}

void	display_card_all(t_vm *vm)
{
  if (vm->nb_champ >= 1)
    display_card_kenny(vm);
  if (vm->nb_champ >= 2)
    display_card_kyle(vm);
  if (vm->nb_champ >= 3)
    display_card_cartman(vm);
  if (vm->nb_champ >= 4)
    display_card_stan(vm);
}
