/*
** get_type_param.c for get_type_param in /home/platel_k/projet/prog_elem/corewar/corewar
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 24 15:46:35 2012 kevin platel
** Last update Fri Mar 23 15:50:56 2012 alexandre deceneux
*/

#include <stdlib.h>
#include "corewar.h"

char    *get_type_param2(char *line, char *param)
{
  if (line[0] == DIRECT_CHAR)
    {
      param = malloc((DIR_SIZE + 1) * sizeof(*param));
      param[0] = T_DIR;
    }
  else if (my_str_isnum(line))
    {
      param = malloc((IND_SIZE + 1) * sizeof(*param));
      param[0] = T_IND;
    }
  return (param);
}

char	*get_type_param(char *line)
{
  char	*param;

  param = NULL;
  if (line[0] == 'r')
    {
      param = malloc(2 * sizeof(*param));
      param[0] = T_REG;
    }
  else if (my_is_instr(LABEL_CHAR, line) == IS_IN_STR)
    {
      param = my_strdup(line);
      param = add_char_to_begin(param, ' ');
      my_is_instr(LABEL_CHAR, line) ? (param[0] = T_LAB | T_DIR) :
	(param[0] = T_LAB | T_IND);
    }
  else
    param = get_type_param2(line, param);
  return (param);
}
