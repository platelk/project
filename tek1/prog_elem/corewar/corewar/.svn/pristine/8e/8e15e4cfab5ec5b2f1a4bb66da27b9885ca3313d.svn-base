/*
** color_decrementation.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/struct/mnemoniques
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Mar 20 13:39:13 2012 ronan guiho
** Last update Sat Mar 24 18:37:29 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void		aff_mem(t_vm *vm)
{
  int		i;
  t_mem		*tmp;

  i = -1;
  tmp = vm->mem;
  while (++i <= MEM_SIZE)
    {
      if (tmp->state != NONE)
	{
	  if (tmp->state == LIVES)
	    disp_live_mem(vm, tmp);
	  else if (tmp->state == WRITE)
	    disp_write_mem(vm, tmp);
	  else if (tmp->state == READ)
	    disp_read_mem(vm, tmp);
	  else if (tmp->state == ACTIF)
	    disp_actif_mem(vm, tmp);
	 tmp->state = NONE;
	}
      tmp = tmp->next;
    }
}
