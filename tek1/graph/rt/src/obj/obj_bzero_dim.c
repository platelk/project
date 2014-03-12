/*
** obj_bzero_dim.c for obj_bzero_dim in /home/jordan/Projets/debug_rt/rt/src/obj
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 11:47:36 2012 jordan vanwalleghem
** Last update Sat Jun  2 17:29:29 2012 alexis leprovost
*/

#include        "obj_create.h"

void		obj_effect_bzero(double *tab)
{
  tab[REFLECTION] = 0.0F;
  tab[BRIGHTNESS] = 0.0F;
  tab[TRANSPARENCY] = 0.0F;
  tab[PHONG] = 10000.0F;
}

void            obj_bzero_dim(double *tab)
{
  tab[X] = 0.0F;
  tab[Y] = 0.0F;
  tab[Z] = 0.0F;
}
