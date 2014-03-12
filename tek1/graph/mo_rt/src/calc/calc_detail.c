/*
** calc_detail.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  9 11:48:21 2012 alexis leprovost
** Last update Wed May 30 15:30:56 2012 ronan guiho
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"perlin_noise.h"
#include	"raytracer.h"
#include        "texture.h"
#include	"global.h"
#include	"detail.h"
#include	"color.h"
#include	"calc.h"
#include	"normal.h"
#include	"my.h"
#include	"utils.h"

int
calc_detail(t_detail *detail, t_color *color, t_camera *camera, double *vector)
{
  if (detail == NULL || color == NULL || camera == NULL || vector == NULL)
    return (EXIT_FAILURE);
  calc_point(camera->position, vector, detail->position, detail->k);
  calc_color(color, detail);
  calc_normal(camera, detail, vector, detail->normal);
  calc_perturbation(detail->object, detail->position, detail->normal);
  if ((detail->object->image_bump != NULL && detail->object->image_bump->type == B_BUMP) ||
      (detail->object->perlin != NULL && (detail->object->perlin->apply == APP_BUMP ||
					  detail->object->perlin->apply == APP_BUMP_TEXT)))
    texture_bump_mapping(detail, detail->normal);
  else if (detail->object->image_bump != NULL && detail->object->image_bump->type == B_NORMAL)
    texture_normal_mapping(detail, detail->normal);
  return (EXIT_SUCCESS);
}
