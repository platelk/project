/*
** perlin_texture.c for perlin in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May 15 17:27:59 2012 ronan guiho
** Last update Fri Jun  1 00:14:09 2012 alexis leprovost
*/

#include <math.h>
#include <stdlib.h>

#include "init.h"
#include "perlin_noise.h"
#include "utils.h"
#include "calc.h"
#include "image.h"
#include "texture.h"
#include "object.h"

int		perlin_texture(t_object *obj, t_perlin *perlin,
			       t_color *color, double *old_pos)
{
  double	value;
  int		utils[2];

  utils[0] = (int)obj->type;
  utils[1] = PERLIN;
  texture_mapping(obj, NULL, old_pos, utils);
  value = perlin->perlin[obj->texture_pos[Y]][obj->texture_pos[X]];
  if (obj->perlin->effect == MARBLE)
    value = marble(value);
  else if (obj->perlin->effect == WOOD)
    value = wood(value);
  color->red = (perlin->begin->red * (1.0 - value)	\
		+ perlin->end->red * value);
  color->green = (perlin->begin->green * (1.0 - value)	\
		  + perlin->end->green * value);
  color->blue = (perlin->begin->blue * (1.0 - value)	\
		 + perlin->end->blue * value);
  return (EXIT_SUCCESS);
}
