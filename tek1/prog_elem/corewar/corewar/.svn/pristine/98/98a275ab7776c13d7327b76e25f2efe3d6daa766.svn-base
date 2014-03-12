/*
** menu.c for corewar in /home/guiho_r/tek1/corewar/source/VM/image
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar  8 00:02:31 2012 ronan guiho
** Last update Sun Mar 25 21:51:58 2012 alexis leprovost
*/

#include <unistd.h>
#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

int		key_left_button(SDL_Event event, FMOD_CHANNEL *channel,
				t_sound **sound_tab)
{
  double       volume;

  volume = 1.0;
  if (event.type == SDL_MOUSEBUTTONUP)
    if (event.button.button == SDL_BUTTON_LEFT)
      {
	if ((event.button.x >= 75 && event.button.x <= 450) &&
	    (event.button.y >= 80 && event.button.y <= 236))
	  {
	    while (volume >= 0.0)
	      {
		FMOD_Channel_SetVolume(channel, volume);
		volume = volume - 0.05;
		usleep(150000);
	      }
	    FMOD_Channel_SetVolume(channel, volume);

	    return (-1);
	  }
	if ((event.button.x >= 75 && event.button.x <= 450) &&
	    (event.button.y >= 318 && event.button.y <= 455))
	  exit (1);
	hello_sound(event, sound_tab);
      }
  return (EXIT_SUCCESS);
}

int		key_menu_exit(SDL_Surface *sc, t_image *image_tab,
			      SDL_Event event)
{
  if ((event.button.x >= 75 && event.button.x <= 450) &&
      (event.button.y >= 318 && event.button.y <= 455))
    SDL_BlitSurface(image_tab[BUTTON_EX_HOLD].img, NULL,
		    sc, &image_tab[BUTTON_EX_HOLD].pos);
  else
    SDL_BlitSurface(image_tab[BUTTON_EX_ON].img, NULL,
		    sc, &image_tab[BUTTON_EX_ON].pos);
  return (EXIT_SUCCESS);
}
int		key_menu(SDL_Surface *sc, t_image *image_tab,
			 FMOD_CHANNEL *channel, t_sound **sound_tab)
{
  SDL_Event	event;

  SDL_WaitEvent(&event);
  if (event.type == SDL_QUIT)
    exit (1);
  if (event.type == SDL_MOUSEMOTION)
    {
      if ((event.button.x >= 75 && event.button.x <= 450) &&
	  (event.button.y >= 80 && event.button.y <= 236))
	SDL_BlitSurface(image_tab[BUTTON_HOLD].img, NULL,
			sc, &image_tab[BUTTON_HOLD].pos);
      else
	SDL_BlitSurface(image_tab[BUTTON_ON].img, NULL,
			sc, &image_tab[BUTTON_ON].pos);
      key_menu_exit(sc, image_tab, event);
    }
  if ((key_left_button(event, channel, sound_tab)) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}

int		loop_display_menu(SDL_Surface *sc, FMOD_CHANNEL *channel,
				  t_image *image_tab, t_sound **sound_tab)
{
  while (42)
    {
      if ((key_menu(sc, image_tab, channel, sound_tab)) == -1)
	return (-1);
      SDL_Flip(sc);
    }
  return (EXIT_SUCCESS);
}
int		display_menu(SDL_Surface *sc, t_image *image_tab,
			     t_sound **sound_tab)
{
  FMOD_CHANNEL *channel;

  image_tab[BACK].pos.x = 0;
  image_tab[BACK].pos.y = 0;
  image_tab[BUTTON_ON].pos.x = X_BUTTON_START;
  image_tab[BUTTON_ON].pos.y = Y_BUTTON_START;
  image_tab[BUTTON_HOLD].pos.x = X_BUTTON_START;
  image_tab[BUTTON_HOLD].pos.y = Y_BUTTON_START;
  image_tab[BUTTON_EX_ON].pos.x = X_BUTTON_EXIT;
  image_tab[BUTTON_EX_ON].pos.y = Y_BUTTON_EXIT;
  image_tab[BUTTON_EX_HOLD].pos.x = X_BUTTON_EXIT;
  image_tab[BUTTON_EX_HOLD].pos.y = Y_BUTTON_EXIT;
  SDL_BlitSurface(image_tab[BACK].img, NULL, sc, &image_tab[BACK].pos);
  SDL_BlitSurface(image_tab[BUTTON_ON].img, NULL,
		  sc, &image_tab[BUTTON_ON].pos);
  SDL_BlitSurface(image_tab[BUTTON_EX_ON].img, NULL,
		  sc, &image_tab[BUTTON_EX_ON].pos);
  FMOD_System_PlaySound(sound_tab[AMB][0].sys, FMOD_CHANNEL_FREE,
			sound_tab[AMB][0].sound, 0, &channel);
FMOD_Channel_SetVolume(channel, 0.3);
  loop_display_menu(sc, channel, image_tab, sound_tab);
  return (0);
}
