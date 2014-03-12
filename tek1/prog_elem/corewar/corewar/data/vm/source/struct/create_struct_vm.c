/*
** create_struct_vm.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jan 27 13:52:37 2012 ronan guiho
** Last update Sun Mar 25 17:24:00 2012 alexis leprovost
*/

#include <stdlib.h>

#include "param.h"
#include "corewar.h"
#include "data_champ.h"
#include "vm.h"
#include "op.h"

t_vm		*create_struct_vm(int ac, char **av)
{
  t_vm		*vm;
  t_data_champ	*data;
  t_param	*param;

  if ((vm = malloc(sizeof(*vm))) == NULL)
    return (NULL);
  if ((param = malloc(sizeof(*param))) == NULL)
    return (NULL);
  param->dump = -1;
  param->rand_mem = 0;
  param->rand_reg = 0;
  param->nbr_live = NBR_LIVE;
  vm->param = param;
  if ((data = treatment_data_champ(ac, av, param)) == NULL ||
      (vm->champ = treatment_champ(data)) == NULL ||
      check_champ(vm->champ, vm->param) == -1)
    return (NULL);
  free_data_champ(data);
  vm->nb_champ = get_champ_number(vm->champ);
  sort_champ(&vm->champ, vm->nb_champ);
  vm->mem = dump_mem(param);
  vm->winner = NULL;
  pop_champ(vm->champ, vm->mem);
  return (vm);
}
