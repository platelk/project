/*
** objects_neg.h for rt in /home/phalip_z//exos/projets/RT/inc
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue May 22 16:37:13 2012 zoe phalippou
** Last update Sun Jun  3 00:17:35 2012 zoe phalippou
*/

#ifndef __OBJECTS_NEG_H__
# define __OBJECTS_NEG_H__

#include	"camera.h"
#include        "object.h"

typedef int    (*ptr_f_inhib)(t_camera *, t_object *, double *, double *);

void	obj_inhibitor(double *, t_object *, t_camera *, double *);

#endif
