/*
** color.h for color in /home/ozouf_h//projet/rtv1/srcs/raytrace
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sun Feb 19 14:18:03 2012 harold ozouf
** Last update Sun Mar 11 19:49:10 2012 harold ozouf
*/

#ifndef		COLOR_H__
# define	COLOR_H__

#include	"struct.h"

void	check_colors(t_color **c, double *angle, t_color *shini);
void	init_colors(t_color **c);
void	div_color(t_color **c, double nbr);
void	add_color(t_color **dest, t_color *a, t_color *b);

#endif
