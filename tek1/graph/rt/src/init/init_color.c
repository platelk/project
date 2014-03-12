/*
** init_color.c for raytracer in /home/leprov_a//depot/rt/src/init
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  8 16:48:33 2012 alexis leprovost
** Last update Fri May 25 14:59:42 2012 ronan guiho
*/

#include	<stdlib.h>
#include	<stdio.h>

#include        "global.h"
#include	"color.h"
#include	"my.h"

t_color	*init_color(char *str)
{
  t_color	*color;
  int	composante;

  if ((color = xmalloc(sizeof(*color))) == NULL)
    return (NULL);
  composante = my_getnbr_base(str, BASE_STRING);
  color->red = (double)(composante >> 16);
  color->green = (double)((composante >> 8) % 256);
  color->blue = (double)(composante % 256);
  return (color);
}
