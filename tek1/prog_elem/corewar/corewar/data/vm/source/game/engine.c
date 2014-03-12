/*
** engine.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/game
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sun Mar 25 17:21:30 2012 alexandre deceneux
** Last update Sun Mar 25 21:28:54 2012 alexis leprovost
*/

#include        <unistd.h>
#include	<stdlib.h>

#include	"corewar.h"
#include	"op.h"

char	*load_mem(t_champ *champ, t_vm *vm)
{
  char	*bin;
  int	i;
  int	lim;
  t_mem	*tmp;

  lim = (champ->data[ADDR] + champ->data[PC]) % MEM_SIZE;
  if ((bin = malloc(sizeof(*bin) * (MAX_BIN_SIZE + 1))) == NULL ||
      champ->data[PC] >= champ->prog_size)
    return (NULL);
  while (vm->mem->indice != lim)
    {
      if ((lim - vm->mem->indice) > 0)
	vm->mem = vm->mem->next;
      else
	vm->mem = vm->mem->before;
    }
  i = -1;
  tmp = vm->mem;
  while (++i < MAX_BIN_SIZE)
    {
      bin[i] = (char)tmp->value;
      tmp = tmp->next;
    }
  bin[i] = '\0';
  return (bin);
}

int	launch_champ(t_champ *champ, t_vm *vm)
{
  t_champ	*tmp;
  char	*bin;

  bin = NULL;
  tmp = champ;
  while (tmp != NULL)
    {
      if (tmp->cycle_instruct == WAIT && (bin = load_mem(tmp, vm)) != NULL)
	{
	  if (tmp->detail != NULL)
	    free(tmp->detail);
	  if ((tmp->detail = get_instruct(bin)) != NULL)
	    {
	      tmp->instruct = tmp->detail[0][0];
	      tmp->cycle_instruct = op_tab[tmp->instruct - 1].nbr_cycles;
	    }
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int	decrease_champ(t_champ *champ)
{
  t_champ	*tmp;

  tmp = champ;
  while (tmp != NULL)
    {
      if (tmp->cycle_instruct > 0)
	tmp->cycle_instruct--;
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int	exec_champ(t_champ *champ, func *instruct, t_vm *vm)
{
  t_champ	*tmp;

  tmp = champ;
  while (tmp != NULL)
    {
      if (tmp->cycle_instruct == READY)
	{
	  key_battel_ground(vm);
	  tmp->cycle_instruct = -1;
	  instruct[tmp->instruct - 1](tmp->detail, tmp, vm, vm->param->nbr_live);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int	engine(t_vm *vm, func *instruct)
{
  if (launch_champ(vm->champ, vm) == EXIT_FAILURE ||
      decrease_champ(vm->champ) == EXIT_FAILURE ||
      exec_champ(vm->champ, instruct, vm) == EXIT_FAILURE ||
      decrease_color(vm->mem) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  usleep(1000);
  return (EXIT_SUCCESS);
}
