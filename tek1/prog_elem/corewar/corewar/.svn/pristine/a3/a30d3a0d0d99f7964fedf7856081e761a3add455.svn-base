/*
** get_id_available.c for Corewar in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 16:28:36 2012 alexis leprovost
** Last update Fri Mar 23 15:23:46 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"

int	get_id_available(t_champ *champ)
{
  if (champ->data[ID] < 0)
    champ->data[ID] = champ->data[ID] * (-1);
  if (check_value_champ(champ->data[ID], champ, ID))
    {
      my_printf("Corewar: Warning: %s has the same id as \
 another champion.\n", champ->prog_name);
      return (-1);
    }
  return (0);
}
