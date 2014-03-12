/*
** texture_map_plan.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May 16 10:44:38 2012 ronan guiho
** Last update Sun Jun  3 17:57:39 2012 harold ozouf
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "calc.h"
#include "image.h"
#include "texture.h"
#include "object.h"

double u;
double v;

int		texture_mapping_plan(t_object *obj, t_color *color,
				     double *old_pos, t_image *image)
{
  double	pos[3];
  int		texture[2];

  modif_vector(obj->rotation, old_pos, pos, INVERSE_ROTATION);
  texture[X] = (int)(pos[X] * ((image != NULL) ? image->freq : \
			       obj->perlin->freq) + \
		     ((image != NULL) ? image->size[WIDTH] : SIZE_X) / 2.0);
  texture[Y] = (int)(pos[Y] * ((image != NULL) ? image->freq : \
			       obj->perlin->freq) + \
		     ((image != NULL) ? image->size[HEIGHT] : SIZE_Y) / 2.0);
  while (texture[X] < 0)
    texture[X] = texture[X] + (100 * ((image != NULL) ? image->size[WIDTH] : \
				      SIZE_X));
  while (texture[Y] < 0)
    texture[Y] = texture[Y] + (100 * ((image != NULL) ? image->size[HEIGHT] : \
				      SIZE_Y));
  texture[X] = texture[X] % ((image != NULL) ? image->size[WIDTH] : SIZE_X);
  texture[Y] = texture[Y] % ((image != NULL) ? image->size[HEIGHT] : SIZE_Y);
  obj->texture_pos[X] = texture[X];
  obj->texture_pos[Y] = texture[Y];
  if (image != NULL)
    texture_getcolor(image, color, texture);
  return (EXIT_SUCCESS);
}
