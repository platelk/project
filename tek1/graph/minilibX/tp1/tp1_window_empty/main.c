/*
** main.c for main.c in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 13:22:01 2011 kevin platel
** Last update Mon Dec  5 16:47:17 2011 kevin platel
*/

#include "mlx.h"
#include "point.h"
#include <stdlib.h>
#include "my_libX.h"

int		event_mouse(int button, int x, int y, t_param *param)
{
  t_point	*pixel;

  pixel = init_point(param->point1->x, param->point1->y, param->point1->color);
  param->point1->x = x;
  param->point1->y = y;
  param->point2->x = pixel->x;
  param->point2->y = pixel->y;
  if (button == 1)
    {
      img_line(param->mlx_ptr, param->img, param->point2, param->point1);
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->img, 0, 0);
    }
}

int	expose(t_param *param)
{
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->img, 0, 0);
  return (0);
}

int		main(int argc, char **argv)
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_point	*point1;
  t_point	*point2;
  t_my_ptr	*my_ptr;
  t_img		*img_data;
  t_param	*param;

  mlx_ptr = mlx_init();
  img_data = init_img(mlx_ptr, 500, 500);
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Test");

  my_ptr = init_my_ptr(mlx_ptr, win_ptr);
  point1 = init_point(150, 0, 0x00FF0000);
  point2 = init_point(300, 300, 0x00FFFFFF);

  img_line(mlx_ptr, img_data, point1, point2);
  mlx_put_image_to_window(mlx_ptr, win_ptr, img_data->img, 0, 0);

  param = malloc(sizeof(*param));
  if (param == NULL)
    return (0);
  param->img = img_data;
  param->point1 = point1;
  param->point2 = point2;
  param->mlx_ptr = mlx_ptr;
  param->win_ptr = win_ptr;

  mlx_mouse_hook(win_ptr, &event_mouse, param);
  mlx_expose_hook(win_ptr, &expose, param);
  mlx_loop(mlx_ptr);
  return (0);
}

