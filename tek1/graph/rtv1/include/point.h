/*
** point.h for point in /home/platel_k/projet/minilibX/lib_libx
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Nov  9 09:42:21 2011 kevin platel
** Last update Sun Feb 19 15:52:28 2012 kevin platel
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
  double x;
  double y;
  double z;
  int color;
} t_point;

typedef struct s_my_ptr
{
  void *mlx_ptr;
  void *win_ptr;
} t_my_ptr;

typedef struct s_imag
{
  void	*img;
  char *data;
  int	bpp;
  int	sizeline;
  int	endian;
  int	width;
  int	height;
} t_imag;

#endif
