/*
** parser_room_analize.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr  5 13:11:05 2012 ronan guiho
** Last update Mon Apr  9 10:49:45 2012 ronan guiho
*/

#include <stdlib.h>

#include "hex.h"

int		parser_room_analize_name_pos(t_room *room)
{
  t_room	*tmp;
  t_room	*tmp1;

  tmp = room;
  while (tmp != NULL)
    {
      tmp1 = room;
      while (tmp1 != NULL)
	{
	  if (my_strcmp(tmp->name, tmp1->name) == 0 && tmp != tmp1)
	    {
	      my_printf("lemin: warning: two rooms are the same name\n");
	      return (EXIT_FAILURE);
	    }
	  if (((tmp1->coord[0] == tmp->coord[0]) && \
	       (tmp1->coord[1] == tmp->coord[1])) && (tmp != tmp1))
	    {
	      my_printf("lemin: warning: two rooms are the same position\n");
	      return (EXIT_FAILURE);
	    }
	  tmp1 = tmp1->next;
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		parser_room_analize_start_end(t_room *list)
{
  t_room	*tmp;
  int		status[2];

  tmp = list;
  status[0] = 0;
  status[1] = 0;
  while (tmp)
    {
      if (tmp->status == START)
	status[0] = 1;
      else if (tmp->status == END)
	status[1] = 1;
      tmp = tmp->next;
    }
  if (status[0] == 1 && status[1] == 1)
    return (EXIT_SUCCESS);
  else if (status[0] == 0 || status[1] == 0)
    {
      my_printf("lemin: error: start or end instruction missing\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	parser_room_analize(t_room *list)
{
  if ((parser_room_analize_name_pos(list)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((parser_room_analize_start_end(list)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
