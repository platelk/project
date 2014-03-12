/*
** parser_link.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Apr  6 12:34:34 2012 ronan guiho
** Last update Mon Apr  9 10:52:59 2012 ronan guiho
*/

#include <stdlib.h>

#include "hex.h"

t_room		*parser_found_room_name(t_room *list, char *name, int i)
{
  t_room	*tmp;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  my_printf("lemin: error(%d): room not exist '%s'\n", i + 1, name);
  return (NULL);
}
int		parser_link_malloc(t_room *list)
{
  t_room	*tmp;

  tmp = list;
  while (tmp)
    {
      if ((tmp->link = parser_malloc_link_tab(list)) == NULL)
	return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		parser_return_indice_end_link(t_room **link, t_room *ptr,
					      int i)
{
  int		i1;

  i1 = 0;
  while (link[i1])
    {
      if (link[i1] == ptr)
	{
	  my_printf("lemin: warning(%d): link already present\n", i + 1);
	  return (-1);
	}
      i1++;
    }
  return (i1);
}
int		parser_fill_link(t_room *list, char **tab, int i)
{
  t_room	*ptr1;
  t_room	*ptr2;
  int		indice;

  if ((ptr1 = parser_found_room_name(list, tab[0], i)) == NULL)
    return (EXIT_FAILURE);
  if ((ptr2 = parser_found_room_name(list, tab[1], i)) == NULL)
    return (EXIT_FAILURE);
  if ((indice = parser_return_indice_end_link(ptr1->link, ptr2, i)) == -1)
    return (EXIT_FAILURE);
  ptr1->link[indice] = ptr2;
  if ((indice = parser_return_indice_end_link(ptr2->link, ptr1, i)) == -1)
    return (EXIT_FAILURE);
  ptr2->link[indice] = ptr1;
  return (EXIT_SUCCESS);
}

int		parser_link(t_room *list, char **tab, int i)
{
  char		delim[2];
  char		**tab_link;

  delim[0] = DELIM_LINK;
  delim[1] = '\0';
  if ((parser_link_malloc(list)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (tab[i])
    {
      while (tab[i][0] == '#' && tab[i][1] != '#')
	i++;
      if ((tab_link = my_strtok(tab[i], delim, TOK_DELIM)) == NULL)
	return (EXIT_FAILURE);
      if ((parser_fill_link(list, tab_link, i)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      parser_free_tab(tab_link);
      i++;
    }
  return (EXIT_SUCCESS);
}
