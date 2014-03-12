/*
** mnemo_16.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/VM/source/struct/mnemoniques
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Tue Mar 13 15:51:35 2012 alexandre deceneux
** Last update Sun Mar 25 18:57:44 2012 alexis leprovost
*/

#include "corewar.h"
#include "vm.h"

void    aff(char **params, t_champ *champ, t_vm *vm, int flag)
{
  to_int        convert;

  flag = flag;
  convert.value = 0;
  params[0][0] = ACTIF;
  get_param_value(&convert, params[1], champ);
  my_putchar(convert.value % 256);
  champ->data[PC] = (champ->data[PC] + params[0][1]) % MEM_SIZE;
  color_mem_case(champ, vm->mem, params[0]);
  if (vm->no_graph == EXIT_FAILURE)
    my_printf("[%d] aff (%d)\n", champ->data[PC], convert.value);
}
