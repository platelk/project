/*
** fill_scene.h for fill_scene.h in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 23:21:34 2012 harold ozouf
** Last update Fri Feb 17 11:45:43 2012 harold ozouf
*/

#ifndef		FILL_SCENE_H__
# define	FILL_SCENE_H__

#include	"node.h"
#include	"struct.h"

typedef	  void (*add_shape)(t_shape **s, t_shape *p, t_node *root);

void	fill_scene(t_scene **sc, t_node *root);
void	fill_camera(t_scene **sc, t_node *root);
void	fill_objects(t_scene **sc, t_node *root);
void	fill_lights(t_scene **sc, t_node *root);

#endif
