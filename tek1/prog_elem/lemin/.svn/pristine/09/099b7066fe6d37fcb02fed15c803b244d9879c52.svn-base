/*
** parser_init_ant.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 15:07:31 2012 ronan guiho
** Last update Fri Apr  6 17:13:18 2012 alexis leprovost
*/

#include <stdlib.h>

#include "hex.h"

t_ant		*parser_init_ant(t_glob *global)
{
  int		i;
  t_room	*ptr_start;
  t_ant		*ant;

  i = -1;
  if ((ant = malloc(sizeof(*global->ant) * \
		    (global->nb_ant))) == NULL)
    return (NULL);
  ptr_start = parser_return_start_end(global->room, START);
  while (++i < global->nb_ant)
    {
      ant[i].old_room = NULL;
      ant[i].current_room = ptr_start;
    }
  return (ant);
}
