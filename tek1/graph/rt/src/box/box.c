/*
** box.c for box in /home/ozouf_h//rt/src/box
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May 15 14:24:45 2012 harold ozouf
** Last update Sun Jun  3 17:56:12 2012 harold ozouf
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"object.h"
#include	"box.h"

void	init_box(t_object *o)
{
  t_object	*tmp;

  tmp = o;
  while (tmp)
    {
      if (tmp->type == SPHERE)
	init_b_sphere(tmp);
      else if (tmp->type == TORE)
	init_b_tore(tmp);
      else
	init_b_inf(tmp);
      tmp = tmp->next;
    }
}

int	inter_ray_box_n(double *min, double *max)
{
  if ((min[X] > max[Y]) || (min[Y] > max[X]))
    return (0);
  if (min[Y] > min[X])
    min[X] = min[Y];
  if (max[Y] < max[X])
    max[X] = max[Y];
  if ((min[X] > max[Z]) || (min[Z] > max[X]))
    return (0);
  if (min[Z] > min[X])
    min[X] = min[Z];
  if (max[Z] < max[X])
    max[X] = max[Z];
  return (1);
}

int	inter_ray_box(t_camera *c, double *vec, t_object *o)
{
  double	max[3];
  double	min[3];
  double       	offset;
  int		i;

  i = -1;
  if (o->box_size[X] == -1)
    return (1);
  while (++i < 3)
    {
      offset = (vec[i] == 0.00000) ? (0.00001) : (0);
      if (vec[i] >= 0.0)
	{
	  min[i] = (o->box_pos[i] - c->position[i]) / (vec[i] + offset);
	  max[i] = (o->box_pos[i] + o->box_size[i] - c->position[i])
	    / (vec[i] + offset);
	}
      else
	{
	  max[i] = (o->box_pos[i] - c->position[i]) / vec[i];
	  min[i] = (o->box_pos[i] + o->box_size[i] - c->position[i]) / vec[i];
	}
    }
  return (inter_ray_box_n(min, max));
}
