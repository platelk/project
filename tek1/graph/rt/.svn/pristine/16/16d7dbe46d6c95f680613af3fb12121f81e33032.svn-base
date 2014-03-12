/*
** my_rev_n.c for my_rev_n in /home/ozouf_h//rt
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Jun  2 06:11:11 2012 harold ozouf
** Last update Sun Jun  3 17:31:08 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"parse_obj.h"
#include	"my_rev_list.h"

static int             my_list_sizes(t_vertice_n *begin)
{
  t_vertice_n        *sec;
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

static t_vertice_n		*getnode(t_vertice_n *list, int n)
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

int		my_rev_n(t_vertice_n **begin)
{
  t_vertice_n	*sec;
  t_vertice_n	*ter;
  t_vertice_n	*qua;
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

