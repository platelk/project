/*
** change_label_by_value.c for change_label_by_value in /home/platel_k/projet/prog_elem/corewar/corewar
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jan 26 16:37:07 2012 kevin platel
** Last update Thu Mar 22 15:36:31 2012 alexandre deceneux
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "corewar.h"

int	verif_extend(char *str, int flag)
{
  int	i;

  i = 0;
  if (flag == 1)
    return (0);
  while (str[i])
    {
      if (str[i] == '+' || str[i] == '-')
	return (1);
      i++;
    }
  return (0);
}

char	*remplace_label(char *param, t_instruction *inst,
			t_label *label, int flag)
{
  char	*new;

  if (my_is_instr('%', param) == IS_IN_STR)
    {
      new = malloc(sizeof(*new) * (IND_SIZE + 1));
      new[0] = (T_DIR | T_LAB);
    }
  else if (my_is_instr(':', param) == IS_IN_STR)
    {
      new = malloc(sizeof(*new) * (IND_SIZE + 1));
      new[0] = (T_IND | T_LAB);
    }
  else
    {
      my_puterror("Asm: Missing ':'\n");
      return (NULL);
    }
  if (verif_extend(param, flag))
    {
      print_error_message("Asm: Trailing garbage",
                          *(inst->label->name), inst->name, inst->line);
      return (NULL);
    }
  new = calcul_label(param, label, inst, new);
  return (new);
}

int	change_label_by_value(t_label *label, int flag)
{
  int	i;
  t_instruction	*inst;

  inst = NULL;
  while (label != NULL)
    {
      inst = label->right;
      while (inst != NULL)
	{
	  i = 0;
	  while (inst->arg != NULL && inst->arg[i] != NULL)
	    {
	      if (inst->arg[i][0] & T_LAB)
		if ((inst->arg[i] = remplace_label(&inst->arg[i][1],
						   inst, label, flag)) == NULL)
		  return (1);
	      i++;
	    }
	  inst = inst->right;
	}
      label = label->next;
    }
  return (0);
}
