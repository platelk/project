/*
** main.c for main in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Dec  7 16:26:26 2011 kevin platel
** Last update Mon Dec 12 11:27:37 2011 kevin platel
*/

#include <stdlib.h>
#include "bsq.h"

int	main(int ac, char **av)
{
  char		**data;
  t_square	*big;

  big = malloc(sizeof(*big));
  if (big == NULL)
    return (0);
  big->x = 0;
  big->y = 0;
  big->size = 0;
  if ((data = get_data(av[1])) == NULL)
    return (0);
  big_square(data, 0, 0, big);
  put_res(data, big);
  my_putstr("plus grand carre:\nx = ");
  my_putnbr(big->x);
  my_putstr("\ny = ");
  my_putnbr(big->y);
  my_putstr("\nsize = ");
  my_putnbr(big->size);
  my_putchar('\n');
  freewordtab(data);
  free(data);
  return (0);
}
