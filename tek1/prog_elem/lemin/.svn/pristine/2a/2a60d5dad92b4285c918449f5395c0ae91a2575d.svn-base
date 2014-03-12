/*
** parser_malloc_link.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Apr  6 14:17:42 2012 ronan guiho
** Last update Fri Apr  6 14:19:56 2012 ronan guiho
*/

#include <stdlib.h>

#include "lemin.h"

struct s_room	**parser_malloc_link_tab(t_room *list)
{
  int		i;
  int		size;
  struct s_room	**tab;

  i = 0;
  size = parser_size_list(list);
  if ((tab = malloc(sizeof(struct s_room *) * \
		    (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    tab[i++] = NULL;
  return (tab);
}

