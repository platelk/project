/*
** calc_equation4deg.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun  1 00:41:11 2012 alexis leprovost
** Last update Sat Jun  2 16:06:19 2012 ronan guiho
*/

#include <math.h>
#include <stdlib.h>

#include "my.h"
#include "tore.h"
#include "inter.h"

double		calcul_solution_smallest(double *solution)
{
  if (solution[0] >= 0.0 && (solution[0] < solution[1]) && \
      (solution[0] < solution[2]) && (solution[0] < solution[3]))
    return (solution[0]);
  else if (solution[1] >= 0.0 && (solution[1] < solution[0]) && \
      (solution[1] < solution[2]) && (solution[1] < solution[3]))
    return (solution[1]);
  else if (solution[2] >= 0.0 && (solution[2] < solution[0]) && \
      (solution[2] < solution[1]) && (solution[2] < solution[3]))
    return (solution[2]);
  else if (solution[3] >= 0.0 && (solution[3] < solution[0]) && \
      (solution[3] < solution[1]) && (solution[3] < solution[2]))
    return (solution[3]);
  return (-0.001);
}

double		calcul_solution_4deg_pt2(double *solution, double *compos,
					 double *part_value, double *k)
{
  double	part1;
  double	part2;
  double	delta_2;

  delta_2 = pow(part_value[R], 2.0) - 2.0 * part_value[T] + 4.0 * \
    part_value[S];
  part1 = part_value[R] / 2.0;
  if (compos[B] > 0)
    part1 = -part1;
  part2 = sqrt(fabs(delta_2)) / 2.0;
  if (delta_2 >= 0)
    {
      solution[2] = part1 + part2 + part_value[DECAL];
      solution[3] = part1 - part2 + part_value[DECAL];
    }
  k[0] = solution[0];
  k[1] = solution[1];
  k[2] = solution[2];
  k[3] = solution[3];
  return (-0.001);
}

double		calcul_solution_4deg_pt1(double *compos, double *part_value, \
					 double *k)
{
  double	part1;
  double	part2;
  double	delta_1;

  double	solution[4];

  solution[0] = 25000;
  solution[1] = 25000;
  solution[2] = 25000;
  solution[3] = 25000;
  delta_1 = pow(part_value[R], 2) - 2.0 * \
    part_value[T] - 4.0 * part_value[S];
  part1 = -part_value[R] / 2.0;
  part2 = sqrt(fabs(delta_1)) / 2.0;
  if (compos[B] > 0)
    part1 = -part1;
  if (delta_1 >= 0)
    {
      solution[0] = part1 + part2 + part_value[DECAL];
      solution[1] = part1 - part2 + part_value[DECAL];
    }
  return (calcul_solution_4deg_pt2(solution, compos, part_value, k));
}

double		calcul_part_value(double *indice, double *compos,
				  double *init_val, double *k)
{
  double	part_value[4];

  part_value[T] = compos[A] / 3.0 + init_val[U];
  part_value[R] = sqrt(part_value[T] - compos[A]);
  part_value[S] = sqrt(CARRE(part_value[T] / 2.0) - compos[C]);
  part_value[DECAL] = -indice[1] / (4.0 * indice[0]);
  return (calcul_solution_4deg_pt1(compos, part_value, k));
}

double		calcul_init_value(double *indice, double *compos, double z, \
				  double *k)
{
  double	init_val[4];

  init_val[U] = 0;
  init_val[Z_D] = z;
  init_val[DELTA_T] = CUBE(compos[C_P] / 3.0) + CARRE(compos[D] / 2.0);
  if (init_val[DELTA_T] > 0)
    {
      init_val[W] = cbrt(-compos[D] / 2.0 + \
			 sqrt(init_val[DELTA_T]));
      init_val[U] = init_val[W] - (compos[C_P] / 3.0) / init_val[W];
    }
  else if (init_val[DELTA_T] == 0)
    init_val[U] = 3.0 * compos[D] / compos[C_P];
  else if (init_val[DELTA_T] < 0)
    init_val[U] = 2.0 * sqrt(-compos[C_P] / 3.0) * \
      cos(acos(-compos[D] / 2 /
	       pow((-compos[C_P] / 3.0),
		   (3.0 / 2.0))) / 3.0);
  return (calcul_part_value(indice, compos, init_val, k));
}
