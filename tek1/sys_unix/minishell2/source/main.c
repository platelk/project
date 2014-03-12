/*
** main.c for main in /home/vink
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Feb  5 13:46:01 2012 kevin platel
** Last update Wed Dec  5 21:08:01 2012 kevin platel
*/


#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"

int	put_c(int cap)
{
  write(2, &cap, 1);
  return (0);
}

int	use_termcap(char *cap)
{
  char	*s;

  s = NULL;
  s = tgetstr(cap, NULL);
  if (s == NULL)
    return (ERROR);
  if (tputs(s, 1, &put_c) == -1)
    return (ERROR);
  return (0);
}

int	main(int ac, char **av, char **envp)
{
  t_env *env;
  t_pwd	*my_pwd;
  t_env	*tmp;

  init(envp);
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
  gest_cmd(tmp, my_pwd);
  return (0);
}
