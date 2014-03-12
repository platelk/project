/*
** projector.c for Corewar in /home/guiho_r//tek1/MaskSDL
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 21 17:45:17 2012 ronan guiho
** Last update Sun Mar 25 20:59:20 2012 ronan guiho
*/

#include <stdlib.h>
#include <pthread.h>

#include "vm.h"
#include "corewar.h"

#define REFRESH		20
#define CENTER_X	840
#define CENTER_Y	150
#define SIZE_LIGHT_I	85
#define SIZE_LIGHT_P    60

Uint32		get_pixel(SDL_Surface *sc, int x, int y)
{
  int		nOctet;
  Uint8		*p;

  nOctet = sc->format->BytesPerPixel;
  p = (Uint8 *)sc->pixels + y * sc->pitch + x * nOctet;
  if (nOctet == 1)
    return (*p);
  else if (nOctet == 2)
    return (*(Uint16 *)p);
  else if (nOctet == 3)
    {
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	return p[0] << 16 | p[1] << 8 | p[2];
      else
	return p[0] | p[1] << 8 | p[2] << 16;
    }
  else if (nOctet == 4)
    return (*(Uint32 *)p);
  else
    return (0);
}

void		set_pixel_suite(int nOctet, Uint8 *p, Uint32 pixel)
{
  if (nOctet == 3)
    {
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
	  p[0] = (pixel >> 16) & 0xff;
	  p[1] = (pixel >> 8) & 0xff;
	  p[2] = pixel & 0xff;
	}
      else
	{
	  p[0] = pixel & 0xff;
	  p[1] = (pixel >> 8) & 0xff;
	  p[2] = (pixel >> 16) & 0xff;
	}
    }
  else if (nOctet == 4)
    *(Uint32 *)p = pixel;
}

void		set_pixel(SDL_Surface *sc, int x, int y, Uint32 pixel)
{
  int nOctet;
  Uint8 *p;

  nOctet = sc->format->BytesPerPixel;
  p = (Uint8 *)sc->pixels + y * sc->pitch + x * nOctet;
  if (nOctet == 1)
    *p = pixel;
  else if (nOctet == 2)
    *(Uint16 *)p = pixel;
  set_pixel_suite(nOctet, p, pixel);
}

int		filter_img(SDL_Surface *sc, int *op)
{
  int		*value;
  Uint8		*color;

  if ((value = malloc(sizeof(int) * 4)) == NULL)
    return (1);
  if ((color = malloc(sizeof(Uint8) * 5)) == NULL)
    return (1);
  value[4] = -1;
  value[0] = 1;
  value[1] = CENTER_X;
  value[2] = CENTER_Y;
  while (++value[4] < op[1])
    {
      value[3] = -1;
      fill_filter_img(sc, value, color, op);
      value[0] = value[0] + 8;
      value[1] = value[1] - 4;
      value[2]++;
    }
  return (0);
}

void		*thread_projector(void *ptr)
{
  int		*op;
  int		time[2];
  t_vm		*vm;
  FMOD_CHANNEL	*ch;

  vm = (t_vm *)ptr;
  if ((op = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  op[0] = 0;
  FMOD_System_PlaySound(vm->sound[AMB][1].sys, FMOD_CHANNEL_FREE,
			vm->sound[AMB][1].sound, 0, &ch);
  vm->sound[AMB][1].ch = ch;
  time[0] = 0;
  time[1] = 0;
  while (42)
    {
      time[0] = SDL_GetTicks();
      if ((time[0] - time[1]) < REFRESH)
	SDL_Delay(REFRESH - (time[0] - time[1]));
      time[1] = SDL_GetTicks();
      treatement_sound_project(vm, op, ch);
      op[0] = (op[0] == 0) ? 1 : 0;
      SDL_Flip(vm->sc);
    }
  return (NULL);
}
