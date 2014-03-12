/*
** mlx_ppti.c for mlx_ppti in /home/leprov_a//afs/cours/TP/igraph/tp2
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu Nov 17 11:45:56 2011 alexis leprovost
** Last update Mon May 21 15:15:07 2012 ronan guiho
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"color.h"
#include	"image.h"

int	mlx_ppti(t_image *image, t_color *color, int x, int y)
{
  int i;

  if (image == NULL || color == NULL)
    return (EXIT_FAILURE);
  i = (y * image->sizeline) + (x * (image->bpp / 8));
  if (!image->endian)
    {
      image->data[i] = color->blue;
      image->data[i + 1] = color->green;
      image->data[i + 2] = color->red;
    }
  else
    {
      image->data[i] = 0;
      image->data[i + 1] = color->red;
      image->data[i + 2] = color->green;
      image->data[i + 3] = color->blue;
    }
  return (EXIT_SUCCESS);
}
