/*
** plan.h for plan in /home/ozouf_h//projet/rtv1/srcs/raytrace
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sun Feb 19 15:43:59 2012 harold ozouf
** Last update Sun Feb 19 15:45:15 2012 harold ozouf
*/

#ifndef		PLAN_H__
# define	PLAN_H__

#include	"struct.h"

void	get_normal_plan(t_shape *s, t_pos *p, t_pos **n);
void	destruct_plan(t_shape *s);
double	inter_plan(t_shape *s, t_pos *v, t_pos *p);

#endif
