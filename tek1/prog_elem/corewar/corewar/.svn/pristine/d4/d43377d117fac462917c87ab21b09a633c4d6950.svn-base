/*
** if_pc_in_case.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/struct/mnemoniques
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Fri Mar 16 14:19:50 2012 alexandre deceneux
** Last update Mon Mar 19 11:26:35 2012 alexandre deceneux
*/

#include "corewar.h"

int	get_mnemo_size(char **params)
{
  int	size;
  int	i;

  size = (**params == 1 || **params == 12 || **params == 15);
  while (params[i])
    {
      if (params[i][0] & T_REG)
	size += REG_SIZE;
      if (params[i][0] & T_IND)
	size += IND_SIZE;
      if (params[i][0] & T_DIR)
	size += DIR_SIZE;
      i++;
    }
  return (0);
}

int	if_pc_in_case(char **params, t_champ *champ, int addr)
{
  if (addr - get_mnemo_size(params)
      < champ->data[ADDR])
    return (0);
  if (addr - get_mnemo_size(params)
      > champ->data[ADDR] + champ->prog_size)
    return (0);
  return (1);
}
