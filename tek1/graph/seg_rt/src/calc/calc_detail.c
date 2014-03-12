/*
** calc_detail.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  9 11:48:21 2012 alexis leprovost
** Last update Wed May 30 02:36:18 2012 ronan guiho
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

int
calc_detail(t_detail *detail, t_color *color, t_camera *camera, double *vector)
{
  if (detail == NULL || color == NULL || camera == NULL || vector == NULL)
    return (EXIT_FAILURE);
  calc_point(camera->position, vector, detail->position, detail->k);
  calc_color(color, detail);
  detail->normal[X] = 0.0F;
  detail->normal[Y] = 0.0F;
  detail->normal[Z] = 0.0F;
  calc_normal(camera, detail, vector, detail->normal);
  calc_perturbation(detail->object, detail->position, detail->normal);
  //  if (detail->object->image_bump != NULL)
  if (detail->object->perlin != NULL)
    texture_bump_mapping(detail, detail->normal, detail->object->perlin);
    //    texture_normal_mapping(detail, detail->normal);
  return (EXIT_SUCCESS);
}
