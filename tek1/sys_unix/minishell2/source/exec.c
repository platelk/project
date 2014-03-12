/*
** exec.c for exec in /home/platel_k/projet/minishell1
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 12 19:12:30 2011 kevin platel
** Last update Tue Feb  7 12:12:32 2012 kevin platel
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "env.h"

void	exec(t_env *envp, char *buffer)
{
  char	**tab;
  char	*link;
  char	**path;
  int	i;

  tab = my_str_to_wordtab(buffer);
  while (envp != NULL && my_strcmp(envp->name, "PATH") != 0)
    envp = envp->next;
  if (envp != NULL)
    {
      path = my_wordtab(envp->content);
      i = 0;
      while (tab[0] != NULL && path != NULL && path[i] != NULL)
	{
	  link = link_cat(tab[0], path[i]);
	  access(link, X_OK) == 0 ? execve(link, tab, environ) : i++;
	  free(link);
	}
    }
  if (tab[0] != NULL && access(tab[0], X_OK) == 0)
    execve(tab[0], tab, environ);
  if (tab[0] != NULL)
    my_printf("[%s] : command not found\n", tab[0]);
  make_free(tab, path);
}

void	make_free(char **tab, char **path)
{
  if (tab != NULL)
    {
      freewordtab(tab);
      free(tab);
    }
  if (path != NULL)
    {
      freewordtab(path);
      free(path);
    }
}
