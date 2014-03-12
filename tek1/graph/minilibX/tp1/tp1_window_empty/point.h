/*
** point.h for point in /home/platel_k/projet/minilibX/lib_libx
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 09:42:21 2011 kevin platel
** Last update Wed Nov 23 16:36:56 2011 kevin platel
*/

#ifndef __POINT_H__
#define __POINT_H__

typedef struct s_point
{
  int x;
  int y;
  int color;
} t_point;

typedef struct s_my_ptr
{
  void *mlx_ptr;
  void *win_ptr;
} t_my_ptr;

typedef struct s_img
{
  void	*img;
  char *data;
  int	bpp;
  int	sizeline;
  int	endian;
  int	width;
  int	height;
} t_img;

typedef struct s_param
{
  t_img	*img;
  t_point *point1;
  t_point *point2;
  void *mlx_ptr;
  void *win_ptr;
} t_param;

#endif
