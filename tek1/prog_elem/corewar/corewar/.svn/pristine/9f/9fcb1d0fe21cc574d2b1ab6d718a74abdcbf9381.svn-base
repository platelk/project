/*
** dump_reg.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 16:37:15 2012 ronan guiho
** Last update Tue Mar 20 14:41:51 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"
#include "op.h"
#include "vm.h"
#include "param.h"

int	*dump_reg(t_param *param, int id)
{
  int	i;
  int	*reg;

  i = 0;
  if ((reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    return (NULL);
  reg[i] = id;
  while (++i < REG_NUMBER)
    if (param->rand_reg == 0)
      reg[i] = 0;
    else
      reg[i] = get_rand_number(MAX);
  return (reg);
}
