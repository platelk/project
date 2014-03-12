/*
** inter.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 13:15:43 2012 alexis leprovost
** Last update Sun May 27 17:52:22 2012 kevin platel
*/

#ifndef __INTER_H__
#define __INTER_H__

#include	"global.h"
#include	"camera.h"
#include	"detail.h"
#include	"object.h"

#define	NB_INDICE	4
#define DELTA		3

typedef enum e_indice
{
  A,
  B,
  C,
  D,
  E
} t_indice;

double		inter_equation4deg(double *indice);
int		inter_cubetroue(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_moebius(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_plan(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_tore(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_sphere(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_cone(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_cylindre(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_paraboloide(t_camera *camera, t_object *object, t_detail *detail, double *vector);
int		inter_hyperboloide(t_camera *camera, t_object *object, t_detail *detail, double *vector);

int	inter_indice_cone(t_camera *, t_object *, double *, double *);
int	inter_indice_sphere(t_camera *, t_object *, double *, double *);
int	inter_indice_cylindre(t_camera *, t_object *, double *, double *);
int	inter_indice_tore(t_camera *, t_object *, double *, double *);


#endif
