/*
** get_param_value.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/VM/source/struct
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Tue Mar 13 14:58:47 2012 alexandre deceneux
** Last update Sun Mar 25 18:59:11 2012 alexis leprovost
*/

#include "corewar.h"

int	get_addr(to_int *convert, char *param)
{
  int i;

  i = -1;
  if (param[0] & T_DIR)
    while (++i < 4)
      convert->param[3 - i] = param[i + 1];
  else if (param[0] & T_IND)
    while (++i < IND_SIZE)
      convert->param[3 - i] = param[i + 1];
  else
    convert->value = -1;
  return (convert->value);
}

int     get_param_value(to_int *convert, char *param, t_champ *champ)
{
  int   i;

  i = -1;
  convert->value = 0;
  if (param[0] & T_DIR)
    while (++i < 4)
      convert->param[3 - i] = param[i + 1];
  else if (param[0] & T_IND)
    {
      while (++i < IND_SIZE)
	convert->param[i] = param[IND_SIZE - i];
      convert->value = (short)convert->value;
    }
  else if (param[0] & T_REG)
    convert->value = champ->reg[(int)param[1] - 1];
  else
    return (-1);
  return (0);
}
