/*
** display.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 18:46:02 2012 alexis leprovost
** Last update Sun Jun  3 17:18:16 2012 alexis leprovost
*/

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include	"parse.h"
#include	"thread.h"
#include	"global.h"

int		progressbar_calc(int i);
int		display_image_calc(t_thread *, double,
			   double *, double *);
int		aliasing(t_thread *, double, double, \
			 double);
int		antialiasing(t_thread *, double, double, double);
int		display_image(t_global *);
void		*display_image_thread(void *);
int		display_image_thread_x(double, t_thread *, double,
				       t_normal_info *);
t_color		*display_image_pixel(t_thread *, double, double, int);
int             display_stereoscopique(t_global *);
int		display_image_proccess(t_global *, \
				       t_normal_info *,
				       int);
int		display_fill_thread(int, int, int *, \
			    t_global *);

#endif
