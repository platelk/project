/*
** calc_procedural.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun  1 12:38:39 2012 alexis leprovost
** Last update Sat Jun  2 18:51:21 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"global.h"
#include	"raytracer.h"
#include	"procedural.h"

static void
apply_color(t_color *init, t_color *tmp)
{
  init->red = tmp->red;
  init->green = tmp->green;
  init->blue = tmp->blue;
}

int	calc_procedural(t_procedural *procedural, double *position,
			t_color *color)
{
  int	p[NB_DIMENSION];

  if (procedural->c1 == NULL || procedural->c2 == NULL || !procedural->size)
    return (EXIT_FAILURE);
  p[X] = (int)ABS(((int)position[X] / procedural->size)) % 2;
  p[X] = position[X] < 0.0F ? !p[X] : p[X];
  p[Y] = (int)ABS(((int)position[Y] / procedural->size)) % 2;
  p[Y] = position[Y] < 0.0F ? !p[Y] : p[Y];
  p[Z] = (int)ABS(((int)position[Z] / procedural->size)) % 2;
  p[Z] = position[Z] < 0.0F ? !p[Z] : p[Z];
  if (p[Z])
    {
      if ((p[X] && p[Y]) || (!p[X] && !p[Y]))
	apply_color(color, procedural->c1);
      else
	apply_color(color, procedural->c2);
    }
  else
    {
      if ((p[X] && p[Y]) || (!p[X] && !p[Y]))
	apply_color(color, procedural->c2);
      else
	apply_color(color, procedural->c1);
    }
  return (EXIT_SUCCESS);
}
