/*
** init_box.c for init_box in /home/ozouf_h//rt/src/box
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May 15 14:36:04 2012 harold ozouf
** Last update Sun Jun  3 17:56:29 2012 harold ozouf
*/

#include	<stdio.h>
#include	"box.h"

void	init_b_sphere(t_object *o)
{
  int	i;

  i = -1;
  while (++i < 3)
    o->box_pos[i] = o->position[i] - ((t_sphere *)o->son)->radius;
  i = -1;
  while (++i < 3)
    o->box_size[i] = ((t_sphere *)o->son)->radius * 2.0;
}

void	init_b_tore(t_object *o)
{
  int	i;

  i = -1;
  while (++i < 3)
    o->box_pos[i] = o->position[i]
      - (((t_tore *)o->son)->radius[1] + ((t_tore *)o->son)->radius[0]);
  i = -1;
  while (++i < 3)
    o->box_size[i] = 2 *
      (((t_tore *)o->son)->radius[1] + ((t_tore *)o->son)->radius[0]);
}

void	init_b_inf(t_object *o)
{
  int	i;

  i = -1;
  while (++i < 3)
    o->box_pos[i] = 0;
  i = -1;
  while (++i < 3)
    o->box_size[i] = -1;
}
