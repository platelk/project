/*
** fcts_adds.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/struct/mnemoniques
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sun Mar 25 16:27:55 2012 alexandre deceneux
** Last update Tue Apr  3 13:57:14 2012 kevin platel
*/

#include "corewar.h"

void    ld_ind(int flag, t_champ *champ, t_vm *vm, char **params)
{
  int           value;
  to_int        size;
  int           addr;

  get_param_value(&size, params[1], champ);
  addr = (size.value % IDX_MOD) + champ->data[ADDR] + champ->data[PC]
    + 2 + get_size_param(params[1][0]);
  addr = addr % MEM_SIZE;
  if (!flag || (addr >= champ->data[ADDR] &&
                addr <= champ->data[ADDR] + champ->prog_size))
    {
      value = get_mem_case(champ, vm->mem, addr, get_size_param(params[1][0]));
      champ->reg[(int)params[2][1] - 1] = value;
    }
}

void	live_win(t_champ *champ, t_vm *vm, to_int id)
{
  t_champ	*tmp;

  tmp = champ;
  while (tmp != NULL && tmp->before != NULL)
    tmp = tmp->before;
  while (tmp != NULL && tmp->data[ID] != id.value)
    tmp = tmp->next;
  if (tmp != NULL)
    {
      tmp->data[LIVE]++;
      vm->winner = tmp;
    }
}
