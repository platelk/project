/*
** exec_redirection_double_left.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/redirection
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 10:28:55 2012 ronan guiho
** Last update Mon Apr 30 11:21:56 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "sh.h"
#include "execute.h"

static int		exec_redirection_double_left_fork(t_child *tmp_node,
							  t_env *env,
							  char *buffer)
{
  pid_t		pid;
  int		fd[2];
  int		status;

  pipe(fd);
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      if (buffer != NULL)
	{
	  exec_write_fd(buffer, fd[1]);
	  free(buffer);
	}
    }
  else
    {
      close(fd[1]);
      dup2(fd[0], 0);
      if ((status = exec_command(tmp_node->nd, env)) >= EXIT_FAILURE)
	return (status);
    }
  return (EXIT_SUCCESS);
}

int		exec_redirection_double_left(t_node  *master_node, t_env *env)
{
  int		status;
  int		rtrn_read;
  t_child	*tmp_node;
  char		*stop_word;
  char		buffer[1024];
  char		*buffer_write;

  buffer_write = NULL;
  tmp_node = master_node->child;
  my_putchar('?');
  if ((rtrn_read = read(0, buffer, 1024)) <= 0)
    return (EXIT_FAILURE);
  buffer[rtrn_read] = '\0';
  if ((stop_word = my_strconcat(tmp_node->next->nd->content, "\n")) == NULL)
    return (EXIT_FAILURE);
  if (my_strcmp(buffer, stop_word) != 0)
    buffer_write = my_strdup(buffer);
  while (my_strcmp(buffer, stop_word) != 0)
    {
      my_putchar('?');
      if ((rtrn_read = read(0, buffer, 1024)) <= 0)
	return (EXIT_FAILURE);
      buffer[rtrn_read] = '\0';
      if (my_strcmp(buffer, stop_word) != 0)
	if ((buffer_write = my_strconcat(buffer_write, buffer)) == NULL)
	  return (EXIT_FAILURE);
     }
  free(stop_word);
  if ((status = exec_redirection_double_left_fork(tmp_node, env, buffer_write)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_CHILD);
}
