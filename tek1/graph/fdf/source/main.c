/*
** main.c for main.c in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 13:22:01 2011 kevin platel
** Last update Fri Jan  6 22:21:13 2012 kevin platel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "grille.h"
#include "mlx.h"
#include "point.h"
#include "my_libX.h"
#include "my.h"
#include "fdf.h"

int	key_hook(int keycode, t_param *par)
{
  if (keycode == 65307)
    exit(1);
  if (keycode > 65360 && keycode < 65365)
    {
      clean(par->mlx_ptr, par->win_ptr);
      if (keycode == 65361)
	mlx_put_image_to_window(par->mlx_ptr, par->win_ptr, IMG, WINXP, WINY);
      if (keycode == 65362)
	mlx_put_image_to_window(par->mlx_ptr, par->win_ptr, IMG, WINX, WINYP);
      if (keycode == 65363)
	mlx_put_image_to_window(par->mlx_ptr, par->win_ptr, IMG, WINXM, WINY);
      if (keycode == 65364)
	mlx_put_image_to_window(par->mlx_ptr, par->win_ptr, IMG, WINX, WINYM);
    }
}

int	expose(t_param *par)
{
  mlx_put_image_to_window(par->mlx_ptr, par->win_ptr, IMG, 0, 0);
  return (0);
}

int		main(int argc, char **argv)
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_img		*img_data;
  t_grille		*grille;
  int		width;
  int		height;
  t_param	*param;

  (mlx_ptr = mlx_init()) == NULL ? exit(1) : 42;
  if ((win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Test")) == NULL)
    return (0);
  img_data = init_img(mlx_ptr, WIDTH, HEIGHT);
  argc > 1 ? grille = get_data(argv[1], &width, &height) : exit(0);
  grille = center(grille, height, width);
  draw(grille, &img_data, mlx_ptr, height, width);
  param = new_param(mlx_ptr, win_ptr, img_data);
  mlx_put_image_to_window(mlx_ptr, win_ptr, img_data->img, 0, 0);
  mlx_key_hook(win_ptr, &key_hook, param);
  mlx_expose_hook(win_ptr, &expose, param);
  mlx_loop(mlx_ptr);
  return (0);
}
