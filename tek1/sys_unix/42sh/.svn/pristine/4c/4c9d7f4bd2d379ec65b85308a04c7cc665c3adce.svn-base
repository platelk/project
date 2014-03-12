/*
** exec_course_branch_execute.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 18 13:04:51 2012 ronan guiho
** Last update Sat May 19 15:34:21 2012 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#include "sh.h"
#include "builtin.h"
#include "globing.h"
#include "env.h"
#include "global.h"
#include "tree.h"
#include "token.h"
#include "execute.h"

int	exec_course_son(t_node *root, t_global *global, int pid)
{
  int	status;

  start_signal();
  if (global->echo == 0)
    {
      if ((setpgid(pid, pid)) == -1)
	return (EXIT_CHILD);
      if ((tcsetpgrp(STDIN_FILENO, getpgid(pid))) == -1)
	return (EXIT_CHILD);
      if ((tcsetpgrp(1, getpgid(pid))) == -1)
	return (EXIT_CHILD);
    }
  if ((status = exec_course_branch_select(root, global)) >= EXIT_FAILURE)
    return (status);
  return (EXIT_SUCCESS);
}

int	exec_course_father(t_global *global, int pid)
{
  int	sig;

  if (global && global->echo == 0)
    signal(SIGTTOU, SIG_IGN);
  if (global->echo == 0 && (setpgid(pid, pid)) == -1)
    return (EXIT_FAILURE);
  wait(&sig);
  if (global->echo == 0)
    {
      if ((tcsetpgrp(STDIN_FILENO, getpgid(0))) == -1)
	return (EXIT_FAILURE);
      if ((tcsetpgrp(1, getpgid(0))) == -1)
	return (EXIT_FAILURE);
    }
  global->exit = WEXITSTATUS(sig);
  return (((WEXITSTATUS(sig) == 0) && (exec_signal(WTERMSIG(sig))	\
				       == EXIT_SUCCESS)) ? EXIT_SUCCESS \
	  : EXIT_FAILURE);
}
