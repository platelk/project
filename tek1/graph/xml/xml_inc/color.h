/*
** color.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 15:12:29 2012 alexis leprovost
** Last update Mon May  7 10:08:16 2012 alexis leprovost
*/

#ifndef __COLOR_H__
#define __COLOR_H__

typedef struct s_color
{
  double	red;
  double	green;
  double	blue;
} t_color;

int	restat_color(t_color *color);
int	add_color(t_color *c1, t_color *c2);

#endif
