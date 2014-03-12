/*
** globing.c for globing in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 10 16:40:50 2012 kevin platel
** Last update Tue May 22 10:11:42 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glob.h>

#include "my_strtok.h"
#include "globing.h"
#include "utils.h"
#include "my.h"
#include "env.h"

static char	*make_globing(char *str, char *src, int flag)
{
  glob_t	gl;
  int	i;
  int	flags;

  flags = GLOB_TILDE | GLOB_NOCHECK;
  if (flag & GLOB_SLASH)
    flags |= GLOB_MARK;
  if (glob(src, flags, NULL, &gl) != 0)
    {
      fprintf(stderr, "Error treatment of %s", str);
      return (NULL);
    }
  i = 0;
  while (gl.gl_pathv && gl.gl_pathv[i])
    {
      str = my_strmcat(str, gl.gl_pathv[i]);
      if (gl.gl_pathv[i + 1] != NULL)
	str = my_strmcat(str, " ");
      i++;
    }
  my_free_tab(gl.gl_pathv);
  return (str);
}

char	*glob_in_dir(char *str, char *new_str, int flag)
{
  int	i;
  char	**tab;

  i = 0;
  tab = my_strtok(str, " \t\n", TOK_DELIM);
  while (tab && tab[i])
    {
      new_str = make_globing(new_str, tab[i], flag);
      if (tab[i + 1])
	new_str = my_strmcat(new_str, " ");
      i++;
    }
  my_free_tab(tab);
  return (new_str);
}

char	*glob_in_env(char *str, t_global *glob, char *new_str)
{
  t_env	*env;

  env = glob->env;
  while (env)
    {
      if (glob_match(str, env->name) == 1)
	{
	  if (new_str)
	    new_str = my_strmcat(new_str, " ");
	  new_str = my_strmcat(new_str, env->name);
	}
      env = env->next;
    }
  return (new_str);
}

char	*glob_in_alias(char *str, t_global *glob, char *new_str)
{
  t_alias	*alias;

  if (glob && glob->config)
    alias = glob->config->alias;
  while (alias)
    {
      if (glob_match(str, alias->initial) == 1)
	{
	  if (new_str)
	    new_str = my_strmcat(new_str, " ");
	  new_str = my_strmcat(new_str, alias->initial);
	}
      alias = alias->next;
    }
  return (new_str);
}

char	*globing(char *str, t_global *glob, int tok)
{
  char	*new_str;

  glob = glob;
  if (str == NULL)
    return (NULL);
  new_str = NULL;
  if (tok & GLOB_DIR)
    new_str = glob_in_dir(str, new_str, tok);
  if ((tok & GLOB_ENV) && str)
    {
      if (str[0] == '$')
	new_str = glob_in_env(&str[1], glob, new_str);
      else
	new_str = glob_in_env(str, glob, new_str);
    }
  if (tok & GLOB_CMD)
    new_str = glob_cmd(str, new_str, glob);
  if (tok & GLOB_ALIAS)
    new_str = glob_in_alias(str, glob, new_str);
  return (new_str);
}
