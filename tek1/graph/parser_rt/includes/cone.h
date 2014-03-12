/*
** cone.h for cone in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb  3 15:38:48 2012 harold ozouf
** Last update Sat Feb 18 17:52:42 2012 harold ozouf
*/

#ifndef		CONE_H__
# define	CONE_H__

# include	"struct.h"

void	get_normal_cone(t_shape *s, t_pos *p, t_pos **n);
double	inter_cone(t_shape *s, t_pos *v, t_pos *p);
void	destruct_cone(t_shape *s);
#endif
