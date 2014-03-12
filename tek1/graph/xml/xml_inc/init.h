/*
** init.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 18:14:07 2012 alexis leprovost
** Last update Wed May  2 19:28:38 2012 alexis leprovost
*/

#ifndef __INIT_H__
#define __INIT_H__

#include	"window.h"
#include	"image.h"
#include	"color.h"

t_image         *init_image(void *mlx_ptr, char *path, int x, int y);
t_window        *init_window(char *name, char *path, int x, int y);
t_color		*init_color(void);

#endif
