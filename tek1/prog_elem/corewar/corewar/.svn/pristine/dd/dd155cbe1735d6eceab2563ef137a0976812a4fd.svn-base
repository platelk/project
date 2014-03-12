/*
** spawn_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 17:02:09 2012 ronan guiho
** Last update Fri Feb 10 16:14:28 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"
#include "vm.h"
#include "param.h"

int	*spawn_champ(t_data_champ *data_champ)
{
  int	*data;

  if ((data = malloc(sizeof(int) * (SIZE_DATA + 1))) == NULL)
    return (NULL);
  data[ADDR] = data_champ->addr;
  data[ID] = data_champ->id;
  data[CARRY] = 0;
  data[PC] = 0;
  data[LIVE] = 0;
  return (data);
}
