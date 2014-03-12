/*
** write_valu.c for write_valu.c in /home/platel_k/projet/prog_elem/corewar/corewar/source/ASM/data
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 24 13:57:15 2012 kevin platel
** Last update Thu Mar 22 13:18:41 2012 kevin platel
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

char	*write_int_in_str(int value, char *param)
{
  int	i;
  int	j;
  t_str_int	bloc;

  j = 0;
  i = (octets_from_type(param[0]) - 1);
  bloc.value = value;
  while (i >= 0)
    {
      param[i + 1] = bloc.str[j];
      i--;
      j++;
    }
  return (param);
}

char	*write_valu(t_instruction *instruct, char *line, char *param)
{
  int	value;

  instruct = instruct;
  if (line != NULL)
    value = my_getnbr(line);
  else
    value = -1;
  param = write_int_in_str(value, param);
  return (param);
}
