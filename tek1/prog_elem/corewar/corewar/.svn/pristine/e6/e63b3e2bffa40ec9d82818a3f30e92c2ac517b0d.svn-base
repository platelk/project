/*
** get_champ_number.c for get_champ_number in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 17:43:54 2012 alexis leprovost
** Last update Tue Mar 20 14:21:55 2012 alexis leprovost
*/

#include "corewar.h"

int	get_champ_number(t_champ *champ)
{
  t_champ	*tmp;
  int	len;

  len = 0;
  tmp = champ;
  while (tmp != NULL)
    {
      ++len;
      tmp = tmp->next;
    }
  return (len);
}
