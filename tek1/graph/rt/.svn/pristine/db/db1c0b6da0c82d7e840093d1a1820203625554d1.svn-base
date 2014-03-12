/*
** obj_create_cube_plan.c for obj in /home/guiho_r/tek1/rt/src/obj
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 06:23:55 2012 ronan guiho
** Last update Sun Jun  3 06:31:50 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "object.h"
void		obj_create_cube_plan_assigne_suite(t_object *tmp, t_limit *limit,
						   double size)
{
  tmp = tmp->next;
  tmp->position[Y] += -size;
  tmp->rotation[X] += -90;
  tmp->color->red = 255.0;
  tmp->color->green = 255.0;
  tmp->color->blue = 0.0;
  tmp->limit = limit;
  tmp = tmp->next;
  tmp->position[X] += size;
  tmp->rotation[Y] += 90;
  tmp->color->red = 60.0;
  tmp->color->green = 100.0;
  tmp->color->blue = 200.0;
  tmp->limit = limit;
  tmp = tmp->next;
}
t_object	*obj_create_cube_plan_assigne(t_object *list, t_limit *limit,
					      double size)
{
  t_object	*tmp;

  tmp = list;
  tmp->position[Z] += -size;
  tmp->color->red = 255.0;
  tmp->color->green = 0.0;
  tmp->color->green = 0.0;
  tmp->limit = limit;
  tmp = tmp->next;
  tmp->position[Z] += size;
  tmp->color->red = 0.0;
  tmp->color->green = 255.0;
  tmp->color->blue = 0.0;
  tmp->limit = limit;
  tmp = tmp->next;
  tmp->position[Y] += size;
  tmp->rotation[X] += 90;
  tmp->color->red = 0.0;
  tmp->color->green = 255.0;
  tmp->color->blue = 255.0;
  tmp->limit = limit;
  obj_create_cube_plan_assigne_suite(tmp, limit, size);
  return (list);
}

t_object	*obj_create_cube_plan(t_object *obj)
{
  int		i;
  t_object	*list;
  double	size;
  t_limit	*limit;

  i = -1;
  size = (double)((t_cube *)obj->son)->size;
  list = NULL;
  if ((limit = malloc(sizeof(*limit))) == NULL)
    return (NULL);
  limit->flag = 0;
  limit->flag |= MIN_X | MAX_X | MIN_Y | MAX_Y;
  limit->x[0] = -size;
  limit->x[1] = size;
  limit->y[0] = -size;
  limit->y[1] = size;
  limit->z[0] = 0.0;
  limit->z[1] = 0.0;
  while (++i < 5)
    obj_duplique(&list, obj, size);
  return (obj_create_cube_plan_assigne(list, limit, size));
}
