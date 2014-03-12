/*
** glob_back_quote.c for back_quotes in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Apr 29 12:35:24 2012 kevin platel
Last update Wed May  2 21:32:44 2012 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "sh.h"
#include "xsys.h"
#include "token.h"
#include "globing.h"
#include "env.h"
#include "pipe.h"

t_token	*glob_back_quotes(t_token *t, t_global *glob)
{
  char	*ret;
  int	pipe_fd[2];
  int	pid;
  int	len;
  t_node	*tree;
  int	exit;
  char	*buffer;

  pipe(pipe_fd);
  ret = NULL;
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      close(pipe_fd[READ]);
      dup2(pipe_fd[WRITE], STDOUT);
      if (is_singlestr(' ', t->content) &&
	  (tree = parsing_func(t->content, glob)))
	(exit = exec_course_tree(tree, glob->env, glob));
      glob->status = 1;
      return (NULL);
    }
  else
    {
      close(pipe_fd[WRITE]);
      wait();
      while ((buffer = get_next_line(pipe_fd[READ])) != NULL)
	{
	  ret = my_strmcat(ret, buffer);
	  free(buffer);
	}
      close(pipe_fd[READ]);
    }
  t->spec = S_QUOTE;
  t->content = my_strdup(ret);
  if (ret)
    free(ret);
  return (t);
}
