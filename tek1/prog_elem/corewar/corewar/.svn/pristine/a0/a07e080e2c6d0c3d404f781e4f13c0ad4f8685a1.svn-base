/*
** get_size_bin.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 15:22:49 2012 ronan guiho
** Last update Tue Mar 20 10:09:48 2012 alexis leprovost
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#include "my.h"
#include "op.h"
#include "ptr_func.h"

int	get_size_bin(int fd, t_champ *champ)
{
  header_t	header;
  to_int	i;
  to_int	a;
  int		n;

  if (read(fd, &header, sizeof(header)) <= 0)
    return (-1);
  i.value = header.magic;
  a.value = 0;
  n = -1;
  while (++n < 4)
    a.param[3 - n] = i.param[n];
  if (a.value != COREWAR_EXEC_MAGIC)
    {
      my_puterror("Corewar: magic exec file is not valid.\n");
      return (-1);
    }
  champ->prog_name = my_strdup(header.prog_name);
  i.value = header.prog_size;
  a.value = 0;
  n = -1;
  while (++n < 4)
    a.param[3 - n] = i.param[n];
  header.prog_size = a.value;
  return (header.prog_size);
}
