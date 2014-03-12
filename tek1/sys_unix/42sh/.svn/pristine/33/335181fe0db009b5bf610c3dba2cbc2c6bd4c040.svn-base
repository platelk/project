/*
** exec_redirection.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/redirection
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Apr 13 13:54:25 2012 ronan guiho
** Last update Sat May 19 14:03:09 2012 ronan guiho
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "sh.h"
#include "env.h"
#include "tree.h"
#include "token.h"
#include "execute.h"

int		exec_redirection_dup(int fd, enum e_token flag)
{
  int		state;

  if (flag == S_RED_LEFT)
    state = dup2(fd, 0);
  else if (flag == S_RED_RIGHT)
    state = dup2(fd, 1);
  else if (flag == D_RED_RIGHT)
    state = dup2(fd, 1);
  else if (flag == S_RED_RIGHT_ERR)
    state = dup2(fd, 2);
  else if (flag == D_RED_RIGHT_ERR)
    state = dup2(fd, 2);
  if (state == -1)
    {
      fprintf(stderr, "42sh: Permission denied.\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		exec_redirection_open(char *file, enum e_token flag)
{
  int		fd;

  if (flag == S_RED_LEFT)
    fd = open(file, O_RDONLY);
  else if (flag == S_RED_RIGHT || flag == S_RED_RIGHT_ERR)
    fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
  else if (flag == D_RED_RIGHT || flag == D_RED_RIGHT_ERR)
    fd = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
  if (fd == -1)
    {
      fprintf(stderr, "%s: Permission denied.\n", file);
      return (-1);
    }
  return (fd);
}

int		exec_redirection_execute(char *file, enum e_token flag, \
					 t_child *tmp_node, t_global *global)
{
  int		fd;
  int		status;

  if ((fd = exec_redirection_open(file, flag)) == -1)
    {
      global->status = EXIT_FAILURE;
      return (EXIT_CHILD);
    }
  if ((exec_redirection_dup(fd, flag)) == EXIT_FAILURE)
    {
      global->status = EXIT_FAILURE;
      return (EXIT_CHILD);
    }
  if ((status = exec_select_execution(tmp_node->nd, global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}

int		exec_redirection(t_node *master_node, t_global *global, \
				 enum e_token flag)
{
  int		status;
  char		*file;
  t_child	*tmp_node;

  if (flag == D_RED_LEFT)
    {
      if ((status = exec_redirection_double_left(master_node, \
						 global, 0)) >= EXIT_FAILURE)
	return (status);
      return (EXIT_SUCCESS);
    }
  tmp_node = master_node->child;
  file = tmp_node->next->nd->content;
  if (flag == S_RED_LEFT)
    if ((access(file, F_OK)) == -1)
      {
	fprintf(stderr, "%s: No such file or directory.\n", file);
	global->status = EXIT_FAILURE;
	return (EXIT_CHILD);
      }
  if ((status = exec_redirection_execute(file, flag, \
					  tmp_node, global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}
