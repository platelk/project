/*
** obj_create.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 31 23:52:40 2012 alexis leprovost
** Last update Sun Jun  3 15:19:34 2012 alexis leprovost
*/

#ifndef	__OBJ_CREATE_H__
#define __OBJ_CREATE_H__

#include	"parse.h"
#include	"object.h"
#include	"camera.h"
#include	"light.h"
#include	"xml_tree.h"
#include	"global.h"

typedef	void	*(*t_create)(t_xtree *);

int		obj_get_light_type(char *);
t_object	*obj_create_list_object(t_xtree *, char *, t_object *, void *);
t_scene		*obj_create_scene(t_xtree *, void *);
void		*obj_create_son(int, t_xtree *);
t_window	*obj_create_window(t_global *, t_xtree *);
t_inter		obj_get_inter_fct(int);
int		obj_get_type(char *);
t_camera	*obj_create_list_cam(t_xtree *);
t_light		*obj_create_list_light(t_xtree *);
t_object*	obj_init_image(t_xtree *, t_object *, void *);
t_normal	obj_get_normal_fct(int);
int             obj_analize_cube(t_object **);
t_stereoscopique        *obj_create_3D(int, int, void *, t_xtree *);

#endif
