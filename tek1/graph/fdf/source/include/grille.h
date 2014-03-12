/*
** grille.h for grille in /home/platel_k/projet/fdf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 24 09:42:14 2011 kevin platel
** Last update Sun Dec 11 14:33:03 2011 kevin platel
*/

#ifndef __GRILLE_H__
#define __GRILLE_H__

#define CTE1	(0,6)
#define CTE2	(0,6)
#define COLOR	(0x005555FF)

#include "point.h"

typedef struct s_grille
{
  t_point  *point;
  struct s_grille *next;
  struct s_grille *prev;
} t_grille;

#endif
