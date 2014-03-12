/*
** exec_write_fd.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/redirection
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 15:50:36 2012 ronan guiho
** Last update Mon Apr 23 17:43:00 2012 harold ozouf
*/

#include <stdlib.h>
#include <unistd.h>
#include "execute.h"

int	exec_write_fd(char *buffer, int fd)
{
  int	i;

  i = 0;
  while (buffer[i])
    {
      write(fd, &buffer[i], 1);
      i++;
    }
  return (EXIT_SUCCESS);
}
