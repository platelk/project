/*
** mnemo_6-10.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/struct/mnemoniques
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sun Mar 25 14:56:35 2012 alexandre deceneux
** Last update Tue Apr  3 15:34:25 2012 kevin platel
*/

#include "corewar.h"
#include "vm.h"
#include "mnemos.h"

void	and(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	v1;
  to_int	v2;

  flag = flag;
  get_param_value(&v1, params[1], champ);
  get_param_value(&v2, params[2], champ);
  params[0][0] = ACTIF;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] and (d=%d & d=%d",
	      champ->data[PC], v1.value, v2.value);
  champ->reg[(int)params[3][1] - 1] = v1.value & v2.value;
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf(" -> r%d=%d) carry=%d\n", (int)params[3][1],
	      champ->reg[(int)params[3][1] - 1], champ->data[CARRY]);
}

void    or(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	v1;
  to_int	v2;

  flag = flag;
  get_param_value(&v1, params[1], champ);
  get_param_value(&v2, params[2], champ);
  params[0][0] = ACTIF;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] and (d=%d | d=%d",
	      champ->data[PC], v1.value, v2.value);
  champ->reg[(int)params[3][1] - 1] = v1.value | v2.value;
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf(" -> r%d=%d) carry=%d\n", (int)params[3][1],
	      champ->reg[(int)params[3][1] - 1], champ->data[CARRY]);
}

void    xor(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	v1;
  to_int	v2;

  flag = flag;
  get_param_value(&v1, params[1], champ);
  get_param_value(&v2, params[2], champ);
  params[0][0] = ACTIF;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] and (d=%d | d=%d",
	      champ->data[PC], v1.value, v2.value);
  champ->reg[(int)params[3][1] - 1] = v1.value ^ v2.value;
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf(" -> r%d=%d) carry=%d\n", (int)params[3][1],
	      champ->reg[(int)params[3][1] - 1], champ->data[CARRY]);
}

void    zjmp(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  int	addr;

  flag = flag;
  size.value = 0;
  params[0][0] = ACTIF;
  get_param_value(&size, params[1], champ);
  addr = ((size.value % IDX_MOD) + champ->data[PC]);
  addr = addr % MEM_SIZE;
  if (champ->data[CARRY])
    champ->data[PC] = addr;
  else
    champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  color_mem_case(champ, vm->mem, params[0]);
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] zjump (%d) carry=%d\n", champ->data[PC],
	      size.value, champ->data[CARRY]);
}

void    ldi(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  to_int	s;
  int	addr;

  size.value = 0;
  s.value = 0;
  get_param_value(&size, params[1], champ);
  params[0][0] = ACTIF;
  addr = ((size.value % IDX_MOD) + champ->data[ADDR] + champ->data[PC] + 1 + \
	  get_size_param(params[1][0]) +  get_size_param(params[2][0]) + \
	  get_size_param(params[3][0]));
  if (!flag || (addr >= champ->data[ADDR] &&
		addr <= champ->data[ADDR] + champ->prog_size))
    {
      get_param_value(&size, params[2], champ);
      s.value = get_mem_case(champ, vm->mem, addr, IND_SIZE) + size.value;
      addr = ((s.value % IDX_MOD) + champ->data[ADDR] + champ->data[PC] + 1 + \
	get_size_param(params[1][0]) +  get_size_param(params[2][0]) + \
	get_size_param(params[3][0]));
      champ->reg[(int)params[3][1] - 1] = get_mem_case(champ,
						       vm->mem, addr, 4);
      champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
    }
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
}
