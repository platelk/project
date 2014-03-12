/*
** create_file.c for AsmX in /home/guiho_r//tek1/corewar/source/ASM/write
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jan 23 14:51:49 2012 ronan guiho
** Last update Thu Feb  9 13:44:41 2012 ronan guiho
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "my.h"
#include "corewar.h"

char	*modify_extension(char *name)
{
  int	size;

  size = my_strlen(name);
  if ((name = realloc(name, sizeof(char) * (size + 3))) == NULL)
    return (NULL);
  name[size - 1] = 'c';
  name[size] = 'o';
  name[size + 1] = 'r';
  name[size + 2] = '\0';
  return (name);
}

int	create_file(char *name)
{
  int	fd;
  char *new_name;

  new_name = my_strdup(name);
  new_name = modify_extension(new_name);
  if ((fd = open(new_name, O_CREAT | O_WRONLY | O_TRUNC,
		 S_IRUSR | S_IWUSR)) == -1)
    {
      my_printf("Corewar: Can't open file <");
      my_putstr(name);
      my_putstr(">.\n");
      exit(0);
    }
  if (new_name != NULL)
    free(new_name);
  return (fd);
}
