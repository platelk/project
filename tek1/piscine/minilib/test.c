/*
** test.c for minilibX in /home/platel_k//projet/piscine/minilib
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct 27 09:06:22 2011 kevin platel
** Last update Thu Oct 27 14:40:03 2011 kevin platel
*/

#include <stdlib.h>

int	main(int argc, char **argv)
{
  void	*window;
  void	*ind;
  int	x;
  int	y;
  int	colo;

  colo = 0xFFFFFF;
  x = 100;
  y = 0;
  window = mlx_init();
  ind = mlx_new_window(window, 600, 600, "test");
   while (x < 300)
    {
      x = x + 1;
      y =  my_square_root(10000 - ((x - 200) * (x - 200))) + 200;
      mlx_pixel_put(window, ind, x, y, colo);
      y = 200 - my_square_root(10000 - ((x - 200) * (x - 200)));
      mlx_pixel_put(window, ind, x, y, colo);
    }
  while (42);
  return (0);
}
