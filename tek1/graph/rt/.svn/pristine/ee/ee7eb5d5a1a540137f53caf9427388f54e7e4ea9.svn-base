/*
** texture_map_cylindre.c for texture in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 25 16:37:16 2012 ronan guiho
** Last update Sun Jun  3 01:22:49 2012 ronan guiho
*/

#include <math.h>
#include <stdlib.h>

#include "init.h"
#include "utils.h"
#include "calc.h"
#include "image.h"
#include "texture.h"
#include "object.h"

t_global *global_thread;

int	texture_mapping_cylindre(t_object *obj, t_color *color,
				 double *old_pos, t_image *image)
{
  double	pos[3];
  int		texture[2];

  obj->position[Z] += 2000;
  modif_position(old_pos, obj, pos, INVERSE_ROTATION);
  texture[X] = ((image != NULL) ? image->size[WIDTH] : SIZE_X) * \
    atan2(pos[X], pos[Y]) / M_PI;
  texture[Y] = pos[Z];
  texture[Y] = -texture[Y] % ((image != NULL) ? image->size[HEIGHT] : SIZE_Y);
  texture[X] = -texture[X] % ((image != NULL) ? image->size[WIDTH] : SIZE_X);
  obj->texture_pos[X] = texture[X];
  obj->texture_pos[Y] = texture[Y];
  if (image != NULL)
    texture_getcolor(image, color, texture);
  obj->position[Z] -= 2000;
  return (EXIT_SUCCESS);
}
