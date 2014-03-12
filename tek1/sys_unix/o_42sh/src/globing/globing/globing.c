/*
** globing.c for globing in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 10 16:40:50 2012 kevin platel
** Last update Mon Apr 30 11:34:56 2012 kevin platel
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
  if (glob(src, GLOB_TILDE | GLOB_NOCHECK, NULL, &gl) != 0)
    {
      fprintf(stderr, "Error treatment of %s", str);
      return (NULL);
    }
  str = realloc(str, my_strlen(str) + my_wordtab_len(gl.gl_pathv)
		+ my_count_str_in_tab(gl.gl_pathv));
  i = 0;
  while (gl.gl_pathv[i])
    {
      str = strcat(str, gl.gl_pathv[i]);
      if (gl.gl_pathv[i + 1] != NULL)
	str = strcat(str, " ");
      i++;
    }
  return (str);
}

char	*glob_in_dir(char *str, char *new_str, int flag)
{
  int	i;
  char	**tab;

  i = 0;
  tab = my_strtok(str, " \t\n", TOK_DELIM);
  while (tab[i])
    {
      new_str = make_globing(new_str, tab[i], flag);
      if (new_str == NULL)
	return (NULL);
      new_str = realloc(new_str, my_strlen(new_str) + 1);
      if (new_str == NULL)
	return (NULL);
      if (tab[i + 1])
	new_str = strcat(new_str, " ");
      i++;
    }
  my_free_tab(tab);
  return (new_str);
}

char	*globing(char *str, t_global *glob, int tok)
{
  char	*new_str;

  if (str == NULL)
    return (NULL);
  new_str = malloc(1);
  new_str[0] = 0;
  if (tok & GLOB_DIR)
    new_str = glob_in_dir(str, new_str, tok);
  return (new_str);
}
