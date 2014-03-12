/*
** parser_moves.c for lemin in /home/guiho_r/tek1/lemin/src/parser/moves
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  9 14:29:10 2012 ronan guiho
** Last update Wed Apr 11 13:56:03 2012 ronan guiho
*/

#include <stdlib.h>

#include "lemin.h"

int		parser_fill_moves(t_move **list, char **tab)
{
  t_move	*ptr;
  t_move	*tmp;

  tmp = *list;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (EXIT_FAILURE);
  ptr->current_move = tab;
  ptr->next = NULL;
  if (*list == NULL)
    {
      ptr->before = NULL;
      *list = ptr;
    }
  else
    {
      while (tmp->next)
	tmp = tmp->next;
      ptr->before = tmp;
      tmp->next = ptr;
    }
  return (EXIT_SUCCESS);
}

t_move		*parser_moves(char **tab, int i)
{
  char		delim[2];
  char		**tab_moves;
  t_move        *list_move;

  delim[0] = DELIM_BUFFER;
  delim[1] = '\0';
  list_move = NULL;
  while (tab[i])
    {
      if ((tab_moves = my_strtok(tab[i], delim, TOK_DELIM))
	  == NULL)
	return (NULL);
      if ((parser_fill_moves(&list_move, tab_moves)) == EXIT_FAILURE)
	return (NULL);
      parser_free_tab(tab_moves);
      i++;
    }
  return (list_move);
}
