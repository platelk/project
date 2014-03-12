/*
** get_addr_available.c for Exam in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Feb 10 14:24:08 2012 alexis leprovost
** Last update Thu Mar 22 12:51:04 2012 alexis leprovost
*/

#include "corewar.h"

int	get_addr_available(t_champ *champ, int nb)
{
  if (champ->data[ADDR] < 0)
    champ->data[ADDR] = ((champ->data[ADDR] * (-1)) - 1) \
      * (MEM_SIZE / nb);
  champ->data[ADDR] %= MEM_SIZE;
  if (check_value_champ(champ->data[ADDR], champ, ADDR))
    {
      my_printf("Corewar: Warning: %s has the same addr as \
another champion.\n", champ->prog_name);
      return (-1);
    }
  return (0);
}
