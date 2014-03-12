/*
** init_my_ptr.c for init_my_ptr in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 14:32:41 2011 kevin platel
** Last update Wed Nov 23 15:14:29 2011 kevin platel
*/

#include <stdlib.h>
#include "point.h"
#include "mlx.h"
#include "my_libX.h"

t_my_ptr	*init_my_ptr(void *mlx_ptr, void *win_ptr)
{
  t_my_ptr	*new_my_ptr;

  new_my_ptr = malloc(sizeof(*new_my_ptr));
  if (new_my_ptr == NULL)
    return (NULL);
  new_my_ptr->mlx_ptr = mlx_ptr;
  new_my_ptr->win_ptr = win_ptr;

  return (new_my_ptr);
}
