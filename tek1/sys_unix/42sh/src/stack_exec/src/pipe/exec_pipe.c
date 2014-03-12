/*
** exec_pipe.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 16:54:12 2012 ronan guiho
** Last update Thu May 17 13:25:45 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "sh.h"
#include "my.h"
#include "pipe.h"
#include "execute.h"

int		exec_pipe_recursif_fathe(t_node *master_node, t_global *global, \
					 int **pipe_fd, int current_pipe)
{
  int		status;
  t_node	*cmd_node;

  if ((close(pipe_fd[current_pipe][WRITE])) == -1)
    return (EXIT_CHILD);
  if ((dup2(pipe_fd[current_pipe][READ], STDIN)) == -1)
    return (EXIT_CHILD);
  if ((close(pipe_fd[current_pipe + 1][READ])) == -1)
    return (EXIT_CHILD);
  if ((dup2(pipe_fd[current_pipe + 1][WRITE], STDOUT)) == -1)
    return (EXIT_CHILD);
  cmd_node = exec_pipe_current(master_node, current_pipe, NONE_STATE);
  if ((status = exec_select_execution(cmd_node, global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}
int		exec_pipe_recursif_child(t_node *master_node, t_global *global, \
					 int **pipe_fd, int current_pipe)
{
  int		status;
  t_node	*cmd_node;

  if ((close(pipe_fd[current_pipe][READ])) == -1)
    {
      global->status = EXIT_FAILURE;
      return (EXIT_CHILD);
    }
  if ((dup2(pipe_fd[current_pipe][WRITE], STDOUT)) == -1)
    {
      global->status = EXIT_FAILURE;
      return (EXIT_CHILD);
    }
  cmd_node = exec_pipe_current(master_node, current_pipe - 1, NONE_STATE);
  if ((status = exec_select_execution(cmd_node, global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}

int		exec_pipe_recursif(t_node *master_node, t_global *global,
				      int **pipe_fd, int current_pipe)
{
  pid_t		pid;
  int		status;

  if (current_pipe == 0)
    return (EXIT_SUCCESS);
  if ((pipe(pipe_fd[current_pipe])) == -1)
    return (EXIT_CHILD);
  if ((pid = fork()) == -1)
    return (EXIT_CHILD);
  if (pid == 0)
    {
      if ((status = exec_pipe_recursif(master_node, global, \
			      pipe_fd, current_pipe - 1)) >= EXIT_FAILURE)
	return (status);
      if ((status = exec_pipe_recursif_child(master_node, global, pipe_fd, \
					     current_pipe)) >= EXIT_FAILURE)
	return (status);
    }
  else
    if ((status = exec_pipe_recursif_fathe(master_node, global, pipe_fd, \
					   current_pipe)) >= EXIT_FAILURE)
      return (status);
  return (EXIT_SUCCESS);
}

int		exec_pipe_cascada(t_node *master_node, t_global *global,
				     int **pipe_fd, int max_pipe)
{
  pid_t		pid;
  int		status;
  int		state_wait;

  if ((pipe(pipe_fd[max_pipe])) == -1)
    return (EXIT_CHILD);
  if ((pid = fork()) == -1)
    return (EXIT_CHILD);
  if (pid == 0)
    {
      if ((status = exec_pipe_recursif(master_node, global, \
				       pipe_fd, (max_pipe - 1))) >= EXIT_FAILURE)
	return (status);
    }
  else
    {
      wait(&state_wait);
      if ((status = exec_pipe_cascada_fath(master_node, global, \
					   pipe_fd, max_pipe)) >= EXIT_FAILURE)
	return (status);
    }
  return (EXIT_SUCCESS);
}

int		exec_pipe(t_node *master_node, t_global *global)
{
  int		status;
  int		max_pipe;
  int		**pipe_fd;

  max_pipe = exec_pipe_count(master_node);
  if ((pipe_fd = malloc_int_tab(max_pipe + 1, 2)) == NULL)
    return (EXIT_CHILD);
  if (max_pipe == 1)
    {
      if ((status = exec_pipe_mono(master_node, global)) >= EXIT_FAILURE)
	return (status);
    }
  else
    if ((status = exec_pipe_cascada(master_node, global,
			   pipe_fd, max_pipe)) >= EXIT_FAILURE)
      return (status);
  return (EXIT_SUCCESS);
}
