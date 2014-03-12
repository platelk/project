/*
** limit.h for raytracer in /home/leprov_a//depot/rt/inc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue May  8 10:31:08 2012 alexis leprovost
** Last update Tue May 29 19:50:14 2012 zoe phalippou
*/

#ifndef __LIMIT_H__
#define __LIMIT_H__

#include	"raytracer.h"
#include	"xml_tree.h"

#define	MIN_X	1
#define	MAX_X	2

#define	MIN_Y	4
#define	MAX_Y	8

#define	MIN_Z	16
#define	MAX_Z	32

struct s_limit
{
  int		flag;
  double	x[2];
  double	y[2];
  double	z[2];
};

t_limit	*obj_create_limit(t_xtree *);

#endif
