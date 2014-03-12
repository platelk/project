/*
** calc_angle.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 10 14:08:22 2012 alexis leprovost
** Last update Sun Jun  3 05:33:39 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<math.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"moebus.h"
#include	"calc.h"
#include	"utils.h"

double	calc_angle(double *u, double *v)
{
  double	ps;
  double	n1;
  double	n2;
  double	angle;

  if (u == NULL || v == NULL)
    return (0.001F);
  angle = 0.0F;
  ps = calc_ps(v, u);
  n1 = calc_norme(u);
  n2 = calc_norme(v);
  if (!EQUALZERO(ps) && !EQUALZERO(n1) && !EQUALZERO(n2))
    angle = ps / (n1 * n2);
  angle = angle < 0.0000001 ? 0.00000 : angle;
  return (angle);
}
