/*
** get_char_param.c for Corewar in /home/guiho_r//tek1/corewar/source/ASM/write
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Tue Jan 24 14:54:01 2012 ronan guiho
** Last update Wed Mar 21 14:15:47 2012 alexandre deceneux
*/

#include <unistd.h>

#include "op.h"
#include "instruction.h"

char	value_of_type(int type)
{
  if (type & T_REG)
    return (1);
  else if (type & T_IND)
    return (3);
  else if (type & T_DIR)
    return (2);
  return (0);
}

int		get_char_param(int fd, t_instruction *instruct)
{
  int		i;
  unsigned char		type;
  unsigned char		print;

  i = 0;
  type = 0;
  print = 0;
  while (instruct && instruct->arg && instruct->arg[i])
    {
      type = value_of_type((char)instruct->arg[i][0]);
      print = print | type;
      print = print << 2;
      i++;
    }
  i++;
  while (i < MAX_ARGS_NUMBER)
    {
      print = print << 2;
      i++;
    }
  write(fd, &print, 1);
  return (0);
}
