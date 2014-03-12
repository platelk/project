/*
** weighting.c for lemin in /home/vink/projet/prog_elem/lemin/src/path
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Apr  9 13:42:17 2012 kevin platel
** Last update Thu Apr 12 09:53:49 2012 kevin platel
*/

#include <stdlib.h>
#include "lemin.h"

static int	attribute_weight_loop(t_room *room, int weight, int start)
{
  int	i;

  i = 0;
  if (room == NULL)
    return (0);
  while (room->link[i] != NULL)
    {
      if (room->link[i]->weight == -1 || room->link[i]->weight > weight)
	{
	  room->link[i]->weight = weight;
	  if (room->link[i]->status == START)
	    start = 1;
	  start = attribute_weight_loop(room->link[i], weight + 2, start);
	}
      i++;
    }
  return (start);
}

t_glob	*weighting(t_glob *glob)
{
  t_room	*room_end;
  room_end = parser_return_start_end(glob->room, END);
  room_end->weight = 0;
  if (attribute_weight_loop(room_end, 2, 0) < 1)
    {
      my_printf("Error : END and Start are not linked\n");
      return (NULL);
    }
  return (glob);
}

