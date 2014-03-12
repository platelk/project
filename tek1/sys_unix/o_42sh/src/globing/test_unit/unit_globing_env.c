/*
** unit_globing_env.c for test in /home/vink/projet/sys_unix/42sh/src/globing/glob_env
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 12 19:35:02 2012 kevin platel
** Last update Fri Apr 13 10:58:25 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "env.h"
#include "utils.h"
#include "my.h"
#include "token.h"
#include "globing.h"

int	main()
{
  t_env	*env;
  char	*str;

  env = creat_env();
  while (env)
    {
      str = globing_env(env->name, env, G_E_WITHOUT_DOL);
      if (strcmp(env->value, str) != 0)
	return (1);
      env = env->next;
    }
  return (0);
}
