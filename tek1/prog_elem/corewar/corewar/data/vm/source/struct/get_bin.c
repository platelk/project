/*
** get_bin.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 14:56:06 2012 ronan guiho
** Last update Tue Mar 20 10:10:17 2012 alexis leprovost
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "corewar.h"
#include "op.h"
#include "champ.h"

int		get_bin(t_champ *champ, char *str)
{
  int		fd;

  if ((fd = open(str, O_RDONLY)) == -1)
    {
      my_printf("Corewar: Cannot open file %s\n", str);
      return (1);
    }
  if ((champ->prog_size = get_size_bin(fd, champ)) == -1)
    return (1);
  if ((champ->bin = malloc(sizeof(char) * (champ->prog_size + 1))) == NULL)
    return (1);
  champ->bin[read(fd, champ->bin, champ->prog_size)] = '\0';
  return (0);
}
