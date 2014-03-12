/*
** echo.c for echo in /home/vink/projet/sys_unix/42sh/src/builtin/src/echo
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Apr 16 11:20:45 2012 kevin platel
** Last update Tue May 15 18:32:34 2012 kevin platel
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
      write(1, av[i], my_strlen(av[i]));
      if (av[i + 1] != NULL)
	write(1, " ", 1);
      i++;
    }
  write(1, &end, 1);
  return (0);
}
