/*
** add_color.c for raytracer in /home/leprov_a//depot/rt/src/utils
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 10:06:40 2012 alexis leprovost
** Last update Fri May 25 15:04:23 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"global.h"
#include	"color.h"

int	add_color(t_color *c1, t_color *c2)
{
  if (c1 == NULL || c2 == NULL)
    return (EXIT_FAILURE);
  c1->red += c2->red;
  c1->green += c2->green;
  c1->blue += c2->blue;
  return (EXIT_SUCCESS);
}
