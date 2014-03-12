/*
** swap_champ.c for Corewar in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Feb 10 15:58:48 2012 alexis leprovost
** Last update Tue Mar 20 13:57:17 2012 alexis leprovost
*/

#include "corewar.h"

void	swap_champ(t_champ **champ, t_champ **begin)
{
  t_champ	*next;
  t_champ	*before;

  next = (*champ)->next;
  before = (*champ)->before;
  if (before == NULL)
    *begin = next;
  else
    before->next = next;
  if (next != NULL)
    {
      next->before = before;
      (*champ)->next = next->next;
      next->next = *champ;
    }
  (*champ)->before = next;
}
