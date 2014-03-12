/*
** exec_pipe_mono.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 11 18:36:14 2012 ronan guiho
** Last update Wed May 16 16:59:14 2012 ronan guiho
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

int		exec_pipe_mono_father(t_node *master_node, t_global *global, \
				      int *pipe_fd)
{
  int		status;

  if (master_node->child->nd->id == D_RED_LEFT)
    wait(&status);
  if ((close(pipe_fd[WRITE])) == -1)
    return (EXIT_CHILD);
  if ((dup2(pipe_fd[READ], STDIN)) == -1)
    return (EXIT_CHILD);
  if ((status = exec_select_execution(master_node->child->next->nd, \
				      global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}

int		exec_pipe_mono_son(t_node *master_node, t_global *global, \
				   int *pipe_fd)
{
  int		status;

  if ((close(pipe_fd[READ])) == -1)
    {
      global->status = EXIT_FAILURE;
      return (EXIT_CHILD);
    }
  if ((dup2(pipe_fd[WRITE], STDOUT)) == -1)
    {
      global->status = EXIT_FAILURE;
      return (EXIT_CHILD);
    }
  if ((status = exec_select_execution(master_node->child->nd, \
				      global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}

int		exec_pipe_mono(t_node *master_node, t_global *global)
{
  pid_t		pid;
  int		status;
  int		pipe_fd[2];

  if ((pipe(pipe_fd)) == -1)
    return (EXIT_FAILURE);
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      if ((status = exec_pipe_mono_son(master_node, global, \
				       pipe_fd)) >= EXIT_FAILURE)
	return (status);
    }
  else
    if ((status = exec_pipe_mono_father(master_node, global, \
					pipe_fd)) >= EXIT_FAILURE)
      return (status);
  return (EXIT_SUCCESS);
}
