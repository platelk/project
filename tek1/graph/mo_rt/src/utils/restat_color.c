/*
** restat_color.c for raytracer in /home/leprov_a//depot/rt/src/utils
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 09:57:08 2012 alexis leprovost
** Last update Fri May 25 15:04:06 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"global.h"
#include	"color.h"

int	restat_color(t_color *color)
{
  if (color == NULL)
    return (EXIT_FAILURE);
  color->red = 0.000;
  color->green = 0.000;
  color->blue = 0.000;
  return (EXIT_SUCCESS);
}
