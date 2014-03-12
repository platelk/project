/*
** wolf.h for wolf.h in /home/platel_k/projet/graph/wolf3d/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Jan  4 09:54:35 2012 kevin platel
** Last update Sun Jan 15 11:48:28 2012 kevin platel
*/

#ifndef __WOLF_H__
#define __WOLF_H__

#include "mlx.h"
#include "decor.h"
#include "perso.h"
#include "point.h"

char	*epur_str(char *line);
int	draw_wall(t_perso *perso, t_decor *map, void *win_ptr, void *mlx_ptr);
int	**calc_p(t_perso *perso);
t_perso	*creat_perso(void);
char	**get_data(char *link);
void	wall_line(void *mlx_ptr, int k, int x, t_imag *wall);
int	show_decor(t_decor *map, void *mlx_ptr, void *win_ptr);
int	calc_k(t_perso *perso, char **map, int **plan, int x);
int	key_hook(int keycode, t_param *param);
int	clean(void *mlx_ptr, t_imag  *img);
int     expose(t_param *param);
int	**calc_p(t_perso *perso);
int	calc_k(t_perso *perso, char **map, int **plan, int x);
int	check_map(t_decor *map);
void	clean_img(void *mlx_ptr, t_imag *img);
t_decor	*creat_decor(char **av, void *mlx_ptr, void *win_ptr);
char	**get_data(char *link);
int	mouv_left(t_param *param);
int	mouv_right(t_param *param);
int	mouv_up(t_param *param);
int	mouv_down(t_param *param);
int	mouv_more_up(t_param *param);
int	mouv_more_down(t_param *param);
int	show_decor(t_decor *map, void *mlx_ptr, void *win_ptr);
int	wolf(t_perso *perso, t_decor *map, void *win_ptr, void *mlx_ptr);

#endif
