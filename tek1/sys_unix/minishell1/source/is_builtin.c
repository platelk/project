/*
** is_builtin.c for is_bultin in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 09:46:26 2011 kevin platel
** Last update Sat Dec 31 00:56:22 2011 kevin platel
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"

int	is_builtin(char *buffer, t_env **envp, t_pwd **my_pwd)
{
  char	**tab;
  int	bool;

  bool = 1;
  tab = my_str_to_wordtab(buffer);
  if (tab[0] != NULL && my_strcmp(tab[0], "exit") == 0)
    {
      freewordtab(tab);
      free(tab);
      free(buffer);
      quit((*envp), (*my_pwd));
    }
  else if (tab[0] != NULL && my_strcmp(tab[0], "cd") == 0)
    (*my_pwd) = change_dir(tab[1], envp, (*my_pwd));
  else if (tab[0] != NULL && (my_strcmp(tab[0], "setenv") == 0
			      || my_strcmp(tab[0], "env") == 0))
    (*envp) = environ_set(buffer, (*envp));
  else if (tab[0] != NULL && my_strcmp(tab[0], "unset") == 0)
    (*envp) = un_set(buffer, (*envp));
  else
    bool = 0;
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (bool);
}

void	free_env(t_env *env)
{
  t_env	*tmp;

  tmp = NULL;
  if (env != NULL)
    {
      while (env != NULL && env->prev != NULL)
	env = env->prev;
      while (env != NULL)
	{
	  if (tmp != NULL)
	    {
	      free(tmp->name);
	      free(tmp->content);
	      free(tmp);
	    }
	  tmp = env;
	  env = env->next;
	}
      if (tmp != NULL)
	{
	  free(tmp->name);
	  free(tmp->content);
	  free(tmp);
	}
    }
}

void	quit(t_env *envp, t_pwd *my_pwd)
{
  free_pwd(my_pwd);
  free_env(envp);
  exit(1);
}
