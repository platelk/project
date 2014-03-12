/*
** cylinder.h for cylinder in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb  3 16:30:27 2012 harold ozouf
** Last update Sat Feb 18 17:54:11 2012 harold ozouf
*/

#ifndef		CYLINDER_H__
# define	CYLINDER_H__

#include	"struct.h"

void	get_normal_cylinder(t_shape *s, t_pos *p, t_pos **n);
double	inter_cylinder(t_shape *s, t_pos *v, t_pos *p);
void	destruct_cylinder(t_shape *s);

#endif
