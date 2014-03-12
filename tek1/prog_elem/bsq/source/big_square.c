/*
** big_square.c for big_square in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Dec  8 15:19:23 2011 kevin platel
** Last update Sun Dec 11 13:17:30 2011 kevin platel
*/

#include "bsq.h"

int	big_square(char **data, int x, int y, t_square *big)
{
  int	size;

  while (data[y] != 0 && data[y + big->size] != 0)
    {
      size = find_square(data, x, y, big->size);
      if (size > big->size)
	new_square(x, y, size, big);
      if (data[y][x + 1] == 0 || (x + size + 1) == 0)
	{
	  y++;
	  x = 0;
	}
      else
	x = x + size + 1;
    }
  return (0);
}
