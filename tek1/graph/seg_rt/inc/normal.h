/*
** normal.h for normal in /home/vink/projet/graph/rt
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed May 23 23:02:04 2012 kevin platel
** Last update Tue May 29 19:57:50 2012 zoe phalippou
*/

#ifndef	__NORMAL_H__
#define __NORMAL_H__

#include "global.h"

int     normal_sphere(double *, t_detail * ,double *, double *);
int     normal_cylindre(double *, t_detail *, double *, double *);
int     normal_cone(double *, t_detail *, double *, double *);
int     normal_plan(double *, t_detail *, double *, double *);
int     normal_tore(double *, t_detail *, double *, double *);
int     normal_cubetroue(double *, t_detail *, double *, double *);

#endif
