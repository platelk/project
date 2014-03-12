/*
** champ.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/struct/mnemoniques
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Mar 20 13:31:48 2012 ronan guiho
** Last update Tue Mar 20 13:36:14 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

t_champ		*search_champ_by_id(t_vm *vm, int id)
{
  int		i;
  t_champ	*tmp;

  i = -1;
  tmp = vm->champ;
  while (++i < id)
      tmp = tmp->next;
  return (tmp);
}
