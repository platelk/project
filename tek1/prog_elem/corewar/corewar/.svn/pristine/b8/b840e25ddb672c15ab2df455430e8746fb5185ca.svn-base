/*
** average.c for Corewaer in /home/guiho_r/tek1/corewar/data/vm/source/graph
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 25 11:04:15 2012 ronan guiho
** Last update Sun Mar 25 11:36:48 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

#define SIZE_LIGHT_I	85
#define SIZE_LIGHT_P    60

Uint8		add_value(Uint8 compo, int value)
{
  int		tmp;

  tmp = (int)compo + value;
  if (tmp > 255)
    tmp = 255;
  if (tmp < 0)
    tmp = 0;
  return ((Uint8)tmp);
}

float		average_float(float *p)
{
  int		i;
  float		s;

  i = 0;
  s = 0;
  while (i < 512)
    {
      s = s + p[i];
      i++;
    }
  return (s / 512);
}

void		treatement_sound_project(t_vm *vm, int *op, FMOD_CHANNEL *ch)
{
  float		sp[512];
  int		test;

  FMOD_Channel_GetSpectrum(ch, sp, 512, 0,
			   FMOD_DSP_FFT_WINDOW_RECT);
  test = average_float((float *)&sp) * 1200;
  if ((average_float((float *)&sp) * 20) < 0.1)
    {
      display_all(vm, 0);
      op[1] = SIZE_LIGHT_I;
      op[2] = 30 * test;
      op[3] = -30 * test;
      op[4] = -30 * test;
      filter_img(vm->sc, op);
    }
  else
    {
      display_all(vm, 1);
      op[1] = SIZE_LIGHT_P;
      op[2] = -30 * test;
      op[3] = 30 * test;
      op[4] = -30 * test;
      filter_img(vm->sc, op);
    }
}

void		fill_filter_img(SDL_Surface *sc, int *value,
				Uint8 *color, int *op)
{
  Uint32	pixel;

  while (++value[3] < value[0])
    {
      if ((value[1] + value[3]) % 2 == op[0] && (value[4] % 2) == op[0])
	{
	  pixel = get_pixel(sc, value[1] + value[3], value[2]);
	  SDL_GetRGBA(pixel, sc->format, &color[0], &color[1],
		      &color[2], &color[3]);
	  color[0] = add_value(color[0], op[2]);
	  color[1] = add_value(color[1], op[3]);
	  color[2] = add_value(color[2], op[4]);
	  pixel = SDL_MapRGBA(sc->format, color[0], color[1],
			      color[2], color[3]);
	      set_pixel(sc, value[1] + value[3], value[2], pixel);
	}
    }
}
