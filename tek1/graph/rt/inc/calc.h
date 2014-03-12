/*
** calc.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 19:29:43 2012 alexis leprovost
** Last update Sun Jun  3 17:25:00 2012 alexis leprovost
*/

#ifndef __CALC_H__
#define __CALC_H__

#include	"global.h"
#include	"color.h"
#include	"limit.h"
#include	"detail.h"
#include	"object.h"

#define	NORMAL_ROTATION		1.000
#define INVERSE_ROTATION	-1.000

int	calc_management(t_global *, t_color *, double, double);
int	calc_direction_vector(t_global *, double *, double, double);
int	calc_any_vector(double *, double *, double *);
int	calc_rotation(double *, double *, double);
int	calc_k(double *, double *);
int	calc_limit(t_object *, double *, double *, double *);
int	calc_detail(t_detail *, t_color *, t_camera *, double *);
int	calc_color(t_color *, t_detail *);
int	calc_point(double *, double *, double *, double);
int	calc_effect(t_detail *, t_color *, t_light *, double *);
int	calc_perturbation(t_object *, double *, double *);
int	calc_reflection(t_detail *, t_color *, t_light *, double *);
int	refraction_management(t_detail *, t_color *, t_light *, double *);
double	calc_angle(double *, double *);
double	calc_ps(double *, double *);
int     calc_normal(t_camera *, t_detail *, double *, double *);
double  calc_norme(double *);
double  calcul_solution_smallest(double *);
double  calcul_solution_4deg_pt2(double *, double *, double *);
double  calcul_solution_4deg_pt1(double *, double *);
double  calcul_part_value(double *, double *, double *);
double  calcul_init_value(double *, double *, double, double *);
int     calc_procedural(t_procedural *, double *, t_color *);
int	calc_cut_texture(double *, t_object *, double *, t_camera *);

#endif
