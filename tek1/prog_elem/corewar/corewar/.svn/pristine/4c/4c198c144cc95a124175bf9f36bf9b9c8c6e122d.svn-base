/*
** mnemo_11-15.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/VM/source/struct/mnemoniques
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Tue Mar 13 15:50:14 2012 alexandre deceneux
** Last update Tue Apr  3 15:43:44 2012 kevin platel
*/

#include "corewar.h"
#include "vm.h"
#include "mnemos.h"

void    sti(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	v1;
  to_int	v2;
  to_int	reg;
  int	addr;

  v1.value = 0;
  v2.value = 0;
  reg.value = 0;
  params[0][0] = ACTIF;
  get_param_value(&v1, params[2], champ);
  get_param_value(&v2, params[3], champ);
  get_param_value(&reg, params[1], champ);
  addr = v1.value + v2.value;
  addr = addr % MEM_SIZE;
  addr < 0 ? (addr = MEM_SIZE + addr) : (addr = addr);
  if (!flag || (addr >= champ->data[ADDR] &&
		addr <= champ->data[ADDR] + champ->prog_size))
      modif_mem_case(champ, vm->mem, reg.param, addr);
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] sti (r%d=%d -> i@pc+(d=%d + d=%d))\n", champ->data[PC],
	      (int)params[1][1], champ->reg[(int)params[1][1] - 1],
	      v1.value, v2.value);
}

void    ifork(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  int	addr;
  t_champ	*tmp;

  tmp = champ;
  flag = flag;
  size.value = 0;
  get_param_value(&size, params[1], champ);
  params[0][0] = ACTIF;
  addr = (size.value % IDX_MOD) + champ->data[PC];
  addr = addr % MEM_SIZE;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = add_champ(champ, addr);
  tmp->next->before = tmp;
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] fork (%d)\n", champ->data[PC], size.value);
}

void    lld(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int        size;
  int   value;
  int   addr;

  size.value = 0;
  value = 0;
  get_param_value(&size, params[1], champ);
  addr = (size.value + champ->data[ADDR] + champ->data[PC]
    + 2 + get_size_param(params[1][0]));
  params[0][0] = ACTIF;
  if (params[1][0] == T_REG)
    {
      champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
      champ->reg[(int)params[2][1] - 1] = champ->reg[(int)params[1][1] - 1];
    }
  else
    if (!flag || (addr >= champ->data[ADDR] &&
		  addr <= champ->data[ADDR] + champ->prog_size))
      {
	value = get_mem_case(champ, vm->mem, addr, get_size_param(params[1][0]));
	champ->reg[(int)params[2][1] - 1] = value;
	champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
      }
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
}

void    lldi(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  to_int	s;
  int	addr;

  size.value = 0;
  s.value = 0;
  get_param_value(&size, params[1], champ);
  params[0][0] = ACTIF;
  addr = (size.value + champ->data[ADDR] + champ->data[PC] + 1 +   \
    get_size_param(params[1][0]) +  get_size_param(params[2][0]) + \
    get_size_param(params[3][0]));
  addr = addr % MEM_SIZE;
  if (!flag || (addr >= champ->data[ADDR] &&
		addr <= champ->data[ADDR] + champ->prog_size))
    {
      get_param_value(&size, params[2], champ);
      s.value = get_mem_case(champ, vm->mem, addr, IND_SIZE) + size.value - 1;
      addr = (s.value + champ->data[ADDR] + champ->data[PC] + 1 +      \
	get_size_param(params[1][0]) +  get_size_param(params[2][0]) + \
	      get_size_param(params[3][0])) % MEM_SIZE;
      champ->reg[(int)params[3][1]] = get_mem_case(champ, vm->mem, addr, 4);
      champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
    }
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
}

void    lfork(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  int	addr;
  t_champ	*tmp;

  tmp = champ;
  flag = flag;
  size.value = 0;
  get_param_value(&size, params[1], champ);
  params[0][0] = ACTIF;
  addr = size.value + champ->data[PC];
  addr = addr % MEM_SIZE;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = add_champ(champ, addr);
  tmp->next->before = tmp;
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] fork (%d)\n", champ->data[PC], size.value);
  (champ->data[CARRY] != 1) ? (champ->data[CARRY] = 1) : (42);
}
