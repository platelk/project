/*
** fill_objects.h for fill_objects in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb 17 10:55:26 2012 harold ozouf
** Last update Thu Mar  8 19:55:25 2012 harold ozouf
*/

#ifndef		FILL_OBJECTS_H__
# define	FILL_OBJECTS_H__

#include	"struct.h"
#include	"node.h"
#include	"fill_scene.h"

int	get_type(char *type, char **cores);
void	add_sphere(t_shape **s, t_shape *p, t_node *nd);
void	add_cone(t_shape **s, t_shape *p, t_node *nd);
void	add_cylinder(t_shape **s, t_shape *p, t_node *nd);
void	add_plan(t_shape **s, t_shape *p, t_node *nd);
void	add_obj(t_shape **sc, t_node *root, char **cores, add_shape *sh);

#endif
