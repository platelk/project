/*
** free_vm.c for vm in /home/leprov_a//depot/corewar/source/VM/free
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar  7 15:36:37 2012 alexis leprovost
** Last update Sun Mar 25 20:22:48 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"corewar.h"

void	free_mem(t_mem *mem)
{
  t_mem	*tmp;
  int	i;

  i = -1;
  while (++i < MEM_SIZE)
    {
      tmp = mem->next;
      free(mem);
      mem = tmp;
    }
}

void	free_vm(t_vm *vm)
{
  if (vm->mem != NULL)
    free_mem(vm->mem);
  if (vm->param != NULL)
    free(vm->param);
  if (vm->sound != NULL)
    {
      free(vm->sound[EVENT]);
      free(vm->sound[AMB]);
      free(vm->sound);
    }
  free(vm);
}
