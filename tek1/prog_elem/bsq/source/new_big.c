/*
** new_big.c for new_big in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Dec  9 16:10:47 2011 kevin platel
** Last update Fri Dec  9 16:15:39 2011 kevin platel
*/

#include "bsq.h"

t_square	*new_square(int x, int y, int size, t_square *big)
{
  big->size = size;
  big->x = x;
  big->y = y;
  return (big);
}
