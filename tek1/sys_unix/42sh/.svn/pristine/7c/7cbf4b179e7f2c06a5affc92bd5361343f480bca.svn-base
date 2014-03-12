/*
** env.c for env in /home/vink/projet/sys_unix/42sh/src/env
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Apr 10 16:43:23 2012 kevin platel
** Last update Sat Apr 28 17:31:08 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my.h"
#include "my_strtok.h"
#include "env.h"

t_env	*creat_list_env(char *str, t_env *env)
{
  char	**tab;
  t_env	*new;

  new = malloc(sizeof(*new));
  if (new == NULL || str == NULL)
    return (NULL);
  tab = my_strtok(str, SEP_ENV, TOK_DELIM);
  new->name  = my_strdup(tab[0]);
  new->value = my_strdup((strchr(str, '=')) + 1);
  new->prev  = env;
  new->next  = NULL;
  if (env != NULL)
    env->next = new;
  my_free_tab(tab);
  return (new);
}

void	print_env(t_env *env)
{
  while (env)
    {
      printf("%s=%s\n", env->name, env->value);
      env = env->next;
    }
}

t_env	*creat_env(void)
{
  int	i;
  t_env	*env;
  t_env	*tmp;

  i = 1;
  if (environ == NULL || environ[0] == NULL)
    return (NULL);
  env = creat_list_env(environ[0], NULL);
  tmp = env;
  while (environ[i])
    {
      tmp = creat_list_env(environ[i], tmp);
      i++;
    }
  return (env);
}
