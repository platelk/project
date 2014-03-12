/*
** bot.c for bot in /home/platel_k/projet/prog_elem/alum-1
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan 30 11:22:47 2012 kevin platel
** Last update Sun Feb 12 20:20:34 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "myselect.h"

int	bot_data(int action, t_element **list, int nbr)
{
  t_element	*tmp;

  tmp = (*list)->next;
  while (tmp != (*list))
    {
      tmp->cursor = 0;
      tmp = tmp->next;
    }
  tmp->cursor = 0;
  if (alum_remove(list, nbr) == END)
    return (END);
  (*list)->cursor = 2;
  (*list)->prev->cursor = 1;
  return (action);
}

int	nbr_ligne(t_element *list)
{
  t_element	*tmp;
  int	nbr;

  tmp = list->prev;
  nbr = 1;
  while (list != tmp)
    {
      list = list->next;
      nbr++;
    }
  return (nbr);
}

int	nbr_alum(t_element *list)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (list != NULL && list->name != NULL)
    {
      while (list->name[i] && list->name[i] == ' ')
	i++;
      if (list->name[i] != '|')
	return (0);
      while (list->name[i] && list->name[i] != '|')
	{
	  i++;
	  j++;
	}
    }
  return (j);
}

t_element	*ligne_max_alum(t_element *list)
{
  int	i;
  int	max;
  t_element	*tmp;

  i = nbr_ligne(list);
  max = 0;
  tmp = list;
  while (i >= 0)
    {
      if (max < nbr_alum(list))
	{
	  max = nbr_alum(list);
	  tmp = list;
	}
      list = list->next;
      i--;
    }
  return (tmp);
}

t_element	*bot(t_element *list)
{
  t_element *tmp;
  t_element	*tmp2;

  if (nbr_ligne(list) == 1)
    {
      if (nbr_alum(list) == 1)
	return (NULL);
      else
	bot_data(SELECT, &list, nbr_alum(list) - 1);
      return (list);
    }
  else
    {
      tmp = ligne_max_alum(list);
      tmp2 = tmp;
      bot_data(SELECT, &tmp, (nbr_alum(tmp) % 2) + 1);
      if (tmp2 != tmp && tmp2 == list)
	list = tmp;
    }
  return (list);
}
