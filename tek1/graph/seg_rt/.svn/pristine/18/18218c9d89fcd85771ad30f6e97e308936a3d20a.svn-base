/*
** box.c for box in /home/ozouf_h//rt/src/box
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May 15 14:24:45 2012 harold ozouf
** Last update Wed May 16 15:49:42 2012 harold ozouf
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"object.h"
#include	"box.h"

void	init_ptr_funct_box(t_init_boxes *b)
{
  b[0] = &init_b_sphere;
  b[1] = &init_b_inf;
  b[2] = &init_b_inf;
  b[3] = &init_b_inf;
  b[4] = &init_b_tore;
}

void	init_box(t_object *o)
{
  t_init_boxes	init_o[5];

  init_ptr_funct_box(init_o);
  while (o)
    {
      init_o[o->type](o);
      o = o->next;
    }
}

int     inter_box_box(t_object *b1, t_object *b2)
{
  if((b2->box_pos[X] >= b1->box_pos[X] + b1->box_size[X])
     || (b2->box_pos[X] + b2->box_size[X] <= b1->box_pos[X])
     || (b2->box_pos[Y] >= b1->box_pos[Y] + b1->box_size[Y])
     || (b2->box_pos[Y] + b2->box_size[Y] <= b1->box_pos[Y])
     || (b2->box_pos[Z] >= b1->box_pos[Z] + b1->box_size[Z])
     || (b2->box_pos[Z] + b2->box_size[Z]<= b1->box_pos[Z]))
    return (0);
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
    {
      //printf("ok inf\n");
      return (1);
    }
  while (++i < 3)
    {
      offset = (vec[i] == 0.00000) ? (0.00001) : (0);
      if (vec[i] >= 0.0)
	{
	  min[i] = (o->box_pos[i] - c->position[i]) / (vec[i] + offset);
	  max[i] = (o->box_pos[i] + o->box_size[i] - c->position[i]) / (vec[i] + offset);
	}
      else
	{
	  max[i] = (o->box_pos[i] - c->position[i]) / vec[i];
	  min[i] = (o->box_pos[i] + o->box_size[i] - c->position[i]) / vec[i];
	}
    }
  if ((min[X] > max[Y]) || (min[Y] > max[X]))
    {
      //   printf("rien\n");
      return (0);
    }
  if (min[Y] > min[X])
    min[X] = min[Y];
  if (max[Y] < max[X])
    max[X] = max[Y];
  if ((min[X] > max[Z]) || (min[Z] > max[X]))
    {
      //printf("rien\n");
      return (0);
    }
  if (min[Z] > min[X])
    min[X] = min[Z];
  if (max[Z] < max[X])
    max[X] = max[Z];
  //printf("ok\n");
  return (1);
}
