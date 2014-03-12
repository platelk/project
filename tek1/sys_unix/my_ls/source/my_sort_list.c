/*
** my_sort_list.c for my_sort_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 17:05:27 2011 kevin platel
** Last update Sun Dec  4 08:09:03 2011 kevin platel
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "data.h"
#include "my_ls.h"

int	my_sort_by_alpha(char *str1, char *str2);

t_data		*del_in_list(t_data *begin)
{
  t_data	*tmp;

  tmp = begin;
  if (begin != NULL)
    {
      if (begin->prev != NULL)
	(begin->prev)->next = begin->next;
      if (begin->next != NULL)
	begin->next->prev = begin->prev;
      if (begin->next != NULL)
	begin = begin->next;
      else
	{
	  free(tmp->name);
	  free(tmp);
	  if (begin->prev != NULL)
	    return (begin->prev);
	  return (NULL);
	}
      free(tmp->name);
      free(tmp);
      return (begin);
    }
  return (NULL);
}

t_data		*add_new(t_data **list, char *name)
{
  t_data	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    {
      perror("malloc");
      exit(0);
    }
  new->name = my_strdup(name);
  new->next = (*list);
  new->prev = NULL;
  if ((*list) != NULL)
    (*list)->prev = new;

  return (*list = new);
}

t_data		*my_list_swap(t_data *begin)
{
  t_data	*tmp;

  tmp = begin->next;
  begin->next = tmp->next;
  if (begin->prev != NULL)
    begin->prev->next = tmp;
  if (tmp->next != NULL)
    tmp->next->prev = begin;
  tmp->prev = begin->prev;
  begin->prev = tmp;
  tmp->next = begin;

  return (tmp);
}

int		my_sort_list(t_data **begin, int (*cmp)())
{
  while ((*begin)->next != NULL)
    {
      if ((*cmp)((*begin)->name, ((*begin)->next)->name) > 0)
	{
	  (*begin) = my_list_swap(*begin);
	  if ((*begin)->prev != NULL)
	    (*begin) = (*begin)->prev;
	}
      else
	(*begin) = (*begin)->next;
    }
  while ((*begin)->prev != NULL)
    (*begin) = (*begin)->prev;
  return (0);
}
