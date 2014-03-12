/*
** print.c for lemin in /home/vink/projet/prog_elem/lemin/src/path
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Apr  9 13:46:07 2012 kevin platel
** Last update Tue Apr 10 14:35:06 2012 matthieu przybylski
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

void	print_room(t_room *room)
{
  int	i;

  while (room)
    {
      my_printf("\n--------\n");
      my_printf("Name : %s\n", room->name);
      my_printf("Weight : %d\n", room->weight);
      my_printf("Status : %d\n", room->status);
      for (i = 0; room->link[i] != NULL; i++)
	{
	  my_printf("\tLink->Name : %s\n", room->link[i]->name);
	  my_printf("\tLink->Weight : %d\n", room->link[i]->weight);
	}
      my_printf("\n--------\n");
      room = room->next;
    }
}

void	print_action(t_room *room, int ind_ant, t_ant *ant)
{
  if (ant != NULL && room->status != START)
    {
      if (ant->current_room != NULL)
	ant->current_room->occ = 0;
      ant->old_room = ant->current_room;
      ant->current_room = room;
      ant->current_room->occ = 1;
      my_printf("P%d-%s", ind_ant, ant->current_room->name, room->occ);
    }
}
