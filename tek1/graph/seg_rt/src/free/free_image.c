/*
** free_image.c for raytracer in /home/leprov_a//depot/rt/src/free
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 10:28:41 2012 alexis leprovost
** Last update Wed May  2 10:37:31 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"image.h"

void	free_image(t_image *image)
{
  if (image)
    free(image);
}
