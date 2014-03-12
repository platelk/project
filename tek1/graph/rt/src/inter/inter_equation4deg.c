/*
** equation4deg.c for raytracer in /home/guiho_r/tek1/rtv1/src/rendering
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Feb 20 18:14:52 2012 ronan guiho
** Last update Sat Jun  2 16:03:36 2012 ronan guiho
*/

#include <math.h>
#include <stdlib.h>

#include "my.h"
#include "tore.h"
#include "inter.h"
#include "calc.h"

int		inter_equation4deg(double *indice, double *k)
{
  double	z;
  double	compos[5];

  z = indice[1] / (2.0 * indice[0]);
  compos[A] = indice[2] / indice[0] - 3.0 * CARRE(z) / 2.0;
  compos[B] = indice[3] / indice[0] + CUBE(z) - indice[2] * z / indice[0];
  compos[C] = indice[4] / indice[0] - 3.0 * QUATRO(z) / 16.0 + \
    indice[2] * CARRE(z) / (4.0 * indice[0])		       \
    - indice[3] * z / (2.0 * indice[0]);
  compos[D] = -2.0 * CUBE(compos[A]) / 27.0 - CARRE(compos[B]) + 8.0 *
    compos[A] * compos[C] / 3.0;
  compos[C_P] = -(CARRE(compos[A]) + 12.0 * compos[C]) / 3.0;
  calcul_init_value(indice, compos, z, k);
  return (EXIT_SUCCESS);
}
