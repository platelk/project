/*
** write_argument.c for Corewar in /home/guiho_r//tek1/corewar/source/ASM/write
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Jan 25 09:53:53 2012 ronan guiho
** Last update Wed Mar 21 14:16:25 2012 alexandre deceneux
*/

#include <stdlib.h>
#include <unistd.h>

#include "corewar.h"
#include "label.h"
#include "instruction.h"

int	write_argument(int fd, t_instruction *instruct, char id_name)
{
  int	i;
  int	len;
  char	*print_arg;

  i = 0;
  len = 0;
  while (instruct && instruct->arg && instruct->arg[i])
    {
      if ((print_arg = cast_param(id_name, instruct->arg[i], i, &len)) != NULL)
	{
	  write(fd, print_arg, len);
	  free(print_arg);
	}
      i++;
    }
  return (0);
}
