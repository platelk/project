/*
** texture_normalmap.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon May 28 17:54:45 2012 ronan guiho
** Last update Tue May 29 22:06:56 2012 ronan guiho
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
  printf("Vector[X] = %f\n", vector[X]);
  printf("Vector[Y] = %f\n", vector[Y]);
  printf("Vector[Z] = %f\n", vector[Z]);
  return (EXIT_SUCCESS);
}
