/*
** main.c for main in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 12 10:16:00 2011 kevin platel
** Last update Wed Dec 12 19:19:34 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"

int	main(int ac, char **av, char **envp)
{
  t_env *env;
  t_pwd	*my_pwd;
  int	i;
  t_env	*tmp;

  i = 0;
  env = get_env(envp);
  tmp = env;
  while (env != NULL && (my_strcmp(env->name, "PWD") != 0))
    env = env->next;
  if (env == NULL || env->content == NULL)
    {
      my_pwd = creat_pwd("/");
      chdir("/");
      env = environ_set("setenv PWD /", tmp);
    }
  else
    my_pwd = creat_pwd(env->content);
  main_loop(tmp, my_pwd);
  return (0);
}
