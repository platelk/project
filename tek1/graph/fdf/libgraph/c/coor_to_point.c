/*
** coor_to_point.c for coor_to_point in /home/platel_k/projet/fdf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 24 09:59:33 2011 kevin platel
** Last update Mon Dec 19 10:28:25 2011 kevin platel
*/

#include "my_libX.h"
#include "grille.h"
#include "point.h"
#include "mlx.h"
#include "my.h"

t_point		*coor_to_point(int x, int y, int z)
{
  t_point	*pixel;
  int		new_x;
  int		new_y;

  new_x = (CTE1 * x) - (CTE2 * y);
  new_y = -z + ((CTE1 / 2) * x) + ((CTE2 / 2) * y);

  pixel = init_point(new_x, new_y, 0x00FFFFFF);
  return (pixel);
}
