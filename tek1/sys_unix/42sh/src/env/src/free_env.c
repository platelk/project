/*
** free_env.c for env in /home/vink/projet/sys_unix/42sh/src/env/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Wed May 16 17:31:02 2012 kevin platel
** Last update Sat May 19 14:25:47 2012 kevin platel
*/

#include	<stdlib.h>

#include	"env.h"

void	env_free(t_env *env)
{
  t_env	*tmp;

  while (env && env->prev)
    env = env->prev;
  while (env)
    {
      tmp = env;
      env = env->next;
      if (tmp->name)
	free(tmp->name);
      if (tmp->value)
	free(tmp->value);
      free(tmp);
    }
}
