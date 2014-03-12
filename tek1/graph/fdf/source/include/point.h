/*
** point.h for point in /home/platel_k/projet/minilibX/lib_libx
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 09:42:21 2011 kevin platel
** Last update Fri Dec  9 18:38:13 2011 kevin platel
*/

#ifndef __POINT_H__
#define __POINT_H__

#define CONST	(50)
#define	WINX	(par->x)
#define	WINY	(par->y)
#define	WINXP	(par->x = par->x - CONST)
#define	WINYP	(par->y = par->y - CONST)
#define	WINXM	(par->x = par->x + CONST)
#define	WINYM	(par->y = par->y + CONST)

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
  void *mlx_ptr;
  void *win_ptr;
  int	x;
  int	y;
} t_param;

#endif
