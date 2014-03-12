/*
** calc_color.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  9 18:30:44 2012 alexis leprovost
** Last update Tue May 29 17:50:34 2012 ronan guiho
*/

#include        <stdio.h>
#include	<stdlib.h>

#include	"global.h"
#include	"detail.h"
#include	"texture.h"
#include	"color.h"
#include	"object.h"

int	calc_color(t_color *color, t_detail *detail)
{
  int	utils[2];

  utils[0] = detail->object->type;
  utils[1] = TEXTURE;
  if (detail == NULL)
    return (EXIT_FAILURE);
  if (detail->object->image != NULL)
    texture_mapping(detail->object, color, detail->position, utils);
  else if (detail->object->perlin != NULL)
    perlin_texture(detail->object, detail->object->perlin, color, detail->position);
  else
    {
      color->red = detail->object->color->red;
      color->green = detail->object->color->green;
      color->blue = detail->object->color->blue;
    }
  /*  printf("Color->Object[RED] = %f\n", color->red);
  printf("Color->Object[GREEN] = %f\n", color->green);
  printf("Color->Object[BLUE] = %f\n", color->blue);*/
  return (EXIT_SUCCESS);
}
