/*
** sphere.h for sphere in /home/ozouf_h//projet/rtv1
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Jan 31 17:04:50 2012 harold ozouf
** Last update Sat Feb 18 17:23:09 2012 harold ozouf
*/

#ifndef		SPHERE_H__
# define	SPHERE_H__
# include	"struct.h"

void		get_normal_sphere(t_shape *s, t_pos *p, t_pos **n);
double		inter_sphere(t_shape *s, t_pos *v, t_pos *p);
void		destruct_sphere(t_shape *s);

#endif
