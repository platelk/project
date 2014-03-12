/*
** clean.c for clean in /home/platel_k/projet/fdf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Dec  9 23:42:02 2011 kevin platel
** Last update Fri Dec  9 23:50:14 2011 kevin platel
*/

#include "my.h"
#include "my_libX.h"
#include "grille.h"
#include "point.h"
#include "mlx.h"
#include "get_next_line.h"
#include "fdf.h"

void	clean(void *mlx_ptr, void *win_ptr)
{
  int	i;
  int	j;

  i = 0;
  while (i < HEIGHT)
    {
      j = 0;
      while (j < WIDTH)
	{
	  mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x00000000);
	  j++;
	}
      i++;
    }
}
