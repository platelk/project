/*
** detail.h for raytracer in /home/leprov_a//depot/rt/inc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon May  7 13:21:14 2012 alexis leprovost
** Last update Sat Jun  2 17:12:39 2012 alexis leprovost
*/

#ifndef __DETAIL_H__
#define __DETAIL_H__

#include	"raytracer.h"
#include	"global.h"
#include	"object.h"
#include	"color.h"

struct s_detail
{
  double	position[NB_DIMENSION];
  double	normal[NB_DIMENSION];
  double	k;
  int		non_initialize;
  t_object	*object;
};

#endif
