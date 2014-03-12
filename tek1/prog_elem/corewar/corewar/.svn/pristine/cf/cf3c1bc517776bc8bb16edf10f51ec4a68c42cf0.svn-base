/*
** sort_champ.c for Corewar in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Feb 10 15:19:24 2012 alexis leprovost
** Last update Tue Mar 20 14:17:38 2012 alexis leprovost
*/

#include "corewar.h"

void	sort_champ(t_champ **begin, int limit)
{
  t_champ       *tmp;

  while (limit > 0)
    {
      tmp = *begin;
      while (tmp != NULL && tmp->next != NULL)
        {
          if (tmp->data[ID] > tmp->next->data[ID])
	    swap_champ(&tmp, begin);
          tmp = tmp->next;
        }
      limit--;
    }
}
