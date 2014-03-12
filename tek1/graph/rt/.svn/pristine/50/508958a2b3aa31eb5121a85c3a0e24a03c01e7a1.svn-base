/*
** my_rev_list.c for my_rev_list in /home/ozouf_h//42sh_local/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 18:40:59 2012 harold ozouf
** Last update Sun Jun  3 15:22:15 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"parse_obj.h"
#include	"my_rev_list.h"

static int             my_list_sizes(t_vertice *begin)
{
  t_vertice        *sec;
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

static t_vertice		*getnode(t_vertice *list, int n)
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

int		my_rev_list(t_vertice **begin)
{
  t_vertice	*sec;
  t_vertice	*ter;
  t_vertice	*qua;
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

