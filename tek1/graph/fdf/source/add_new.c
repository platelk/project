/*
** add_new.c for add_new in /home/platel_k/projet/fdf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Dec  5 18:47:10 2011 kevin platel
** Last update Mon Dec  5 20:08:26 2011 kevin platel
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

t_grille	*add_new(t_grille *begin, int x, int y, int z)
{
  t_grille	*new;

  new = malloc(sizeof(new));
  new->point = coor_to_point(x, y, z);
  new->prev = NULL;
  new->next = begin;
  if (begin != NULL)
    begin->prev = new;

  return (new);
}
