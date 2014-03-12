/*
** display.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 18:46:02 2012 alexis leprovost
** Last update Tue May 29 18:36:12 2012 zoe phalippou
*/

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include	"thread.h"
#include	"global.h"

int		display_image(t_global *);
t_color		*display_image_pixel(t_thread *, double, double, int);

#endif
