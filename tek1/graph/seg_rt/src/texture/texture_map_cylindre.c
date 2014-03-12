/*
** texture_map_cylindre.c for texture in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 25 16:37:16 2012 ronan guiho
** Last update Tue May 29 19:08:07 2012 ronan guiho
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
  double	rayon;
  double	pos[3];
  int		texture[2];

  //  modif_position(obj->position, obj, obj->position, INVERSE_ROTATION);
  modif_position(old_pos, obj, pos, INVERSE_ROTATION);
  obj->position[X] += global_thread->window->y_win;

  rayon = (double)((t_cylindre *)obj->son)->radius;
  texture[X] = image->size[WIDTH] * atan2(pos[X], pos[Y]) / M_PI;
  texture[Y] = pos[Z];
  texture[Y] = -texture[Y] % image->size[HEIGHT];
  texture[X] = -texture[X] % image->size[WIDTH];
  obj->texture_pos[X] = texture[X];
  obj->texture_pos[Y] = texture[Y];
  texture_getcolor(image, color, texture);

  obj->position[X] -= global_thread->window->y_win;

  //  modif_position(obj->position, obj, obj->position, INVERSE_ROTATION);
  return (EXIT_SUCCESS);;
}
