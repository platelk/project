/*
** lum.h for lum in /home/ozouf_h//projet/rtv1/srcs/raytrace
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb 17 14:36:42 2012 harold ozouf
** Last update Sun Mar 11 14:43:40 2012 harold ozouf
*/

#ifndef		LUM_H__
# define	LUM_H__

#include	"struct.h"

void	get_shininess(t_color *b, double q_shi, t_color *c, double angle);
void	appli_shininess(int i, t_color *shini);
t_color	*appli_lum_effects(t_color *, double, t_color *);
t_color	*get_lum_color(t_inter *it, t_lum *lum);

#endif
