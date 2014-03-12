/*
** texture_mapping.c for texture in /home/guiho_r/tek1/rt/src/obj
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun  1 11:18:32 2012 ronan guiho
** Last update Sat Jun  2 19:17:30 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "color.h"
#include "image.h"
#include "object.h"
#include "texture.h"

int		texture_mapping(t_object *obj, t_color *color, \
				double *pos, int *utils)
{
  t_mapping	tab_funct[NB_TYPE + 1];

  if (utils[0] >= 5)
    return (EXIT_FAILURE);
  tab_funct[0] = &texture_mapping_sphere;
  tab_funct[1] = &texture_mapping_plan;
  tab_funct[2] = &texture_mapping_cylindre;
  tab_funct[3] = &texture_mapping_cylindre;
  tab_funct[4] = &texture_mapping_tore;
  tab_funct[5] = NULL;
  if (utils[1] == TEXTURE)
    tab_funct[utils[0]](obj, color, pos, obj->image);
  else if (utils[1] == BUMP)
    tab_funct[utils[0]](obj, color, pos, obj->image_bump);
  else if (utils[1] == PERLIN)
    {
      tab_funct[utils[0]](obj, color, pos, NULL);
      return (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}
