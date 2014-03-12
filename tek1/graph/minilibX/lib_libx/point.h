/*
** point.h for point in /home/platel_k/projet/minilibX/lib_libx
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 09:42:21 2011 kevin platel
** Last update Wed Nov  9 09:49:20 2011 kevin platel
*/

#ifndef __POINT_H__
#define __POINT_H__

typedef struct s_point
{
  int x;
  int y;
  int color;
  void *mlx_ptr;
  void *win_ptr;
} t_point;

#endif
