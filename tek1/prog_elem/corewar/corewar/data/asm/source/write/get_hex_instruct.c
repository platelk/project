/*
** get_hex_instruct.c for Corewar in /home/guiho_r//tek1/corewar/source/ASM/write
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jan 24 13:49:58 2012 ronan guiho
** Last update Tue Feb  7 18:36:39 2012 alexis leprovost
*/

#include <unistd.h>

#include "op.h"
#include "corewar.h"
#include "instruction.h"

char	get_hex_instruct(int fd, t_instruction *instruct)
{
  int	i;
  char	value;

  i = 0;
  if (instruct != NULL)
    {
      while (op_tab[i].mnemonique != NULL &&
	     my_strcmp(instruct->name, op_tab[i].mnemonique) != 0)
	i++;
      value = op_tab[i].code;
      write(fd, &value, 1);
      if ((int)value != 1 && (int)value != 12 &&
	  (int)value != 15 && (int)value != 9)
	get_char_param(fd, instruct);
    }
  return (value);
}
