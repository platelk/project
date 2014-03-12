/*
** image.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 15:51:52 2012 alexis leprovost
** Last update Tue May  1 15:52:43 2012 alexis leprovost
*/

#ifndef __IMAGE_H__
#define __IMAGE_H__

typedef struct s_image
{
  void	*ptr;
  char	*data;
  int	sizeline;
  int	bpp;
  int	endian;
} t_image;

#endif
