/*
** fill_struct_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 14:48:34 2012 ronan guiho
** Last update Tue Mar 20 16:07:37 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"
#include "param.h"
#include "champ.h"
#include "data_champ.h"
#include "vm.h"

int		fill_struct_champ(t_champ *champ, t_data_champ *data)
{
  if ((get_bin(champ, data->name)) == 1 ||
      (champ->data = fill_data(data)) == NULL)
    return (1);
  champ->instruct = -1;
  champ->cycle_instruct = -1;
  champ->detail = NULL;
  return (0);
}
