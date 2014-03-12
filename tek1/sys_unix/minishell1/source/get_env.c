/*
** get_env.c for get_env in /home/platel_k/projet/minishell1/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 11:28:30 2011 kevin platel
** Last update Sat Dec 31 01:40:34 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"
#include "minishell.h"

t_env	*add_new(char *field, t_env *begin)
{
  char **tab;
  t_env	*new;

  new = begin;
  tab = my_env_wordtab(field);
  if (tab != NULL)
    {
      new = malloc(sizeof(*new));
      tab[0] != NULL ? (new->name = my_strdup(tab[0])) : (new->name = NULL);
      if (tab[0] != NULL && tab[1] != NULL)
	(new->content = my_strdup(tab[1]));
      else
	new->content = NULL;
      new->next = begin;
      new->prev = NULL;
      if (begin != NULL)
	begin->prev = new;
    }
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (new);
}

t_env	 *add_new_with_two_arg(char *name, char *content, t_env *begin)
{
  t_env	*new;
  t_env	*tmp;

  tmp = begin;
  while (tmp != NULL && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  if (tmp != NULL && my_strcmp(tmp->name, name) == 0)
    {
      if (tmp->content != NULL)
	free(tmp->content);
      tmp->content = my_strdup(content);
      return (begin);
    }
  else
    {
      if ((new = malloc(sizeof(*new))) == 0)
	return (NULL);
      new->name = my_strdup(name);
      new->content = my_strdup(content);
      new->next = begin;
      new->prev = NULL;
    }
  if (begin != NULL)
    begin->prev = new;
  return (new);
}

t_env   *get_env(char **envp)
{
  int	i;
  t_env	*env;

  i = 0;
  env = NULL;
  while (envp != NULL && envp[i] != NULL)
    {
      env = add_new(envp[i], env);
      i++;
    }
  return (env);
}
