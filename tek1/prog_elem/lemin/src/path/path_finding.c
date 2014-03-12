/*
** path_finding.c for lemin in /home/vink/projet/prog_elem/lemin/src/path
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Apr  9 11:15:32 2012 kevin platel
** Last update Wed Apr 11 09:08:18 2012 matthieu przybylski
*/

#include <stdlib.h>
#include "lemin.h"

static int	check_end(t_ant **ant)
{
  int	i;

  i = 0;
  while (ant[i])
    {
      if (ant[i]->current_room->status != END)
	return (1);
      i++;
    }
  return (0);
}

static t_room	*find_best_path(t_ant *ant, t_room *room)
{
  int		i;
  t_room	*new_room;

  i = 0;
  new_room = ant->current_room;
  while (room->link[i])
    {
      if (((new_room->weight + new_room->occ) >
	   (room->link[i]->weight + room->link[i]->occ)
	   && room->link[i]->occ == 0)
	  || room->link[i]->status == END)
	{
	  new_room = room->link[i];
	}
      i++;
    }
  return (new_room);
}

int	is_there_more_ant(t_glob *glob, int *print, int i)
{
  if (!glob->ant[i + 1])
    {
      my_putchar('\n');
      *print = 0;
      return (0);
    }
  return (i + 1);
}

t_glob	*path_finding(t_glob *glob)
{
  int		i;
  int		print;
  t_room	*room;

  i = 0;
  print = 0;
  while (check_end(glob->ant))
    {
      if (glob->ant[i]->current_room->status != END)
	{
	  room = find_best_path(glob->ant[i], glob->ant[i]->current_room);
	  if (room != NULL)
	    {
	      if (print > 0)
		my_putchar(' ');
	      room->occ = 1;
	      print_action(room, i + 1, glob->ant[i]);
	      print++;
	    }
	}
      i = is_there_more_ant(glob, &print, i);
    }
  return (0);
}
