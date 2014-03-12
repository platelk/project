/*
** creat_list_label.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sat Mar 24 13:49:36 2012 alexandre deceneux
** Last update Sat Mar 24 13:49:38 2012 alexandre deceneux
*/

#include <stdlib.h>
#include "my.h"
#include "label.h"
#include "instruction.h"
#include "corewar.h"

t_label *creat_list_label(int fd, int *l)
{
  char	  *buffer;
  t_label *label;
  int	  i;

  label = NULL;
  while ((buffer = get_next_line(fd, l)) != NULL)
    {
      i = 0;
      while (buffer != NULL && (buffer[i] == '\t' || buffer[i] == ' ')
	     && buffer[i])
	i++;
      if (buffer != NULL && buffer[i] != 0 &&
	  buffer[i] != '#' && buffer[i] != ';')
	label = creat_one_label(buffer, fd, label, l);
      if (label == NULL && buffer[i] != 0)
	{
	  my_putstr("ECHEC\n");
	  return (NULL);
	}
      free(buffer);
    }
  while (label != NULL && label->prev != NULL)
    label = label->prev;
  return (label);
}
