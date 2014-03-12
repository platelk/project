/*
** echo.c for echo in /home/vink/projet/sys_unix/42sh/src/builtin/src/echo
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Apr 16 11:20:45 2012 kevin platel
** Last update Tue Apr 24 11:17:30 2012 zoe phalippou
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtin.h"
#include "my.h"

char	*search_in_tab(char *str, char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (strcmp(str, tab[i]) == 0)
	return (tab[i]);
      i++;
    }
  return (NULL);
}

int	echo(t_global *global, char **av)
{
  int	i;
  char  end;

  i = 1;
  if (!av)
    return (0);
  global->env = global->env;
  my_strcmp(av[i], "-n") == 0 ? (end = '\0') : (end = '\n');
  end == '\0' ? (i = 2) : (i = 1);
  while (av[i])
    {
      printf("%s", av[i]);
      if (av[i + 1] != NULL)
	printf(" ");
      i++;
    }
  printf("%c", end);
  return (0);
}
