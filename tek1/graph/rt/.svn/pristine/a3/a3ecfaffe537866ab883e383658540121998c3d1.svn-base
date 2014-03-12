/*
** texture_map_tore.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May 27 15:56:02 2012 ronan guiho
** Last update Fri Jun  1 11:24:51 2012 ronan guiho
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "utils.h"
#include "calc.h"
#include "image.h"
#include "texture.h"
#include "object.h"

#define TWO_M_PI (2.0 * M_PI)

int		texture_mapping_tore(t_object *obj, t_color *color,
				     double *old_pos, t_image *image)
{
  double	radius[2];
  double	utils[3];
  int		texture[2];
  double	pos[3];

  radius[MIN] = (double)((t_tore *)obj->son)->radius[MIN];
  radius[MAX] = (double)((t_tore *)obj->son)->radius[MAX];
  modif_position(old_pos, obj, pos, INVERSE_ROTATION);
  utils[0] = (1.0 - (atan2(pos[Z], pos[X]) + M_PI) / TWO_M_PI) * \
    image->size[WIDTH];
  utils[2] = sqrt(pos[X] * pos[X] + pos[Z] * pos[Z]);
  pos[X] = utils[2] - radius[MAX];
  utils[1] = ((atan2(pos[Y], pos[X]) + M_PI) / TWO_M_PI) * \
    image->size[HEIGHT];
  texture[X] = (int)utils[0];
  texture[Y] = (int)utils[1];
  obj->texture_pos[X] = texture[X];
  obj->texture_pos[Y] = texture[Y];
  texture_getcolor(image, color, texture);
  return (EXIT_SUCCESS);
}
