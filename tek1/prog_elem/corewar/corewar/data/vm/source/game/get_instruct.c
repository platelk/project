/*
** get_instruct.c for get_instruct in /home/vink/projet/prog_elem/corewar/corewar/source/VM
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb 29 10:17:05 2012 kevin platel
** Last update Sun Mar 25 03:05:03 2012 ronan guiho
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

int	get_size_param(int type)
{
  if (type == T_DIR)
    return (DIR_SIZE);
  if (type == T_IND)
    return (IND_SIZE);
  if (type == T_REG)
    return (1);
  return (0);
}

int	get_type_param(int nb, char id, unsigned char parm)
{
  int	i;
  int	dec;

  dec = 3;
  i = 0;
  if (id == 12 || id == 9)
    return (T_IND);
  if (id == 1 || id == 9 || id == 12 || id == 15)
    return (op_tab[id - 1].type[0]);
  while (i < (4 - nb))
    {
      parm = parm >> 2;
      i++;
    }
  if ((id == 10 || id == 14) && (nb == 1 || nb == 2) && (dec & parm) != 1)
    return (T_IND);
  if (id == 11 && (nb == 2 || nb == 3) && ((dec & parm) != 1))
    return (T_IND);
  if ((dec & parm) == 1)
    return (T_REG);
  if ((dec & parm) == 2)
    return (T_DIR);
  if ((dec & parm) == 3)
    return (T_IND);
  return (0);
}

char **get_param(char **inst, char *bin, int *v)
{
  int	i;
  unsigned char	parm;
  int j;

  i = 0;
  parm = 0;
  if (inst[0][0]  != 9 && inst[0][0] != 1
      && inst[0][0] != 12 && inst[0][0] != 15)
    {
      parm = bin[*v];
      *(v) = *(v) + 1;
    }
  while (++i <= op_tab[inst[0][0] - 1].nbr_args)
    {
      inst[i] =	malloc((get_size_param(get_type_param(i,
		        inst[0][0], parm)) + 2) * sizeof(**inst));
      inst[i][0] = get_type_param(i, inst[0][0], parm);
	      get_size_param(get_type_param(i, inst[0][0], parm));
      j = -1;
      while (++j < (get_size_param(get_type_param(i, inst[0][0], parm))))
	inst[i][j + 1] = bin[*v + j];
      *(v) = *(v) + get_size_param(get_type_param(i, inst[0][0], parm));
    }
  inst[i] = NULL;
  return (inst);
}

char 	**get_instruct(char *bin)
{
  int	id;
  char	**inst;
  int	v;

  v = 0;
  if (bin == NULL)
    return (NULL);
  id = (unsigned char) bin[v];
  if (id <= 0 || id > 16)
    return (NULL);
  inst = malloc((op_tab[id - 1].nbr_args + 2) * sizeof(*inst));
  if (inst == NULL)
    return (NULL);
  inst[0] = malloc(2 * sizeof(**inst));
  inst[0][0] = id;
  v++;
  inst = get_param(inst, bin, &v);
  inst[0][1] = v;
  return (inst);
}
