/*
** main.c for main in /home/platel_k/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  1 13:06:41 2012 kevin platel
** Last update Sat Mar 10 17:11:29 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "scene.h"
#include "rt.h"
#include "point.h"

int	expose(t_param *param)
{
  mlx_put_image_to_window(param->mlx_ptr,
			  param->win_ptr, param->img->img, 0, 0);
  return (0);
}

int	check(int ac, char **av)
{
  if (ac < 2)
    {
      my_printf("Please give en .rt file");
      return (0);
    }
  if (my_strcmp(".rt", &av[1][my_strlen(av[1]) - 3]) != 0)
    {
      my_printf("Error : give a .rt file");
      return (0);
    }
  return (1);
}

int	main(int ac, char **av)
{
  t_scene	*scene;
  void		*mlx_ptr;
  void		*win_ptr;
  t_imag	*img;
  t_param	param;

  if (check(ac, av) == 0)
    return (0);
  if ((mlx_ptr = mlx_init()) == NULL)
    return (0);
  if ((scene = get_data(av[1])) == NULL)
    return (0);
  if ((img = calc_img(scene, mlx_ptr)) == NULL)
    return (0);
  win_ptr = mlx_new_window(mlx_ptr, img->width, img->height, "Rtv1");
  if (win_ptr == NULL)
    return (0);
  param.mlx_ptr = mlx_ptr;
  param.win_ptr = win_ptr;
  param.img = img;
  mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);
  mlx_expose_hook(win_ptr, &expose, &param);
  mlx_loop(mlx_ptr);
  return (0);
}
