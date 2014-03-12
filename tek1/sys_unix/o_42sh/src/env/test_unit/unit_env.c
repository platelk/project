/*
** unit_env.c for ls in /home/vink/projet/sys_unix/42sh/src/env/test_unit
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 12:21:22 2012 kevin platel
** Last update Mon Apr 16 09:57:46 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "env.h"
#include "my.h"
#include "utils.h"

int	main()
{
  t_env	*e;
  char	*str;
  int	i;

  e = creat_env();
  i = 0;
  while (environ[i])
    {
      str = malloc((strlen(e->name) + strlen(e->value) + 2) * sizeof(*str));
      sprintf(str, "%s=%s", e->name, e->value);
      printf("\n->%s\n=>%s\n", environ[i], str);
      if (strcmp(environ[i], str) != 0)
	return (1);
      if (str)
	free(str);
      e = e->next;
      i++;
    }
  return (0);
}
