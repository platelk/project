/*
** glob_cmd.c for glob in /home/vink/projet/sys_unix/42sh/src/globing/globing/dir
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May 10 11:54:21 2012 kevin platel
** Last update Thu May 10 15:26:00 2012 kevin platel
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<dirent.h>

#include	"globing.h"
#include	"global.h"
#include	"my.h"

char	*glob_cmd_in_dir(char *link, char *str, char *new_str)
{
  struct	dirent	*files;
  DIR	*dir;

  if ((dir = opendir(link)) == NULL)
    return (new_str);
  while ((files = readdir(dir)) != NULL)
    {
      if (files->d_name[0] != '.' && (glob_match(str, files->d_name) == 1))
	{
	  if (new_str)
	    new_str = my_strmcat(new_str, " ");
	  new_str = my_strmcat(new_str, files->d_name);
	}
    }
  return (new_str);
}

char	*glob_cmd(char *str, char *new_str, t_global *glob)
{
  char	*tmp;
  char	**tab;
  int	i;

  tmp = find_in_env("PATH", glob->env);
  tab = my_strtok(tmp, ":", TOK_DELIM);
  while (tab && tab[i])
    {
      new_str = glob_cmd_in_dir(tab[i], str, new_str);
      i++;
    }
  my_free_tab(tab);
  return (new_str);
}
