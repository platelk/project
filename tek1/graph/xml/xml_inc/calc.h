/*
** calc.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 19:29:43 2012 alexis leprovost
** Last update Mon May  7 10:20:03 2012 alexis leprovost
*/

#ifndef __CALC_H__
#define __CALC_H__

#include	"global.h"
#include	"color.h"

#define	NORMAL_ROTATION	1.000
#define INVERSE_ROTATION	-1.000

int	calc_management(t_global *global, t_color *color, int x, int y);
int	calc_vector(t_global *global, double *vector, int x, int y);
int	calc_rotation(double *vector, double *rotation, double flag);

#endif
