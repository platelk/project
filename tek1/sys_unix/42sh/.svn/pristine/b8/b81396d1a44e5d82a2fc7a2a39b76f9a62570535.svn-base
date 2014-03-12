/*
** search_env.c for env in /home/vink/projet/sys_unix/42sh/src/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 15:48:57 2012 kevin platel
** Last update Sat Apr 28 17:29:28 2012 kevin platel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "env.h"
#include "my.h"

char	*find_in_env(char *name, t_env *env)
{
  while (env)
    {
      if (my_strcmp(name, env->name) == 0)
	return (env->value);
      env = env->next;
    }
  return (NULL);
}
