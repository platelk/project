/*
** un_set.c for un_set in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 20:43:05 2011 kevin platel
** Last update Sat Dec 31 01:44:56 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "env.h"

t_env	*del_one(t_env *envp)
{
  t_env	*tmp;

  tmp = envp;
  if (tmp != NULL)
    {
      envp->next != NULL ? (envp = envp->next) : (envp = envp->prev);
      if (tmp->prev != NULL)
	tmp->prev->next = tmp->next;
      if (tmp->next != NULL)
	tmp->next->prev = tmp->prev;
      free(tmp->name);
      free(tmp->content);
      free(tmp);
    }
  return (envp);
}

t_env	*un_set(char *buffer, t_env *envp)
{
  char	**tab;
  int	i;

  tab = my_str_to_wordtab(buffer);
  i = 0;
  while (envp != NULL && tab[++i])
    {
      while (envp->next != NULL && my_strcmp(tab[i], envp->name) != 0)
	envp = envp->next;
      if (envp != NULL && my_strcmp(tab[i], envp->name) == 0)
	envp = del_one(envp);
      else
	my_printf("%s : Invalid argument\n", tab[i]);
      while (envp != NULL && envp->prev != NULL)
	envp = envp->prev;
    }
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (envp);
}
