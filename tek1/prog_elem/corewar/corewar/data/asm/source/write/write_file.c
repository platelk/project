/*
** write_file.c for AsmX in /home/guiho_r//tek1/corewar/source/ASM/write
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jan 23 16:48:28 2012 ronan guiho
** Last update Wed Mar 21 15:53:03 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "label.h"
#include "corewar.h"

int	write_file(t_label *list, char *name, header_t *header)
{
  int	fd;

  fd = create_file(name);
  write_header(fd, header, list);
  write_instruction(fd, list);
  return (0);
}
