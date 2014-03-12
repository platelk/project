/*
** my_rev_node.c for my_rev_node7 in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 18 23:34:08 2012 harold ozouf
** Last update Wed Apr 18 23:40:18 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"tree.h"

static int             my_list_sizes(t_child *begin)
{
  t_child        *sec;
  int           size;

  size = 0;
  sec = begin;
  while (sec != NULL)
    {
      size = size + 1;
      sec = sec->next;
    }
  return (size);
}

static t_child		*getnode(t_child *list, int n)
{
  int		i;

  i = 0;
  while (i < n - 1)
    {
      list = list->next;
      i = i + 1;
    }
  return (list);
}

int		my_rev_node(t_child **begin)
{
  t_child	*sec;
  t_child	*ter;
  t_child	*qua;
  int		i;

  i = -1;
  sec = *begin;
  ter = *begin;
  if (*begin == NULL)
    return (0);
  while (++i < my_list_sizes(ter) - 1)
    sec = sec->next;
  qua = sec;
  while (i >= 0)
    {
      sec->next = getnode(ter, i);
      sec = sec->next;
      i = i - 1;
    }
  sec->next = NULL;
  *begin = qua;
  return (1);
}

