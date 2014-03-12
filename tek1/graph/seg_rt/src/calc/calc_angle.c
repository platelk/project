/*
** calc_angle.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 10 14:08:22 2012 alexis leprovost
** Last update Sat May 26 14:11:00 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"calc.h"

double	calc_angle(double *u, double *v)
{
  double	ps;
  double	n1;
  double	n2;
  double	angle;

  if (u == NULL || v == NULL)
    return (0.0F);
  angle = 0.0F;
  ps = calc_ps(u, v);
  n1 = calc_norme(u);
  n2 = calc_norme(v);
  if (ps != 0 && n1 != 0 && n2 != 0)
    angle = ps / (n1 * n2);
  angle = angle < 0.000 ? 0.000 : angle;
  return (angle);
}
