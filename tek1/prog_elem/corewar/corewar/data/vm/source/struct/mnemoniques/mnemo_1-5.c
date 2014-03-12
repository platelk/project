/*
** mnemo_1-5.c for Corewar in /home/guiho_r/tek1/corewar/data/vm/source/game
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Sun Mar 25 03:14:08 2012 ronan guiho
** Last update Tue Apr  3 15:15:50 2012 kevin platel
*/

#include "corewar.h"
#include "vm.h"
#include "mnemos.h"

void	live(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	id;
  int	i;
  int	save;

  flag = flag;
  id.value = 0;
  i = -1;
  while (++i < 4)
    id.param[i] = params[1][4 - i];
  params[0][0] = LIVES;
  live_win(champ, vm, id);
  save = champ->reg[0];
  champ->reg[0] = id.value;
  color_mem_case(champ, vm->mem, params[0]);
  champ->reg[0] = save;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] live (%d)\n", champ->data[PC], id.value);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  (champ->data[CARRY] != 1) ? (champ->data[CARRY] = 1) : (42);
}

void    ld(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  int		value;

  size.value = 0;
  value = 0;
  get_param_value(&size, params[1], champ);
  params[0][0] = ACTIF;
  if (params[1][0] == T_REG)
    champ->reg[(int)params[2][1] - 1] = champ->reg[(int)params[1][1] - 1];
  else if (params[1][0] == T_IND)
    ld_ind(flag, champ, vm, params);
  if (params[1][0] == T_DIR)
    champ->reg[(int)params[2][1] - 1] = size.value;
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] ld (d=%d -> r%d) carry=%d\n", champ->data[PC], size.value,
	      (int)params[2][1], champ->data[CARRY]);
  champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
}

void	st(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int	size;
  int	addr;
  to_int	reg;

  size.value = 0;
  reg.value = champ->reg[(int)params[1][1] - 1];
  get_param_value(&size, params[2], champ);
  addr = (size.value % IDX_MOD) + champ->data[ADDR] + champ->data[PC]
    + 2 + get_size_param(params[2][0]);
  addr = addr % MEM_SIZE;
  params[0][0] = ACTIF;
  if (params[2][0] == T_REG)
    champ->reg[(int)params[2][1] - 1] = champ->reg[(int)params[1][1] - 1];
  else
    {
      if (!flag || (addr >= champ->data[ADDR] &&
		    addr <= champ->data[ADDR] + champ->prog_size))
	modif_mem_case(champ, vm->mem, reg.param, addr);
    }
  color_mem_case(champ, vm->mem, params[0]);
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] st (r%d=%d -> i@pc+%d)\n", champ->data[PC],
	      (int)params[1][1], reg.value, size.value);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
}

void    add(char **params, t_champ *champ, t_vm *vm, int flag)
{
  flag = flag;
  params[0][0] = ACTIF;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] add (r%d=%d + r%d=%d",
	      champ->data[PC],
	      (int)params[1][1], champ->reg[(int)params[1][1] - 1],
	      (int)params[2][1], champ->reg[(int)params[2][1] - 1]);
  champ->reg[(int)params[3][1] - 1] = champ->reg[(int)params[1][1] - 1]
    + champ->reg[(int)params[2][1] - 1];
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
  if (vm->no_graph == EXIT_FAILURE)
    my_printf(" -> r%d=%d) carry=%d\n",
	      (int)params[3][1], champ->reg[(int)params[3][1] - 1],
	      champ->data[CARRY]);
}

void    sub(char **params, t_champ *champ, t_vm *vm, int flag)
{
  flag = flag;
  params[0][0] = ACTIF;
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] add (r%d=%d + r%d=%d",
	      champ->data[PC],
	      (int)params[1][1], champ->reg[(int)params[1][1] - 1],
	      (int)params[2][1], champ->reg[(int)params[2][1] - 1]);
  champ->reg[(int)params[3][1] - 1] = champ->reg[(int)params[1][1] - 1]
    - champ->reg[(int)params[2][1] - 1];
  color_mem_case(champ, vm->mem, params[0]);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  champ->data[CARRY] != 1 ? (champ->data[CARRY] = 1) : (42);
  if (vm->no_graph == EXIT_FAILURE)
    my_printf(" -> r%d=%d) carry=%d\n",
	      (int)params[3][1], champ->reg[(int)params[3][1] - 1],
	      champ->data[CARRY]);
}
