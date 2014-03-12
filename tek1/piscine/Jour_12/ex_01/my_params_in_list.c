/*
** my_params_in_list.c for my_params_in_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 10:14:30 2011 kevin platel
** Last update Thu Oct 27 17:51:00 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

t_list		*add_new_in_list(t_list **list, char *value)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  new->data = value;
  new->next = *list;

  return (*list = new);
}

t_list		*my_params_in_list(int ac, char **av)
{
  int		i;
  t_list	*list;

  list = NULL;
  i = 0;
  while (i < ac)
    {
      add_new_in_list(&list, av[i]);
      i = i + 1;
    }
  return (list);
}
