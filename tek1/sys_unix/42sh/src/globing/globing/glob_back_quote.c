/*
** glob_back_quote.c for back_quotes in /home/vink/projet/sys_unix/42sh/src/globing/globing
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Apr 29 12:35:24 2012 kevin platel
** Last update Sat May 19 15:38:41 2012 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "my.h"
#include "sh.h"
#include "xsys.h"
#include "token.h"
#include "globing.h"
#include "env.h"
#include "pipe.h"
#include "execute.h"

char	*glob_back_father(int *pipe_fd, int pid)
{
  char	*buffer;
  char	*ret;

  if (close(pipe_fd[WRITE]) < 0)
    return (NULL);
  if (waitpid(pid, NULL, 0) < 0)
    return (NULL);
  ret = NULL;
  while ((buffer = get_next_line(pipe_fd[READ])) != NULL)
    {
      if (ret != NULL)
	ret = my_strmcat(ret, " ");
      ret = my_strmcat(ret, buffer);
      free(buffer);
    }
  if (close(pipe_fd[READ]) < 0)
    return (NULL);
  return (ret);
}

t_token	*glob_back_son(int *pipe_fd, t_token *t, t_global *glob)
{
  t_node	*tree;

  if (close(pipe_fd[READ]) < 0)
    return (NULL);
  if (dup2(pipe_fd[WRITE], 1) < 0)
    return (NULL);
  if (glob && glob->config)
    glob->config->alias = NULL;
  if (is_singlestr(' ', t->content) &&
      (tree = parsing_func(t->content, glob, 0)))
    {
      glob->echo = 1;
      (exec_course_tree(tree, glob->env, glob));
    }
  if (close(pipe_fd[WRITE]) < 0)
    return (NULL);
  if (glob)
    glob->status = 1;
  return (NULL);
}

t_token	*glob_make_link(t_token *t, t_token *tmp, char *str)
{
  t_token	*tmp2;

  if (str)
    {
      tmp = analyse_cmd(str);
      tmp2 = tmp;
      while (tmp2 && tmp2->next)
	tmp2 = tmp2->next;
      if (tmp2)
	tmp2->next = t->next;
      if (tmp)
	{
	  t->content = my_strdup(tmp->content);
	  t->id = tmp->id;
	  t->spec = tmp->spec;
	  t->next = tmp->next;
	  free(tmp);
	}
    }
  else
    t->content = NULL;
  return (t);
}

t_token	*glob_back_quotes(t_token *t, t_global *glob)
{
  char	*ret;
  int	pipe_fd[2];
  int	pid;

  if (t == NULL || pipe(pipe_fd) < 0 || t->content == NULL)
    return (t);
  ret = NULL;
  if ((pid = (int) fork()) == -1)
    {
      fprintf(stderr, "42sh: Unable to create a new process.\n");
      return (NULL);
    }
  if (pid == 0)
    return (glob_back_son(pipe_fd, t, glob));
  else
    ret = glob_back_father(pipe_fd, pid);
  if (t->content)
    free(t->content);
  t = glob_make_link(t, NULL, ret);
  if (ret)
    free(ret);
  return (t);
}
