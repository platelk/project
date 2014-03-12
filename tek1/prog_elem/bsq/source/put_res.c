/*
** put_res.c for put_res in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Dec  9 08:56:03 2011 kevin platel
** Last update Fri Dec  9 14:46:47 2011 kevin platel
*/

#include "my.h"
#include "bsq.h"

void	put_res(char **data, t_square *big)
{
  int	i;
  int	j;

  i = 0;
  while (data[i])
    {
      j = 0;
      if (i < big->y || i > (big->y + big->size))
	my_putstr(data[i]);
      else
	while (data[i][j])
	  {
	    if ((j >= big->x && j < big->x + big->size) &&
		(i >= big->y && i < big->y + big->size))
	      my_putchar('X');
	    else
	      my_putchar(data[i][j]);
	    j++;
	  }
      my_putchar('\n');
      i++;
    }
}
