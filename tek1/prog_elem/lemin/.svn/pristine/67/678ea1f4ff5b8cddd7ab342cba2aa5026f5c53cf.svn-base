/*
** parser_init_ant.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 15:07:31 2012 ronan guiho
** Last update Mon Apr  9 15:37:31 2012 ronan guiho
*/

#include <stdlib.h>

#include "lemin.h"

t_ant		**parser_init_ant(t_glob *global)
{
  int		i;
  t_room	*ptr_start;
  t_ant		**ant;

  i = -1;
  if ((ant = malloc(sizeof(t_ant *) * \
		    (global->nb_ant + 1))) == NULL)
    return (NULL);
  ptr_start = parser_return_start_end(global->room, START);
  while (++i < global->nb_ant)
    {
      if ((ant[i] = malloc(sizeof(t_ant))) == NULL)
	return (NULL);
      ant[i]->old_room = NULL;
      ant[i]->current_room = ptr_start;
    }
  ant[i] = NULL;
  return (ant);
}
