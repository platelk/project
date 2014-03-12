/*
** calc_k.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 18:27:50 2012 alexis leprovost
** Last update Sun May 27 21:43:43 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"inter.h"

int	calc_k(double *indice, double *k)
{
  if (indice == NULL || k == NULL)
    return (EXIT_FAILURE);
  k[0] = ((indice[B] * (-1.0F)) - sqrt(indice[DELTA])) /
    ((2.0F * indice[A]) + EPSILON);
  k[1] = ((indice[B] * (-1.0F)) + sqrt(indice[DELTA])) /
    ((2.0F * indice[A]) + EPSILON);
  return (EXIT_SUCCESS);
}
