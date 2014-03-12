/*
** main.c for pushswap in /home/platel_k/projet/pushswap/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 19 13:36:35 2011 kevin platel
** Last update Sun Jan  8 11:44:57 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "pushswap.h"

int	main(int ac, char **av)
{
  t_nbr	*list_a;
  t_nbr	*list_b;

  list_a = create_list(ac, av);
  list_b = NULL;
  if (ac > 1)
    main_function_sort(list_a, list_b);
  write(1, "pa pb\n", 6);
  return (0);
}

void	aff_list(t_nbr *list_a, t_nbr *list_b)
{
  printf("list A : ");
  while (list_a != NULL)
    {
      printf("[%d] ", list_a->nbr);
      list_a = list_a->next;
    }
  printf("\n\nlist B :");
  while (list_b != NULL)
    {
      printf("[%d] ", list_b->nbr);
      list_b = list_b->next;
    }
  my_putchar('\n');
}
