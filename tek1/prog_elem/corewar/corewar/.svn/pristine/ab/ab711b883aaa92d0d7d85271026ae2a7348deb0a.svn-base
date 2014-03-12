/*
** asm.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Thu Mar 22 13:47:18 2012 alexandre deceneux
** Last update Fri Mar 23 15:56:49 2012 alexandre deceneux
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "corewar.h"

int	asm_treatment(char *str)
{
  int   fd;
  int   flag;
  t_label       *label;
  header_t      *header;
  int	l;

  l = 0;
  flag = 0;
  if ((fd = open(str, O_RDONLY)) < 0)
    {
      my_printf("Asm: Can't open file %s\n", str);
      return (1);
    }
  if ((header = get_header(&flag, fd, &l)))
    {
      label = get_list_label(fd, &l);
      if (label == NULL || change_label_by_value(label, flag) ||
	  find_errors(label))
	return (1);
      if (str != NULL && str[0] != '\0')
	write_file(label, str, header);
      return (0);
    }
  else
    return (1);
}
