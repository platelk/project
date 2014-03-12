/*
** texture_getcolor.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May 10 14:45:24 2012 ronan guiho
** Last update Mon May 28 21:59:32 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "color.h"
#include "image.h"

int	texture_getcolor(t_image *texture, t_color *color, \
			 int *pos)
{
  int	i;

  pos[X] = (pos[X] < 0) ? 0 : pos[X];
  pos[Y] = (pos[Y] < 0) ? 0 : pos[Y];
  i = (pos[Y] * texture->sizeline) + (pos[X] * (texture->bpp / 8));
  color->red = (float)(unsigned char)texture->data[i + 2];
  color->green = (float)(unsigned char)texture->data[i + 1];
  color->blue = (float)(unsigned char)texture->data[i];
  return (EXIT_SUCCESS);
}
