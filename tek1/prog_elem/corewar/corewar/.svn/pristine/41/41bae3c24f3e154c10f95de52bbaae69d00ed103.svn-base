/*
** write_header.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/write
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Thu Mar 22 13:49:12 2012 alexandre deceneux
** Last update Thu Mar 22 13:49:13 2012 alexandre deceneux
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

#include "op.h"
#include "label.h"
#include "corewar.h"

int		write_header(int fd, header_t *header, t_label *list)
{
  t_str_int	convert;

  convert.value = 0;
  while (list)
    {
      convert.value = list->size + convert.value;
      list = list->next;
    }
  header->prog_size = magic(convert.value);
  write(fd, header, sizeof(header_t));
  free(header);
  return (0);
}
