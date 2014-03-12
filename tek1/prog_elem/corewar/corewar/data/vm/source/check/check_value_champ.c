/*
** check_id_value.c for check_id_value in /home/leprov_a//depot/corewar/source/VM/check
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 18:10:06 2012 alexis leprovost
** Last update Tue Mar 20 14:37:12 2012 alexis leprovost
*/

#include "corewar.h"

int	check_value_champ(int value, t_champ *champ, int flag)
{
  t_champ	*tmp;

  tmp = champ->next;
  while (tmp != NULL)
    {
      if (value == tmp->data[flag])
	return (1);
      tmp = tmp->next;
    }
  tmp = champ->before;
  while (tmp != NULL)
    {
      if (value == tmp->data[flag])
	return (1);
      tmp = tmp->before;
    }
  return (0);
}
