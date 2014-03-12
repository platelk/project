/*
** get_header.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Thu Mar 22 13:48:38 2012 alexandre deceneux
** Last update Thu Mar 22 13:48:38 2012 alexandre deceneux
*/

#include <stdlib.h>

#include "corewar.h"
#include "op.h"

header_t	*get_header(int *flag, int fd, int *l)
{
  header_t	*header;
  int		error;

  error = 0;
  header = NULL;
  if ((header = malloc(sizeof(*header))) == NULL)
    my_merror();
  if (get_name(fd, header, l) == EXIT_FAILURE)
    {
      my_printf("Asm: Name invalid at line %d.\n", *l);
      error++;
    }
  if (get_comment(fd, header, l) == EXIT_FAILURE)
    {
      my_printf("Asm: Comment invalid at line %d.\n", *l);
      error++;
    }
  if (get_extend(flag, fd, l) == EXIT_FAILURE)
    error++;
  if (error || !header)
    return (NULL);
  header->magic = magic(COREWAR_EXEC_MAGIC);
  return (header);
}
