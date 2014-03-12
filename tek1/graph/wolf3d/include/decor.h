/*
** decor.h for decor.h in /home/platel_k/projet/graph/wolf3d/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Jan  4 09:34:35 2012 kevin platel
** Last update Sat Jan  7 12:54:18 2012 kevin platel
*/

#ifndef __DECOR_H__
#define __DECOR_H__

#include "point.h"
#include "perso.h"

typedef struct s_decor
{
  t_imag	*wall;
  char		**map;
} t_decor;

typedef struct s_param
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_decor	*map;
  t_perso	*perso;
} t_param;

#endif
