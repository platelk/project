/*
** init_detail.c for raytracer in /home/leprov_a//depot/rt/src/init
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 13:47:16 2012 alexis leprovost
** Last update Wed May 30 13:35:49 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"detail.h"
#include	"object.h"

int	init_detail(t_detail *detail)
{
  if (detail == NULL)
    return (EXIT_FAILURE);
  detail->k = -1.0F;
  detail->object = NULL;
  return (EXIT_SUCCESS);
}
