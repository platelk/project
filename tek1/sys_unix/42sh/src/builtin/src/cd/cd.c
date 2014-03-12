/*
** cd.c for cd in /home/vink/projet/sys_unix/42sh/src/builtin/cd
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 10:30:11 2012 kevin platel
** Last update Sat May 12 02:25:16 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"builtin.h"
#include	"global.h"
#include	"my.h"

char	*get_pwd(char *str, t_env *env)
{
  if (str == NULL)
    {
      if (find_in_env("HOME", env) == NULL)
	fprintf(stderr, "Error : cd : no such variable HOME\n");
      return (find_in_env("HOME", env));
    }
  if (my_strcmp("-", str) == 0)
    {
      if (find_in_env("OLDPWD", env) == NULL)
	fprintf(stderr, "Error : cd : no such variable OLDPWD\n");
      return (find_in_env("OLDPWD", env));
    }
  if (my_strcmp("~", str) == 0)
    return (find_in_env("HOME", env));
  return (my_strdup(str));
}

int	check_cd_access(char *pwd)
{
  int	ret;

  if (pwd == NULL)
    return (EXIT_FAILURE);
  ret = access(pwd, F_OK);
  if (ret != 0)
    {
      fprintf(stderr, "%s: No such file or directory\n", pwd);
      return (EXIT_FAILURE);
    }
  ret = access(pwd, X_OK);
  if (ret != 0)
    {
      fprintf(stderr, "%s: Permission denied.\n", pwd);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	cd(t_global *global, char **cmd)
{
  char	*tab[3];
  char	*pwd;

  if (!cmd || !cmd[0])
    return (EXIT_FAILURE);
  if ((pwd = get_pwd(cmd[1], global->env)) == NULL)
    return (EXIT_FAILURE);
  if (check_cd_access(pwd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (chdir(pwd) < 0)
    return (EXIT_FAILURE);
  tab[0] = "setenv";
  tab[1] = "OLDPWD";
  tab[2] = find_in_env("PWD", global->env);
  if (tab[2] == NULL)
    return (EXIT_FAILURE);
  if (my_strcmp(tab[1], pwd) != 0)
    check_setenv(global, tab);
  tab[0] = "setenv";
  tab[1] = "PWD";
  tab[2] = getcwd(NULL, 0);
  check_setenv(global, tab);
  return (EXIT_SUCCESS);
}
