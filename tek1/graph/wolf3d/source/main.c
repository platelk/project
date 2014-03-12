/*
** main.c for main in /home/platel_k/projet/wolf3d/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 19 10:33:38 2011 kevin platel
** Last update Sun Jan 15 11:49:49 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "grille.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"

int	key_hook(int keycode, t_param *param)
{
  if (keycode == 65307)
    exit(1);
  clean_img(param->mlx_ptr, param->map->wall);
  if (keycode == 65361)
    mouv_left(param);
  if (keycode == 65362)
    mouv_up(param);
  if (keycode == 65364)
    mouv_down(param);
  if (keycode == 65363)
    mouv_right(param);
  if (keycode == 119)
    mouv_more_up(param);
  if (keycode == 115)
    mouv_more_down(param);
  return (0);
}

int     expose(t_param *param)
{
  show_decor(param->map, param->mlx_ptr, param->win_ptr);
  return (0);
}

int	main(int ac, char **av)
{
  void          *mlx_ptr;
  void          *win_ptr;
  t_decor	*map;
  t_perso	*perso;

  if ((mlx_ptr = mlx_init()) == NULL)
    return (0);
  if ((win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Wolf3d")) == NULL)
    return (0);
  map = malloc(sizeof(map));
  if (ac > 1)
    {
      perso = creat_perso();
      map = creat_decor(av, mlx_ptr, win_ptr);
      if (check_map(map) > 0)
	{
	  my_printf("Error map!\n");
	  return (0);
	}
      wolf(perso, map, win_ptr, mlx_ptr);
    }
  else
    my_printf("Error : ./wolf3d [link_map]\n");
  return (0);
}

int	draw_wall(t_perso *perso, t_decor *map, void *win_ptr, void *mlx_ptr)
{
  int		**plan;
  int		k;
  int		x;
  t_point	*point1;
  t_point	*point2;

  plan = calc_p(perso);
  x = 1;
  while (x < (LENGHT_P - 1))
    {
      k = calc_k(perso, map->map, plan, x);
      if (k < 600)
	k = 600;
      point1 = init_point(x - 1, 500 + ((300000) / k), 0x00AA1122);
      point2 = init_point(x, 500 - ((300000)/ k), 0x00AA1122);
      img_line(mlx_ptr, map->wall, point1, point2);
      x++;
    }
  mlx_put_image_to_window(mlx_ptr, win_ptr, map->wall->img, 0, 0);
  return (0);
}
