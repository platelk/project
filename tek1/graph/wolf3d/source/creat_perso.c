/*
** creat_perso.c for creat_perso.c in /home/platel_k/projet/graph/wolf3d
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jan  5 12:02:22 2012 kevin platel
** Last update Sun Jan  8 17:27:52 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "grille.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"
#include "perso.h"

t_perso	 *creat_perso()
{
  t_perso	*perso;

  perso = malloc(sizeof(*perso));
  perso->x = 200;
  perso->y = 200;
  perso->angle = 90;
  perso->life = 0;

  return (perso);
}
