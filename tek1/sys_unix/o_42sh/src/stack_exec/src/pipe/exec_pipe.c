/*
** exec_pipe.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 16:54:12 2012 ronan guiho
** Last update Sun Apr 29 12:54:45 2012 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "my.h"
#include "pipe.h"
#include "execute.h"

int		exec_pipe_mono(t_node *master_node, t_global *global)
{
  pid_t		pid;
  int		status;
  int		pipe_fd[2];

  pipe(pipe_fd);
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      close(pipe_fd[READ]);
      dup2(pipe_fd[WRITE], STDOUT);
      if ((status = exec_select_execution(master_node->child->nd, global)) >= EXIT_FAILURE)
	return (status);
    }
  else
    {
      close(pipe_fd[WRITE]);
      dup2(pipe_fd[READ], STDIN);
      if ((status = exec_select_execution(master_node->child->next->nd, global)) >= EXIT_FAILURE)
	return (status);
    }
  return (EXIT_SUCCESS);
}

int		exec_pipe_recursif(t_node *master_node, t_global *global,
				      int **pipe_fd, int current_pipe)
{
  pid_t		pid;
  int		status;
  t_node	*cmd_node;

  if (current_pipe == 0)
    return (EXIT_SUCCESS);
  pipe(pipe_fd[current_pipe]);
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      if ((status = exec_pipe_recursif(master_node, global, \
			      pipe_fd, current_pipe - 1)) >= EXIT_FAILURE)
	return (status);
      close(pipe_fd[current_pipe][READ]);
      dup2(pipe_fd[current_pipe][WRITE], STDOUT);
      cmd_node = exec_pipe_current(master_node, current_pipe - 1, NONE_STATE);
      if ((status = exec_select_execution(cmd_node, global)) >= EXIT_FAILURE)
	return (status);
    }
  else
    {
      close(pipe_fd[current_pipe][WRITE]);
      dup2(pipe_fd[current_pipe][READ], STDIN);
      close(pipe_fd[current_pipe + 1][READ]);
      dup2(pipe_fd[current_pipe + 1][WRITE], STDOUT);
      cmd_node = exec_pipe_current(master_node, current_pipe, NONE_STATE);
      if ((status = exec_select_execution(cmd_node, global)) >= EXIT_FAILURE)
	return (status);
    }
  return (EXIT_SUCCESS);
}

int		exec_pipe_cascada(t_node *master_node, t_global *global,
				     int **pipe_fd, int max_pipe)
{
  pid_t		pid;
  int		status;
  t_node	*cmd_node;
  int		state_wait;

  pipe(pipe_fd[max_pipe]);
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      if ((status = exec_pipe_recursif(master_node, global, \
				       pipe_fd, (max_pipe - 1))) >= EXIT_FAILURE)
	return (status);
    }
  else
    {
      wait(&state_wait);
      close(pipe_fd[max_pipe][WRITE]);
      dup2(pipe_fd[max_pipe][READ], STDIN);
      cmd_node = exec_pipe_current(master_node, (max_pipe - 1), INIT);
      if ((status = exec_select_execution(cmd_node, global)) >= EXIT_FAILURE)
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
    return (EXIT_FAILURE);
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
