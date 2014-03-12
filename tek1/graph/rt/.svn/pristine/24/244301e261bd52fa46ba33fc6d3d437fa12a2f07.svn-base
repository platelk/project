/*
** utils.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 18:10:00 2012 alexis leprovost
** Last update Sat Jun  2 14:47:56 2012 alexis leprovost
*/

#ifndef __UTILS_H__
#define __UTILS_H__

#include	"camera.h"
#include	"object.h"
#include	"color.h"

int	restat_color(t_color *);
int	add_color(t_color *, t_color *);
int	modif_position(double *, t_object *, double *, int);
int	modif_vector(double *, double *, double *, int);
int	get_vector_reflechie(double *, double *, double *);
int	get_vector_light(t_light *, t_detail *, double *);
int     get_vector_refracte(double *, double *, double, double);
int     modif_normal(t_detail *, double *);
int     corrector_normal(t_detail *, double *, double *);
int     normalize_vector(double *);
int	inverse_vector(double *);
int	cpy_point(double *, double *);
int	cmp_k(t_detail *, double *);
int	cpy_color(t_color *, t_color *);

#endif
