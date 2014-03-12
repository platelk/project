/*
** draw.c for draw in /home/platel_k/projet/fdf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Dec  6 14:00:04 2011 kevin platel
** Last update Wed Dec  7 17:37:50 2011 kevin platel
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

void	draw(t_grille *grille, t_img **img, void *mlx, int height, int width)
{
  t_grille	*tmp;
  int	i;
  int	j;

  j = 1;
  while (grille != NULL)
    {
      tmp = grille;
      i = -1;
      while (tmp != NULL && ++i < width)
	tmp = tmp->prev;
      if (tmp != NULL && i == width)
	img_line(mlx, *img, grille->point, tmp->point);
      if (grille->prev != NULL && (j % (height)) != 0)
	img_line(mlx, *img, grille->point, grille->prev->point);
      grille = grille->prev;
      j++;
    }
}
