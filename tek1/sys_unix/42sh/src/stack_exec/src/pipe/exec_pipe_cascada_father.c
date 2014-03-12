/*
** exec_pipe.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May 12 13:51:06 2012 ronan guiho
** Last update Sat May 12 13:54:05 2012 ronan guiho
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

int		exec_pipe_cascada_fath(t_node *master_node, t_global *global,
				       int **pipe_fd, int max_pipe)
{
  int		status;
  t_node	*cmd_node;

  if ((close(pipe_fd[max_pipe][WRITE])) == -1)
    return (EXIT_FAILURE);
  if ((dup2(pipe_fd[max_pipe][READ], STDIN)) == -1)
    return (EXIT_FAILURE);
  cmd_node = exec_pipe_current(master_node, (max_pipe - 1), INIT);
  if ((status = exec_select_execution(cmd_node, global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}
