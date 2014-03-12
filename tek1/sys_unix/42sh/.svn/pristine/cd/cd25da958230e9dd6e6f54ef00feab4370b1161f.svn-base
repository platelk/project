/*
** is_builtin.c for is_builtin in /home/vink/projet/sys_unix/42sh/src/builtin/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 12:44:48 2012 kevin platel
** Last update Sat May 19 14:31:00 2012 kevin platel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include	"my.h"

int	is_builtin(char *str)
{
  int	i;
  char	*tab[10];

  i = 0;
  tab[0] = "cd";
  tab[1] = "setenv";
  tab[2] = "unsetenv";
  tab[3] = "history";
  tab[4] = "echo";
  tab[5] = "exit";
  tab[6] = "alias";
  tab[7] = "unalias";
  tab[8] = "chdir";
  tab[9] = NULL;
  if (str == NULL)
    return (-1);
  while (tab[i])
    {
      if (my_strcmp(tab[i], str) == 0)
	return (i);
      i++;
    }
  return (-1);
}
