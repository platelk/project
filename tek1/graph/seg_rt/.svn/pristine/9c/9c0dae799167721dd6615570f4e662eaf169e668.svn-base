/*
** texture_bumpmap.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May 15 16:45:42 2012 ronan guiho
** Last update Wed May 30 02:46:10 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "init.h"
#include "object.h"
#include "texture.h"

#define CONST_BUMP 0.03

double		texture_bump_mapping_height(int x, int y, t_image *img, t_perlin *perlin)
{
  t_color	color;
  int		texture[2];
  double	height;

  texture[X] = x;
  texture[Y] = y;
  //texture_getcolor(img, &color, texture);
  height = 50 * perlin->perlin[y][x];
  height = wood(height);
  //  height = ((color.red + color.green + color.blue) / 3.0);
  return (height);
}

int		texture_bump_mapping(t_detail *detail, double *vector,\
				     t_perlin *perlin)
{
  double	lenght;
  int		utils[2];
  t_color	color;
  double	tangent[3][3];

  utils[0] = (int)detail->object->type;
  utils[1] = BUMP;
  texture_mapping(detail->object, &color, detail->position, utils);
  utils[0] = (texture_bump_mapping_height(detail->object->texture_pos[X] + 1, \
					    detail->object->texture_pos[Y], \
					  detail->object->image_bump, perlin) - \
		texture_bump_mapping_height(detail->object->texture_pos[X] - 1, \
					    detail->object->texture_pos[Y], \
					    detail->object->image_bump, perlin));
  utils[1] = (texture_bump_mapping_height(detail->object->texture_pos[X], \
					   detail->object->texture_pos[Y] + 1, \
					  detail->object->image_bump, perlin) - \
	       texture_bump_mapping_height(detail->object->texture_pos[X], \
					   detail->object->texture_pos[Y] - 1, \
					   detail->object->image_bump, perlin));
  vector[X] = (1.0f - CONST_BUMP) * vector[X] + CONST_BUMP * utils[0];
  vector[Y] = (1.0f - CONST_BUMP) * vector[Y] + CONST_BUMP * utils[1];
  vector[Z] = (1.0f - CONST_BUMP) * vector[Z] + CONST_BUMP * 1.0;
  return (EXIT_SUCCESS);
}
