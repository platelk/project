/*
** get_param.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Wed Mar 21 14:25:03 2012 alexandre deceneux
** Last update Fri Mar 23 16:43:42 2012 alexandre deceneux
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"

char	**get_param(char **line, t_instruction *instruct)
{
  int	i;
  char	**param;

  i = 0;
  while (line != NULL && line[i] != NULL)
    i++;
  param = malloc((i + 1) * sizeof(*param));
  i = 0;
  while (line != NULL && line[i] != NULL && my_is_instr(';', line[i]) == -1
	 && my_is_instr('#', line[i]) == -1)

    {
      param[i] = get_type_param(line[i]);
      if (param[i] == NULL)
	return (NULL);
      else if (!(param[i][0] & T_LAB))
	param[i] = write_valu(instruct, line[i], param[i]);
      i++;
    }
  param[i] = NULL;
  return (param);
}
