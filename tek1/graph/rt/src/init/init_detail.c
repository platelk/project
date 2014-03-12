/*
** init_detail.c for raytracer in /home/leprov_a//depot/rt/src/init
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 13:47:16 2012 alexis leprovost
** Last update Sat Jun  2 17:12:32 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"detail.h"
#include	"object.h"

int	init_detail(t_detail *detail)
{
  int	i;

  i = -1;
  if (detail == NULL)
    return (EXIT_FAILURE);
  detail->k = -1.0F;
  detail->object = NULL;
  detail->non_initialize = 0;
  while (++i < NB_DIMENSION)
    {
      detail->position[i] = 0.0F;
      detail->normal[i] = 0.0F;
    }
  return (EXIT_SUCCESS);
}
