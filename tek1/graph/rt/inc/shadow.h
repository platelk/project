/*
** shadow.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat May 12 01:44:12 2012 alexis leprovost
** Last update Sun Jun  3 06:22:25 2012 kevin platel
*/

#ifndef __SHADOW_H__
#define __SHADOW_H__

#include	"detail.h"
#include	"color.h"
#include	"light.h"

double	shadow_management(t_detail *, t_color *, double *);

#endif
