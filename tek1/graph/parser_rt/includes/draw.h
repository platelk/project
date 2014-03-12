/*
** draw.h for draw in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb  1 16:36:44 2012 harold ozouf
** Last update Sun Feb 19 14:55:15 2012 harold ozouf
*/

#ifndef		DRAW_H__
# define	DRAW_H__
#include	"struct.h"

t_color	*get_color_px(t_pos *vec, t_scene *sc, t_inter *inter);
void	draw(t_gl *gl);
void	antialising(t_px *px, t_gl *gl, t_inter *it, t_pos *v);

#endif
