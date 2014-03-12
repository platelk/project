/*
** list.c for list in /home/platel_k/projet/sys_unix/myselect/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 10 10:06:37 2012 kevin platel
** Last update Thu Jan 12 18:55:23 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "myselect.h"

t_element	*add_in_list(t_element *list, char *name)
{
  t_element	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  new->name = my_strdup(name);
  new->cursor = 0;
  new->is_select = 0;
  new->lenght = my_strlen(name);
  new->next = list;
  new->prev = NULL;
  if (list != NULL)
    list->prev = new;
  return (new);
}

t_element	*del_one_in_list(t_element *list)
{
  t_element	*tmp;

  if (list != NULL)
    {
      tmp = list;
      if (list->next != list)
	{
	  list = list->next;
	  list->prev = tmp->prev;
	  tmp->prev->next = list;
	}
      else if (list->prev != list)
	{
	  list = list->prev;
	  list->next = tmp->next;
	  tmp->next->prev = list;
	}
      else
	list = NULL;
      if (tmp->name != NULL)
	free(tmp->name);
      free(tmp);
    }
  return (list);
}

void	free_list(t_element *list)
{
  while (list != NULL)
    list = del_one_in_list(list);
}

t_element	*creat_list(char **av, int ac)
{
  t_element	*list;
  t_element	*last;
  int	i;

  list = NULL;
  list = add_in_list(list, av[ac - 1]);
  last = list;
  i = (ac - 2);
  while (i > 0)
    {
      list = add_in_list(list, av[i]);
      i--;
    }
  list->cursor = 1;
  list->prev = last;
  last->next = list;
  return (list);
}
