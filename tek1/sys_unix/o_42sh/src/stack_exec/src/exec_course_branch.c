/*
** exec_course_tree.c for exec_stack in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr 18 12:57:52 2012 ronan guiho
** Last update Mon Apr 30 13:08:10 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "builtin.h"
#include "env.h"
#include "global.h"
#include "tree.h"
#include "token.h"
#include "execute.h"

int	exec_course_branch_select(t_node *root, t_global *global)
{
  int	status;

  if (root->id == PIPE)
    {
      if ((status = exec_pipe(root, global)) >= EXIT_FAILURE)
	return (status);
    }
  else if (root->id == CMD)
    {
      if ((status = exec_command(root, global->env)) >= EXIT_FAILURE)
	return (status);
    }
  else
    {
      if ((status = exec_redirection(root, global, root->id)) >= EXIT_FAILURE)
	return (status);
    }
  return (EXIT_SUCCESS);
}

int	exec_course_branch_execute(t_node *root, t_global *global)
{
  int	pid;
  int	signal;
  int	status;

  if (is_builtin(root->content) != -1)
    {
      if ((exec_builtin(root, global)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  if ((pid = fork()) == -1)
    return (EXIT_FAILURE);
  if (pid == 0)
    {
      start_signal();
      if ((status = exec_course_branch_select(root, global)) >= EXIT_FAILURE)
	return (status);
    }
  else
    {
      wait(&signal);
      exec_signal(WTERMSIG(signal));
      return((WEXITSTATUS(signal) == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		exec_course_branch(t_node *root, t_env *env, t_global *global)
{
  int		status;

  if (root == NULL)
    return (EXIT_SUCCESS);
  if (root->id == AND)
    {
      if ((status = exec_course_branch_execute(root->child->nd, global)) >= EXIT_FAILURE)
	{
	  if (status == EXIT_FAILURE)
	    if (root->child->next->nd->id == OR)
	      if ((status = exec_course_branch(root->child->next->nd->child->next->nd, env, global)) >= EXIT_FAILURE)
		return (status);
	  return (status);
	}
      if ((status = exec_course_branch(root->child->next->nd, env, global)) >= EXIT_FAILURE)
	return (status);
    }
  else if (root->id == OR)
    {
      if ((status = exec_course_branch_execute(root->child->nd, global)) >= EXIT_FAILURE)
	{
	  if (status == EXIT_FAILURE)
	    if ((status = exec_course_branch(root->child->next->nd, env, global)) >= EXIT_FAILURE)
	      return (status);
	  return (status);
	}
    }
  else if (root->id != CMD && root->id != PIPE && root->id != S_RED_RIGHT && \
      root->id != D_RED_RIGHT && root->id != S_RED_LEFT && \
      root->id != D_RED_LEFT && root->id != S_RED_RIGHT_ERR && \
      root->id != D_RED_RIGHT_ERR)
    {
      if ((status = exec_course_branch(root->child->nd, env, global)) >= EXIT_FAILURE)
	return (status);
    }
  else
    if ((status = exec_course_branch_execute(root, global)) >= EXIT_FAILURE)
      return (status);
  return (EXIT_SUCCESS);
}
