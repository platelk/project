/*
** object.h for object in /home/platel_k/projet/graph/rtv1/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  1 09:19:59 2012 kevin platel
** Last update Thu Feb 23 10:12:59 2012 kevin platel
*/

#ifndef	__OBJECT_H__
#define __OBJECT_H__

#include "attribute.h"

typedef struct s_object
{
  int	type;
  double	r;
  double	x;
  double	y;
  double	z;
  t_attr	*attr;
  //void	*(f)(void *);
  void	*father;
  struct s_object *next;
  struct s_object *prev;
} t_object;

#endif
