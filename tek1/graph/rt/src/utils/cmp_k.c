/*
** cmp_k.c for raytracer.h in /home/leprov_a//depot/rt/src/utils
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun  1 00:31:14 2012 alexis leprovost
** Last update Fri Jun  1 16:31:03 2012 zoe phalippou
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"detail.h"

int	cmp_k(t_detail *detail, double *k)
{
  if (detail == NULL || k == NULL)
    return (EXIT_FAILURE);
  if ((detail->k < CONST_ERROR && (k[0] > CONST_ERROR ||
				   k[1] > CONST_ERROR)) ||
      (k[0] > CONST_ERROR &&
       (k[1] > CONST_ERROR && k[0] < k[1]) && k[0] < detail->k) ||
      (k[1] > CONST_ERROR && (k[0] > CONST_ERROR &&
			      k[1] < k[0]) && k[1] < detail->k))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
