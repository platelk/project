/*
** light.h for light in /home/platel_k/projet/graph/rtv1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Feb  1 10:33:46 2012 kevin platel
** Last update Fri Feb 17 11:19:03 2012 kevin platel
*/

#ifndef	__LIGHT__
#define __LIGHT__

#include "attribute.h"

typedef struct s_light
{
  int	x;
  int	y;
  int	z;
  t_attr *attr;
  void	*father;
  struct s_light *next;
  struct s_light *prev;
} t_light;

#endif
