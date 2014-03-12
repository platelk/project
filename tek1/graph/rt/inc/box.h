/*
** box.h for box in /home/ozouf_h//rt/src/box
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May 15 14:25:59 2012 harold ozouf
** Last update Tue May 29 18:31:36 2012 zoe phalippou
*/

#ifndef		__BOX_H__
# define	__BOX_H__

#include	"object.h"

typedef void    (*t_init_boxes)(t_object *);

void	init_b_sphere(t_object *);
void	init_b_tore(t_object *);
int     inter_box(t_object *, t_object *);
void	init_b_inf(t_object *);
int	inter_ray_box(t_camera *, double *, t_object *);
void	init_box(t_object *);

#endif
