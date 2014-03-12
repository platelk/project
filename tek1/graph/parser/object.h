/*
** object.h for object in /home/ozouf_h//projet/rt_v1/srcs/raytrace
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sun Mar 11 14:31:43 2012 harold ozouf
** Last update Sun Mar 11 14:32:29 2012 harold ozouf
*/

#ifndef		OBJECT_H__
# define	OBJECT_H__

void	add_sphere(t_shape **s, t_shape *p, t_node *nd);
void	add_cone(t_shape **s, t_shape *p, t_node *nd);
void	add_plan(t_shape **s, t_shape *p, t_node *nd);
void	add_cylinder(t_shape **s, t_shape *p, t_node *nd);

#endif
