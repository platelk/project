/*
** texture_normalmap.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon May 28 17:54:45 2012 ronan guiho
** Last update Wed May 30 14:04:32 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "init.h"
#include "object.h"
#include "texture.h"

int		texture_normal_mapping(t_detail *detail, double *vector)
{
  t_color	color;
  int		utils[2];

  utils[0] = (int)detail->object->type;
  utils[1] = BUMP;
  texture_mapping(detail->object, &color, detail->position, utils);
  vector[X] = color.red;
  vector[Y] = color.green;
  vector[Z] = color.blue;
   return (EXIT_SUCCESS);
}
