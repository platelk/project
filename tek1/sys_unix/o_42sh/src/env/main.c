/*
** main.c for test in /home/vink/projet/sys_unix/42sh/src/env
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 09:37:20 2012 kevin platel
** Last update Tue Apr 17 12:01:12 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "env.h"

int	main(int ac, char **av, char **env)
{
  t_env	*e;
  int	i;
  char	*str;
  t_env	*tmp;
  char	**tab;

  e = creat_env();
  tmp = e;
  if (e == NULL)
    return (1);
  printf("PWD = %s\n", find_in_env("PWD", e));
  printf("LOGNAME = %s\n", find_in_env("LOGNAME", e));

  print_env(e);
  tab = export_env(e);
  i = 0;
  while (tab[i])
    {
      if (strcmp(tab[i], environ[i]) != 0)
	{
	  fprintf(stderr, "Error to transform t_env in char**\nyou -> %s != env -> %s\n",
		  tab[i], environ[i]);
	  return (1);
	}
      i++;
    }
  printf("Test de FIND_IN_ENV :\n");
  while (tmp && strcmp(tmp->name, "PWD") != 0)
    tmp = tmp->next;
  if (tmp && tmp->value && strcmp(tmp->value, find_in_env("PWD", e)) != 0)
    return (1);
  printf("Test recup:\n");
  i = 0;
  while (e)
    {
      str = malloc((strlen(e->name) + strlen(e->value) + 2) * sizeof(*str));
      sprintf(str, "%s=%s", e->name, e->value);
      if (strcmp(str, environ[i]) != 0)
	{
	  printf("Error : you -> %s, env -> %s", str, environ[i]);
	  return (1);
	}
      e = e->next;
      i++;
    }
  return (0);
}
