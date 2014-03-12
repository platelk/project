/*
** fdf.h for fdf in /home/platel_k/projet/fdf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 24 10:44:45 2011 kevin platel
** Last update Sun Dec 11 12:49:25 2011 kevin platel
*/

#ifndef __FDF_H__
#define __FDF_H__

#include "my.h"
#include "my_libX.h"
#include "grille.h"
#include "point.h"
#include "mlx.h"
#include "get_next_line.h"

#define ECA	5
#define WIDTH	900
#define HEIGHT	900
#define IMG par->img->img
#define ABS(x)	((x < 0) ? (-x) : (x))

int	key_hook(int keycode, t_param *param);
void	draw(t_grille *grille, t_img **img, void *mlx, int height, int width);
void    freewordtab(char ***tab);
t_grille   *add_in_list(t_grille *line, t_grille *begin, t_point *pixel);
t_point    *coor_to_point(int x, int y, int z);
t_grille	*get_data(char *link, int *i, int *j);
t_grille	*center(t_grille *grille, int h, int w);
t_param		*new_param(void *mlx_ptr, void *win_ptr, t_img *img);
int	expose(t_param *param);
void	clean(void *mlx_ptr, void *win_ptr);

#endif
