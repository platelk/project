/*
** new_param.c for new_param in /home/platel_k/projet/fdf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Dec  7 15:16:32 2011 kevin platel
** Last update Fri Dec  9 18:36:56 2011 kevin platel
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

t_param		*new_param(void *mlx_ptr, void *win_ptr, t_img *img)
{
  t_param	*new;

  new = malloc(sizeof(new));
  new->mlx_ptr = mlx_ptr;
  new->win_ptr = win_ptr;
  new->x = 0;
  new->y = 0;
  new->img = img;
  return (new);
}
