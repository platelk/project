/*
** inter.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 13:15:43 2012 alexis leprovost
** Last update Sat Jun  2 16:09:23 2012 ronan guiho
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

int	inter_equation4deg(double *, double *);
int	inter_cubetroue(t_camera *, t_object *, t_detail *, double *);
int	inter_moebius(t_camera *, t_object *, t_detail *, double *);
int	inter_plan(t_camera *, t_object *, t_detail *, double *);
int	inter_tore(t_camera *, t_object *, t_detail *, double *);
int	inter_sphere(t_camera *, t_object *, t_detail *, double *);
int	inter_cone(t_camera *, t_object *, t_detail *, double *);
int	inter_cylindre(t_camera *, t_object *, t_detail *, double *);
int	inter_paraboloide(t_camera *, t_object *, t_detail *, double *);
int	inter_hyperboloide(t_camera *, t_object *, t_detail *, double *);
int	inter_triangle(t_camera *, t_object *, t_detail *, double *);
int	inter_blender(t_camera *, t_object *, t_detail *, double *);
int	inter_indice_cone(t_camera *, t_object *, double *, double *);
int	inter_indice_sphere(t_camera *, t_object *, double *, double *);
int	inter_indice_cylindre(t_camera *, t_object *, double *, double *);
int	inter_indice_tore(t_camera *, t_object *, double *, double *);
double	inter_indice_plan(t_camera *, t_object *, double *);
int	inter_indice_cubetroue(t_camera *, t_object *, double *, double *);
int	inter_indice_paraboloide(t_camera *, t_object *, double *, double *);
int	inter_indice_hyperboloide(t_camera *, t_object *, double *, double *);
#endif
