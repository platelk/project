/*
** set_env.c for set_env in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 19:41:30 2011 kevin platel
** Last update Fri Dec 30 22:47:05 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "env.h"

t_env	*environ_set(char *buffer, t_env *envp)
{
  char	**tab;
  t_env	*tmp;

  tmp = envp;
  tab = my_str_to_wordtab(buffer);
  if (tab != NULL)
    {
      if (tab[1] == NULL)
	while (envp != NULL)
	  {
	    my_printf("%s=%s\n", envp->name, envp->content);
	    envp = envp->next;
	  }
      else
	tmp = add_new_with_two_arg(tab[1], tab[2], envp);
    }
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (tmp);
}
