/*
** center.c for center in /home/platel_k/projet/fdf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Dec  7 15:07:24 2011 kevin platel
** Last update Sun Dec 11 14:34:34 2011 kevin platel
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

t_grille	*center(t_grille *grille, int h, int w)
{
  t_grille	*tmp;
  int	decal;
  int	eca;

  decal = ((HEIGHT) - (my_square_root((w * w) + (h * h)))) / 2 + w;
  eca = (WIDTH / (w + 1)) / 10;
  while (grille != NULL)
    {
      grille->point->x = (grille->point->x * eca) + decal;
      grille->point->y = (grille->point->y *eca) + (decal - (h));
      if (grille->point->x > WIDTH)
	grille->point->x = WIDTH - 1;
      if (grille->point->y > HEIGHT)
	grille->point->y = HEIGHT - 1;
      if (grille->point->x < 0)
	grille->point->x = 0;
      if (grille->point->y < 0)
	grille->point->y = 0;
      grille->point->color = COLOR;
      tmp = grille;
      grille = grille->next;
    }
  return (tmp);
}
