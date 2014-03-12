/*
** texture_bumpmap.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May 15 16:45:42 2012 ronan guiho
** Last update Fri Jun  1 13:16:38 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "init.h"
#include "object.h"
#include "texture.h"

#define CONST_BUMP 0.030

double		texture_bump_mapping_height(int x, int y, t_object *obj)
{
  t_color	color;
  int		texture[2];
  double	height;

  texture[X] = x;
  texture[Y] = y;
  if (obj->image_bump != NULL)
    texture_getcolor(obj->image_bump, &color, texture);
  if (obj->perlin != NULL && (obj->perlin->apply == APP_BUMP || \
			      obj->perlin->apply == APP_BUMP_TEXT))
    {
      height = obj->perlin->perlin[y][x];
      color.red = (obj->perlin->begin->red * (1.0 - height) + \
		   obj->perlin->end->red * height);
      color.green = (obj->perlin->begin->green * (1.0 - height) + \
		     obj->perlin->end->green * height);
      color.blue = (obj->perlin->begin->blue * (1.0 - height) + \
		    obj->perlin->end->blue * height);
      height = ((color.red + color.green + color.blue) / 3.0);
    }
  else
    height = ((color.red + color.green + color.blue) / 3.0);
  return (height);
}

int		texture_bump_mapping_X(t_detail *detail, double *vector, int *utils)
{
  vector[X] = (1.0f - ((detail->object->perlin != NULL && \
			(detail->object->perlin->apply == APP_BUMP ||
			 detail->object->perlin->apply == APP_BUMP_TEXT)) ? \
		       detail->object->perlin->relief : \
		       detail->object->image_bump->relief)) * vector[X] + \
    ((detail->object->perlin != NULL && \
      (detail->object->perlin->apply == APP_BUMP || \
       detail->object->perlin->apply == APP_BUMP_TEXT)) ? \
     detail->object->perlin->relief : \
     detail->object->image_bump->relief) * utils[0];
  return (EXIT_SUCCESS);
}

int		texture_bump_mapping_Y(t_detail *detail, double *vector, int *utils)
{
  vector[Y] = (1.0f - ((detail->object->perlin != NULL && \
			(detail->object->perlin->apply == APP_BUMP ||
			 detail->object->perlin->apply == APP_BUMP_TEXT)) ? \
		       detail->object->perlin->relief : \
		       detail->object->image_bump->relief)) * vector[Y] + \
    ((detail->object->perlin != NULL && \
      (detail->object->perlin->apply == APP_BUMP || \
       detail->object->perlin->apply == APP_BUMP_TEXT)) ? \
     detail->object->perlin->relief : \
     detail->object->image_bump->relief) * utils[1];
  return (EXIT_SUCCESS);
}

int		texture_bump_mapping_Z(t_detail *detail, double *vector)
{
   vector[Z] = (1.0f - ((detail->object->perlin != NULL && \
			 (detail->object->perlin->apply == APP_BUMP || \
			  detail->object->perlin->apply == APP_BUMP_TEXT)) ? \
			detail->object->perlin->relief : \
			detail->object->image_bump->relief)) * vector[Z] + \
     ((detail->object->perlin != NULL && \
       (detail->object->perlin->apply == APP_BUMP || \
	detail->object->perlin->apply == APP_BUMP_TEXT)) ? \
      detail->object->perlin->relief : \
      detail->object->image_bump->relief) * 1.0;
  return (EXIT_SUCCESS);
}

int		texture_bump_mapping(t_detail *detail, double *vector)
{
  int		utils[2];
  t_color	color;

  utils[0] = (int)detail->object->type;
  utils[1] = BUMP;
  texture_mapping(detail->object, &color, detail->position, utils);
  utils[0] = (texture_bump_mapping_height(detail->object->texture_pos[X] + 1, \
					    detail->object->texture_pos[Y], \
					  detail->object) - \
		texture_bump_mapping_height(detail->object->texture_pos[X] - 1, \
					    detail->object->texture_pos[Y], \
					    detail->object));
  utils[1] = (texture_bump_mapping_height(detail->object->texture_pos[X], \
					   detail->object->texture_pos[Y] + 1, \
					  detail->object) - \
	       texture_bump_mapping_height(detail->object->texture_pos[X], \
					   detail->object->texture_pos[Y] - 1, \
					   detail->object));
  texture_bump_mapping_X(detail, vector, utils);
  texture_bump_mapping_Y(detail, vector, utils);
  texture_bump_mapping_Z(detail, vector);
  return (EXIT_SUCCESS);
}
