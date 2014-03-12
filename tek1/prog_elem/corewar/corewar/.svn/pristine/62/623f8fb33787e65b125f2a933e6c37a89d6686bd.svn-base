/*
** get_id_champ_min.c for Corewar in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Feb 10 15:40:26 2012 alexis leprovost
** Last update Fri Feb 10 16:56:25 2012 alexis leprovost
*/

#include "corewar.h"

t_champ	*get_champ_min(t_champ *champ)
{
  t_champ	*tmp;
  int	id;
  int	len;

  tmp = champ;
  len = get_champ_number(champ);
  id = -1;
  while (len)
    {
      if (id < 0 || (id > tmp->data[ID]))
	id = tmp->data[ID];
      len--;
      tmp = tmp->next;
    }
  while (tmp->data[ID] != id)
    tmp = tmp->next;
  return (tmp);
}
