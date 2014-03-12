/*
** export_env.c for env in /home/vink/projet/sys_unix/42sh/src/env/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 12 11:08:46 2012 kevin platel
** Last update Sat Apr 28 17:38:40 2012 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "env.h"
#include "globing.h"
#include "my.h"
#include "xsys.h"

int	len_env_list(t_env *env)
{
  int	i;

  i = 0;
  while (env)
    {
      env = env->next;
      i++;
    }
  return (i);
}

char	**export_env(t_env *env)
{
  char	**tab;
  int	i;

  tab = xmalloc((len_env_list(env) + 1) * sizeof(*tab));
  if (tab == NULL)
    return (NULL);
  i = 0;
  while (env)
    {
      tab[i] = malloc((my_strlen(env->name) + 2 + my_strlen(env->value))
		      * sizeof(**tab));
      sprintf(tab[i], "%s=%s", env->name, env->value);
      i++;
      env = env->next;
    }
  tab[i] = NULL;
  return (tab);
}
